/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_fractal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 23:12:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/12 19:29:06 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include <stdio.h>

void	draw_fractal(t_var *v)
{
	printf("draw_fractal\n");
	if (v->fractal.fractal_set == MANDELBROT)
		mandelbrot(v);
}
