/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 22:47:57 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/09 10:21:34 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	if (keycode == 65307 || keycode == 53)
	{
		printf("Escape pressed (keycode: %d), closing image and window..\n", keycode);
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
