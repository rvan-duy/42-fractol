/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:43:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/14 17:04:36 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

// saved mandelbrots
// max 80 min 50, k * 255, k * 255, 0 with and without cos
// max 130 min 50, k * 255, k * 255, 0 without cos
// max 200 min 150, k * 255, k * 255, 0 without cos << any color
				// k = (cos(k * 3.14159 + 3.14159) + 1) / 2;

void	apply_color_theme(t_var v, t_math_vars m)
{
	int		rgb;
	double	k;

	if (m.ite < v.fractal.max_ite)
	{
		k = (double)(m.ite - v.fractal.min_ite)
			/ (v.fractal.max_ite - v.fractal.min_ite);
		rgb = create_rgb(k * 255, k * 255, 0);
		putpixel(&v, m.col, m.row, rgb);
	}
	else
		putpixel(&v, m.col, m.row, 0x000000);
}

static int	mandelbrot_math(t_var v, t_math_vars m)
{
	int		ite;
	double	x;
	double	y;
	double	tmp;

	ite = 0;
	x = 0;
	y = 0;
	tmp = 0;
	while (x * x + y * y <= 4 && ite < v.fractal.max_ite)
	{
		tmp = x * x - y * y + m.comp_real;
		y = 2 * x * y + m.comp_imag;
		x = tmp;
		if (x * x + y * y > 4)
			return (ite);
		ite++;
	}
	return (ite);
}

void	mandelbrot(t_var *v)
{
	t_math_vars	m;

	m.row = 0;
	while (m.row < WINDOW_HEIGHT)
	{
		m.col = 0;
		while (m.col < WINDOW_WIDTH)
		{
			m.comp_real = (((double)m.col / WINDOW_WIDTH) - 0.5)
				/ v->fractal.zoom * 3.0 - 0.7 + v->fractal.x_offset;
			m.comp_imag = (((double)m.row / WINDOW_HEIGHT) - 0.5)
				/ v->fractal.zoom * 3.0 + v->fractal.y_offset;
			m.ite = mandelbrot_math(*v, m);
			apply_color_theme(*v, m);
			m.col++;
		}
		m.row++;
	}
}
