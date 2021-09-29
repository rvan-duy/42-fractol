/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 22:47:57 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/29 17:10:39 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	main_hook(t_var *v)
{
	if (v->needs_draw == true && v->is_drawing == false)
	{
		v->is_drawing = true;
		v->needs_draw = false;
		set_visuals(&v->fractal);
		set_simple_color(&v->fractal);
		draw_fractal(v);
		mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
		ft_putendl_fd("[\x1b[92mfractol\x1b[0m] Image drawn", 2);
		v->is_drawing = false;
	}
	return (0);
}

int	key_hook(int keycode, t_var *v)
{
	if (keycode == KEY_ESC)
		close_window(v);
	if (keycode >= 123 && keycode <= 1236)
	{
		if (keycode == KEY_LEFT)
			v->fractal.x_offset -= (0.05 / v->fractal.speed);
		else if (keycode == KEY_UP)
			v->fractal.y_offset -= (0.05 / v->fractal.speed);
		else if (keycode == KEY_RIGHT)
			v->fractal.x_offset += (0.05 / v->fractal.speed);
		else if (keycode == KEY_DOWN)
			v->fractal.y_offset += (0.05 / v->fractal.speed);
		refresh_image(v);
	}
	if (keycode == KEY_M)
		start_config(v);
	return (0);
}

int	mouse_scroll_start(int scroll, int x, int y, t_var *v)
{
	(void)x;
	(void)y;
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
