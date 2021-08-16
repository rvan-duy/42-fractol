/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 23:12:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/16 14:09:26 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_fractal(t_var *v)
{
	v->fractal.fractal_arr[v->fractal.fractal_set](v);
}
