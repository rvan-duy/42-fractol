/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:43:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/29 14:44:22 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

static int	mandelbrot_math(t_var v, double comp_re, double comp_im)
{
	int		iteration;
	double	z_re;
	double	z_im;
	double	tmp;

	iteration = 0;
	z_re = 0;
	z_im = 0;
	tmp = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iteration < v.fractal.max_ite)
	{
		tmp = z_re * z_re - z_im * z_im + comp_re;
		z_im = 2 * z_re * z_im + comp_im;
		z_re = tmp;
		if (z_re * z_re + z_im * z_im > 4)
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
