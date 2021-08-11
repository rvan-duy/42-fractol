/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 18:28:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/11 16:59:02 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "structs.h"
#include "mlx.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->zoom = 1.0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fractol");
}
