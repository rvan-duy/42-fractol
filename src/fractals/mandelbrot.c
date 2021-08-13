/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:43:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/12 21:17:35 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

// void	mandelbrot(t_mlx *mlx)
// {
// 	double x, y, xx, cx, cy;
// 	int iteration, width, height;
// 	int max_iterations = 50;
// 	// double zoom = 1.5;
// 	size_t black = 0, white = 0;

// 	width = 0;
// 	while (width < WINDOW_WIDTH)
// 	{
// 		// printf("%d\n", width);
// 		height = 0;
// 		while (height < WINDOW_HEIGHT)
// 		{
// 			cx = (((double)width / WINDOW_WIDTH) - 0.5) / mlx->zoom * 3.0 - 0.7;
// 			cy = (((double)height / WINDOW_HEIGHT) - 0.5) / mlx->zoom * 3.0;
// 			x = 0.0;
// 			y = 0.0;
// 			iteration = 0;
// 			while (iteration < max_iterations)
// 			{
// 				xx = x * x - y * y + cx;
// 				y = 2.0 * x * y + cy;
// 				x = xx;
// 				if (x * x + y * y > 100.0)
// 					iteration = 999999;
// 				iteration++;
// 			}
// 			// printf("cx:%f cy%f\niteration:%d\n", cx, cy, iteration);
// 			// printf("width: %d height: %d\n", width, height);
// 			// if (height == 100)
// 				// exit (1);
// 			// printf("x: %f y: %f\n", x, y);
// 			if (iteration < 999999)
// 			{
// 				black++;
// 				putpixel(mlx->img, width, height, 0x000000);
// 			}
// 			else
// 			{
// 				white++;
// 				putpixel(mlx->img, width, height, 0xFFFFFF);
// 			}
// 			// printf("height: %d\n", height);
// 			height++;
// 		}
// 		width++;
// 	}
// 	printf("done. %ld %ld\n", white, black);
// }

// void	mandelbrot(t_mlx *mlx)
// {
// 	int		row;
// 	int		col;
// 	int		iteration;
// 	int 	max_iterations;
// 	double	x;
// 	double	y;
// 	double	min = -1.0;
// 	double 	max = 1.0;

// 	col = 0;
// 	max_iterations = 200;
// 	while (col < WINDOW_WIDTH)
// 	{
// 		row = 0;
// 		while (row < WINDOW_HEIGHT)
// 		{
// 			x = map(col, WINDOW_HEIGHT, min, max);
// 			y = map(row, WINDOW_WIDTH, min, max);
// 			double original_x = x;
// 			double original_y = y;
// 			iteration = 0;
// 			while (iteration < max_iterations)
// 			{
// 				double xx = x * x - y * y;
// 				double yy = 2 * x * y;
// 				x = xx + original_x;
// 				y = yy + original_y;
// 				if (x * x + y * y > 4)
// 					break ;
// 				iteration++;
// 			}
// 			if (iteration == max_iterations)
// 				putpixel(mlx->img, col, row, 0x000000);
// 			else
// 				putpixel(mlx->img, col, row, 0xFFFFFF);
// 			row++;
// 		}
// 		col++;
// 	}
// }

// saved mandelbrots
// max 80 min 50, k * 255, k * 255, 0 with and without cos
// max 130 min 50, k * 255, k * 255, 0 without cos
// max 200 min 150, k * 255, k * 255, 0 without cos << any color

void	mandelbrot(t_var *v)
{
	int row = 0;
	int col = 0;
	int max = 130;
	int min = 50;
	double k;

	printf("hello?\n");
	while (row < WINDOW_HEIGHT)
	{
		col = 0;
		while (col < WINDOW_WIDTH)
		{
			// double c_re = (((double)col / WINDOW_WIDTH) - 0.5) / mlx->zoom * 3.0 - 0.7; // add stuf behind this to decide on zoom
			double c_re = (((double)col / WINDOW_WIDTH) - 0.5) / v->fractal.zoom * 3.0 - 0.7 + v->fractal.x_pos; // add stuf behind this to decide on zoom
			// double c_im = (((double)row / WINDOW_HEIGHT) - 0.5) / mlx->zoom * 3.0;
			double c_im = (((double)row / WINDOW_HEIGHT) - 0.5) / v->fractal.zoom * 3.0 + v->fractal.y_pos;
			double x = 0, y = 0;
			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < max)
			{
				double x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
				if (x*x+y*y > 4)
					break;
				iteration++;
			}
			if (iteration < max)
			{
				k = (double) (iteration - min) / (max - min);
				// k = (cos(k * 3.14159 + 3.14159) + 1) / 2;
				// printf("%f ", k);
				int rgb = create_rgb(k * 255, 0, k * 255);
				putpixel(*v->img_vars, col, row, rgb);
				// putpixel(mlx->img, col, row, colors[iteration]);
				// my_mlx_pixel_put(data, col, row, 0x000000 + (iteration * 2));
			}
			else
				putpixel(*v->img_vars, col, row, 0x000000);
			printf("col:%d\n", col);
			col++;
		}
			printf("row:%d\n", row);
		row++;
	}
	printf("done\n");
}
