/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 18:28:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/07 15:06:43 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_var(t_fractal *fractal)
{
	fractal->fractal_arr[0] = &mandelbrot;
	fractal->fractal_arr[1] = &julia;
	fractal->fractal_arr[2] = &burning_ship;
	fractal->zoom = 1.0;
	fractal->speed = 1.0;
	fractal->x_offset = 0.0;
	fractal->y_offset = 0.0;
}

void	init_mlx(t_var *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
}
