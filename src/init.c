/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 18:28:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/16 15:43:37 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_var(t_fractal *fractal)
{
	fractal->fractal_arr[0] = (void *)mandelbrot;
	fractal->fractal_arr[1] = NULL;
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

static void	set_rgb(t_fractal *fractal, int red, int green, int blue)
{
	fractal->red = red;
	fractal->green = green;
	fractal->blue = blue;
}

static void	set_iterations(t_fractal *fractal, int min_ite, int max_ite)
{
	fractal->min_ite = min_ite;
	fractal->max_ite = max_ite;
}

void	init_visuals(t_fractal *fractal)
{
	if (fractal->fractal_color_theme == RED)
	{
		set_rgb(fractal, 255, 0, 0);
		set_iterations(fractal, 0, 200);
	}
	else if (fractal->fractal_color_theme == GREEN)
	{
		set_rgb(fractal, 0, 255, 0);
		set_iterations(fractal, 0, 200);
	}
	else if (fractal->fractal_color_theme == BLUE)
	{
		set_rgb(fractal, 0, 0, 255);
		set_iterations(fractal, 0, 200);
	}
}
