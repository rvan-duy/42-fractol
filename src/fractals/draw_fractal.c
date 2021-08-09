/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_fractal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 23:12:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/08 23:18:51 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	draw_fractal(t_mlx *mlx)
{
	if (mlx->fractol_info.fractol_set == MANDELBROT)
		mandelbrot(mlx);
}
