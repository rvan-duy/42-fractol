/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 22:47:57 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/13 18:24:13 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "fractol.h"
#include "fractals.h"
#include "mlx.h"
#include "utilities.h"
#include "libft.h"
#include <stdio.h>

int	main_hook(t_var *v)
{
	v->img = mlx_new_image(v->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	v->addr = mlx_get_data_addr(v->img, &v->addr_vars.bits_pp,
			&v->addr_vars.line_len, &v->addr_vars.endian);
	draw_fractal(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_var *v)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC_LINUX || keycode == ESC_MACOS)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		ft_free((void **)&v);
		exit(EXIT_SUCCESS);
	}
	if (keycode == Z_LINUX)
	{
		v->fractal.zoom *= 2;
		v->fractal.speed *= 1.5;
		refresh_window(v);
	}
	if (keycode >= 65361 && keycode <= 65364)
	{
		if (keycode == 65361)
			v->fractal.x_offset -= (0.05 / v->fractal.speed);
		else if (keycode == 65362)
			v->fractal.y_offset -= (0.05 / v->fractal.speed);
		else if (keycode == 65363)
			v->fractal.x_offset += (0.05 / v->fractal.speed);
		else if (keycode == 65364)
			v->fractal.y_offset += (0.05 / v->fractal.speed);
		refresh_window(v);
	}
	if (keycode == 96)
	{
		char *line;
		printf("Starting configuration menu:\n>\n");
		get_next_line(STDIN_FILENO, &line);
		printf("[%s]\n", line);
	}
	return (0);
}


//  mouse position out of bounds then do not take it into accout
//	if it is in the screen add it to the zooming formula
