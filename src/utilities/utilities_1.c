/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:52:44 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/12 12:27:47 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "fractol.h"
#include "mlx.h"
#include <math.h>

void	putpixel(t_image image, int x, int y, int color)
{
	const char	*dst = image.addr + (y * image.line_length
		+ x * (image.bits_per_pixel / 8));

	*(unsigned int *)dst = color;
}

static bool	is_on_screen(int point, int max)
{
	if (point >= 0 && point <= max)
		return (true);
	return (false);
}

#include <stdio.h>

static void	zoom_screen(t_mlx *mlx, int x_mouse_pos, int y_mouse_pos)
{
	mlx->zoom *= 2;
	mlx->thingy += 5.0;
	mlx->thingy_2 *= 1.5;
	(void)x_mouse_pos;
	(void)y_mouse_pos;
	// mlx->zoom_x += (double) x_mouse_pos / 10000;
	// mlx->zoom_y += (double) y_mouse_pos / 10000;
	printf("zoom: %f\nthingy: %f\nthingy_2:%f\n", mlx->zoom, mlx->thingy, mlx->thingy_2);
}

bool	zoom_if_possible(t_mlx *mlx)
{
	int	x_mouse_pos;
	int	y_mouse_pos;

	// mlx->zoom_x = 1.0;
	// mlx->zoom_y = 1.0;
	mlx_mouse_get_pos(mlx->mlx, mlx->win, &x_mouse_pos, &y_mouse_pos);
	if (is_on_screen(x_mouse_pos, WINDOW_WIDTH) == false
		|| is_on_screen(y_mouse_pos, WINDOW_HEIGHT) == false)
		return (false);
	else
		zoom_screen(mlx, x_mouse_pos, y_mouse_pos);
	return (true);
}
