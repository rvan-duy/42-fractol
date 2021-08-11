/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 22:47:57 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/11 23:18:35 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "fractol.h"
#include "fractals.h"
#include "mlx.h"
#include <stdio.h>

int	main_hook(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, \
		&mlx->img.line_length, &mlx->img.endian);
	draw_fractal(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_LINUX || keycode == ESC_MACOS)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 65362 || 126)
	{
		int	x, y;
		mlx->zoom += 0.5;
		mlx_mouse_get_pos(mlx->mlx, mlx->win, &x, &y);
		printf("%d %d\n", x, y);
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_clear_window(mlx->mlx, mlx->win);
		main_hook(mlx);
	}
	return (0);
}
