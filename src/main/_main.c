/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _main.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/13 16:45:08 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/13 17:41:53 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "libft.h"
#include "mlx.h"
#include "hooks.h"
#include <stdio.h>

static void	parse_arguments(t_fractal *fractal, char **arguments)
{
	if (!ft_strncmp(arguments[1], "mandelbrot", 11))
		fractal->fractal_set = MANDELBROT;
	else if (!ft_strncmp(arguments[1], "julia", 6))
		fractal->fractal_set = JULIA;
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
		parse_arguments(&v->fractal, argv);
		init_var(v);
		init_mlx(v);
		mlx_expose_hook(v->win, main_hook, v);
		mlx_hook(v->win, KEY_PRESS, 1L << 0, key_hook, v);
		mlx_loop(v->mlx);
	}
	ft_free((void **) &v);
	return (EXIT_SUCCESS);
}
