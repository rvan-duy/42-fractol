/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/16 15:00:16 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/26 13:45:59 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_fractal_type(t_fractal *fractal, char *argument)
{
	if (!ft_strncmp(argument, "mandelbrot", 11))
		fractal->fractal_set = MANDELBROT;
	else if (!ft_strncmp(argument, "julia", 6))
		fractal->fractal_set = JULIA;
	else if (!ft_strncmp(argument, "burning_ship", 13))
		fractal->fractal_set = BURNING_SHIP;
	else
	{
		printf("Usage:\n./fractol <mandelbrot | julia> [color_theme]\n");
		exit(EXIT_SUCCESS);
	}
}

void	parse_fractal_color_theme(t_fractal *t_fractal, char *argument)
{
	if (argument == NULL)
		t_fractal->fractal_color_theme = FIRE;
	else if (!ft_strncmp(argument, "white", 6))
		t_fractal->fractal_color_theme = WHITE;
	else if (!ft_strncmp(argument, "red", 4))
		t_fractal->fractal_color_theme = RED;
	else if (!ft_strncmp(argument, "green", 6))
		t_fractal->fractal_color_theme = GREEN;
	else if (!ft_strncmp(argument, "blue", 5))
		t_fractal->fractal_color_theme = BLUE;
	else if (!ft_strncmp(argument, "yellow", 7))
		t_fractal->fractal_color_theme = YELLOW;
	else if (!ft_strncmp(argument, "teal", 5))
		t_fractal->fractal_color_theme = TEAL;
	else if (!ft_strncmp(argument, "purple", 7))
		t_fractal->fractal_color_theme = PURPLE;
	else
		t_fractal->fractal_color_theme = FIRE;
}
