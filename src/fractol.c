/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/13 16:45:08 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/29 17:13:05 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_var	*v;

	v = malloc(sizeof(t_var));
	if (v == NULL)
		return (EXIT_FAILURE);
	if (argc >= 2 && argc <= 6)
	{
		parse_fractal_type(&v->fractal, argv[1]);
		if (v->fractal.fractal_set == JULIA)
			parse_fractal_color_theme(&v->fractal, argv[4]);
		else
			parse_fractal_color_theme(&v->fractal, argv[2]);
		parse_fractal_extra(&v->fractal, argv + 2, argc);
		init_var(&v->fractal);
		init_mlx(v);
		set_iterations(&v->fractal);
		mlx_hook(v->win, KEY_PRESS, 1L << 0, key_hook, v);
		mlx_hook(v->win, BUTTON_PRESS, 1L << 2, mouse_scroll_start, v);
		mlx_loop_hook(v->mlx, main_hook, v);
		mlx_loop(v->mlx);
	}
	else
		printf("Usage:\n./fractol <mandelbrot | julia | burning_ship> [theme]\n");
	ft_free((void **) &v);
	return (EXIT_SUCCESS);
}
