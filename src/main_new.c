/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 16:20:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/12 12:50:40 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "hooks.h"
#include "libft.h"
#include "fractals.h"
#include "mlx.h"
#include <stdio.h>

static void	read_arguments(t_mlx *mlx, char **arguments)
{
	if (!ft_strncmp(arguments[1], "mandelbrot", 11))
	{
		mlx->fractol_info.fractol_set = MANDELBROT;
	}
	else if (!ft_strncmp(arguments[1], "julia", 6))
	{
		mlx->fractol_info.fractol_set = JULIA;
	}
	else
	{
		printf("Usage:\n%s <mandelbrot | julia>\n", arguments[0]);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		read_arguments(mlx, argv);
		init_mlx(mlx);
		mlx_expose_hook(mlx->win, main_hook, mlx);
		mlx_hook(mlx->win, KEY_PRESS, 1L << 0, key_hook, mlx);
		// mlx_do_key_autorepeaton(mlx->mlx);
		mlx_loop(mlx->mlx);
	}
	else
		printf("Usage:\n%s <mandelbrot | julia>\n", argv[0]);
	return (EXIT_SUCCESS);
}
