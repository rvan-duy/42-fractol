/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_fractal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 23:12:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/13 18:34:47 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	draw_fractal(t_var *v)
{
	v->fractal.fractal_arr[v->fractal.fractal_set](v);
}
