/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 22:47:57 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/12 12:26:28 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "fractol.h"
#include "fractals.h"
#include "mlx.h"
#include "utilities.h"
#include "libft.h"
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
	printf("keycode: %d\n", keycode);
	if (keycode == ESC_LINUX || keycode == ESC_MACOS)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		ft_free((void **)&mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 122 || keycode == 126)
	{
		int	x, y;
		mlx_mouse_get_pos(mlx->mlx, mlx->win, &x, &y);
		if (zoom_if_possible(mlx))
		{
			mlx_destroy_image(mlx->mlx, mlx->img.img);
			mlx_clear_window(mlx->mlx, mlx->win);
			main_hook(mlx);
		}
	}
	if (keycode >= 65361 && keycode <= 65364)
	{
		if (keycode == 65361)
			mlx->zoom_x -= (0.05 / mlx->thingy_2);
		else if (keycode == 65362)
			mlx->zoom_y -= (0.05 / mlx->thingy_2);
		else if (keycode == 65363)
			mlx->zoom_x += (0.05 / mlx->thingy_2);
		else if (keycode == 65364)
			mlx->zoom_y += (0.05 / mlx->thingy_2);
		printf("thing; %f x;%f y;%f\n", mlx->thingy_2, mlx->zoom_x, mlx->zoom_y);
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_clear_window(mlx->mlx, mlx->win);
		main_hook(mlx);
	}
	return (0);
}


//  mouse position out of bounds then do not take it into accout
//	if it is in the screen add it to the zooming formula
