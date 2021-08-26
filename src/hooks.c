/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 22:47:57 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/24 14:29:15 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

// This could be swapped around but still need to check..

int	main_hook(t_var *v)
{
	v->img = mlx_new_image(v->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	v->addr = mlx_get_data_addr(v->img, &v->addr_vars.bits_pp,
			&v->addr_vars.line_len, &v->addr_vars.endian);
	set_visuals(&v->fractal);
	// set_iterations(&v->fractal);
	set_simple_color(&v->fractal);
	draw_fractal(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_var *v)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY_LINUX || keycode == ESC_KEY_MACOS)
		close_window(v);
	if (keycode >= 123 && keycode <= 1236)
	{
		if (keycode == 123)
			v->fractal.x_offset -= (0.05 / v->fractal.speed);
		else if (keycode == 126)
			v->fractal.y_offset -= (0.05 / v->fractal.speed);
		else if (keycode == 124)
			v->fractal.x_offset += (0.05 / v->fractal.speed);
		else if (keycode == 125)
			v->fractal.y_offset += (0.05 / v->fractal.speed);
		refresh_image(v);
	}
	if (keycode == M_KEY_MACOS)
		start_config(v);
	return (0);
}

int	mouse_scroll_start(int scroll, int x, int y, t_var *v)
{
	(void)x;
	(void)y;
	printf("scroll: %d\n", scroll);
	if (scroll == SCROLL_UP)
	{
		v->fractal.zoom *= 2;
		v->fractal.speed *= 1.5;
		refresh_image(v);
	}
	else if (scroll == SCROLL_DOWN)
	{
		v->fractal.zoom /= 2;
		v->fractal.speed /= 1.5;
		refresh_image(v);
	}
	return (0);
}
