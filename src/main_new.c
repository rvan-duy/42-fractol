/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 16:20:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/12 21:22:45 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "hooks.h"
#include "libft.h"
#include "fractals.h"
#include "mlx.h"
#include <stdio.h>

static void	read_arguments(t_fractal *fractal_info, char **arguments)
{
	if (!ft_strncmp(arguments[1], "mandelbrot", 11))
	{
		fractal_info->fractal_set = MANDELBROT;
	}
	else if (!ft_strncmp(arguments[1], "julia", 6))
	{
		fractal_info->fractal_set = JULIA;
	}
	else
	{
		printf("Usage:\n%s <mandelbrot | julia>\n", arguments[0]);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	t_var	*v;

	v = (t_var *) malloc(sizeof(t_var));
	if (v == NULL)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		read_arguments(&v->fractal, argv);
		printf("1 %p\n", v->win);
		init(v);
		printf("1 %p\n", v->win);
		int i = mlx_expose_hook(v->win, main_hook, v);
		printf("2 %i\n", i);
		mlx_hook(v->win, KEY_PRESS, 1L << 0, key_hook, v);
		printf("3\n");
		mlx_loop(v->win);
		printf("4\n");
	}
	else
		printf("Usage:\n%s <mandelbrot | julia>\n", argv[0]);
	return (EXIT_SUCCESS);
}
