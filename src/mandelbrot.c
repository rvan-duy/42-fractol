/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:43:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/16 21:24:43 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

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
	ft_putendl_fd("[\e[92mfractol\e[0m] Image drawn", 2);
}
