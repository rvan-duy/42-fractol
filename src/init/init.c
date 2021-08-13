/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 18:28:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/12 21:05:58 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "fractol.h"
#include "mlx.h"

void	init(t_var *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	v->fractal.zoom = 1.0;
	v->fractal.zoom_modifier = 1.0;
	v->fractal.x_pos = 0.0;
	v->fractal.y_pos = 0.0;
}
