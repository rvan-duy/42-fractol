/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 16:20:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/08 22:03:32 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "init.h"
#include "libft.h"
#include "fractals.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

static void	draw_fractal(t_fractol fractol_info, t_mlx *mlx)
{
	if (fractol_info.fractol_set == MANDELBROT)
		mandelbrot(mlx);
}

static void	read_arguments(t_fractol *fractol_info, char **arguments)
{
	if (!ft_strncmp(arguments[1], "mandelbrot", 11))
	{
		fractol_info->fractol_set = MANDELBROT;
	}
	else if (!ft_strncmp(arguments[1], "julia", 6))
	{
		fractol_info->fractol_set = JULIA;
	}
	else
	{
		printf("Usage:\n%s <mandelbrot | julia>\n", arguments[0]);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	fractol_info;
	t_mlx		*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (1);
	if (argc > 1)
	{
		read_arguments(&fractol_info, argv);
		init_mlx(mlx);
		draw_fractal(fractol_info, mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
		mlx_loop(mlx->mlx);
	}
	else
		printf("Usage:\n%s <mandelbrot | julia>\n", argv[0]);
	return (0);
}
