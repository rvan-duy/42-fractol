/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:43:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/08 22:01:00 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>

void	mandelbrot(t_mlx *mlx)
{
	int row = 0;
	int col = 0;
	int max = 200;
	int colors[max];
	int i = 0;
	
	ft_bzero(colors, sizeof(colors));
	printf("hello %d %d\n", max, i);
	while (i < max && (400 - (10 * i) > -1))
	{
		// colors[i] = (i + 0x0000FF) / (8.0 * i);
		colors[i] = 400 - (10 * i);
		printf("%d\n", colors[i]);
		i++;
	}
	
	while (row < WINDOW_HEIGHT)
	{
		col = 0;
		while (col < WINDOW_WIDTH)
		{
			double c_re = (col - WINDOW_WIDTH/2.0)*4.0/WINDOW_WIDTH;
			double c_im = (row - WINDOW_HEIGHT/2.0)*4.0/WINDOW_WIDTH;
			double x = 0, y = 0;
			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < max)
			{
				double x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
				iteration++;
			}
			if (iteration < max)
			{
				putpixel(mlx->img, col, row, colors[iteration]);
				// my_mlx_pixel_put(data, col, row, 0x000000 + (iteration * 2));
			}
			else
				putpixel(mlx->img, col, row, 0x000000);
			col++;
		}
		row++;
	}
}
