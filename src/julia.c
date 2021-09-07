/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 14:42:17 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/07 15:39:55 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

static int	julia_math(t_var v, double comp_re, double comp_im)
{
	int		iteration;
	double	z_re;
	double	z_im;
	double	tmp;

	iteration = 0;
	z_re = comp_re;
	z_im = comp_im;
	tmp = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iteration < v.fractal.max_ite)
	{
		tmp = z_re * z_re - z_im * z_im + v.fractal.extra_param_1;
		z_im = 2 * z_re * z_im + v.fractal.extra_param_2;
		z_re = tmp;
		if (z_re * z_re + z_im * z_im > 4)
			return (iteration);
		iteration++;
	}
	return (iteration);
}

void	julia(t_var *v)
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
			iteration = julia_math(*v, real_component, imag_component);
			apply_color_theme(*v, row, col, iteration);
			col++;
		}
		row++;
	}
	ft_putendl_fd("[\x1b[92mfractol\x1b[0m] Image drawn", 2);
}
