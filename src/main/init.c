/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 18:28:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/13 18:59:51 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "fractol.h"
#include "fractals.h"
#include "mlx.h"

void	init_var(t_var *v)
{
	v->fractal.fractal_arr[0] = (void *)mandelbrot;
	v->fractal.fractal_arr[1] = NULL;
	v->fractal.zoom = 1.0;
	v->fractal.speed = 1.0;
	v->fractal.x_offset = 0.0;
	v->fractal.y_offset = 0.0;
	v->fractal.min_iterations = 50;
	v->fractal.max_iterations = 130;
}

void	init_mlx(t_var *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
}
