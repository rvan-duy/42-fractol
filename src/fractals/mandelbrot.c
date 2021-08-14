/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:43:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/14 21:48:33 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

// saved mandelbrots
// max 80 min 50, k * 255, k * 255, 0 with and without cos
// other color inputs
// max 130 min 50, k * 255, k * 255, 0 without cos
// max 200 min 150, k * 255, k * 255, 0 without cos << any color
				// k = (cos(k * 3.14159 + 3.14159) + 1) / 2;
// max 300 min 0, k * 255, k * 255, 0

// void	apply_color_theme(t_var v, int row, int col, int iteration)
// {
// 	int		rgb;
// 	double	k;

// 	if (iteration <= v.fractal.min_ite)
// 		putpixel(&v, col, row, 0x000000);
// 	else if (iteration < v.fractal.max_ite)
// 	{
// 		k = (double)(iteration - v.fractal.min_ite)
// 			/ (v.fractal.max_ite - v.fractal.min_ite);
// 		rgb = create_rgb(k * 255, k * 255, 0);
// 		putpixel(&v, col, row, rgb);
// 	}
// 	else
// 		putpixel(&v, col, row, 0x000000);
// }

void	apply_color_theme(t_var v, int row, int col, int iteration)
{
	int		rgb;
	double	k;

	if (iteration < v.fractal.max_ite)
	{
		k = (double)(iteration - v.fractal.min_ite)
			/ (v.fractal.max_ite - v.fractal.min_ite);
		rgb = create_rgb(k * 255, 0, 0);
		putpixel(&v, col, row, rgb);
	}
	else
		putpixel(&v, col, row, 0x000000);
}

static int	mandelbrot_math(t_var v, double comp_real, double comp_imag)
{
	int		iteration;
	double	x;
	double	y;
	double	tmp;

	iteration = 0;
	x = 0;
	y = 0;
	tmp = 0;
	while (x * x + y * y <= 4 && iteration < v.fractal.max_ite)
	{
		tmp = x * x - y * y + comp_real;
		y = 2 * x * y + comp_imag;
		x = tmp;
		if (x * x + y * y > 4)
			return (iteration);
		iteration++;
	}
	return (iteration);
}

void	mandelbrot(t_var *v)
{
	int			row;
	int			col;
	double		real_component;
	double		imag_component;
	int			iteration;

	row = 0;
	while (row < WINDOW_HEIGHT)
	{
		col = 0;
		while (col < WINDOW_WIDTH)
		{
			real_component = (((double)col / WINDOW_WIDTH) - 0.5)
				/ v->fractal.zoom * 3.0 - 0.7 + v->fractal.x_offset;
			imag_component = (((double)row / WINDOW_HEIGHT) - 0.5)
				/ v->fractal.zoom * 3.0 + v->fractal.y_offset;
			iteration = mandelbrot_math(*v, real_component, imag_component);
			apply_color_theme(*v, row, col, iteration);
			col++;
		}
		row++;
	}
}
