/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/16 15:00:16 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/07 18:14:04 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_fractal_type(t_fractal *fractal, char *arguments)
{
	if (!ft_strncmp(arguments, "mandelbrot", 11))
		fractal->fractal_set = MANDELBROT;
	else if (!ft_strncmp(arguments, "julia", 6))
		fractal->fractal_set = JULIA;
	else if (!ft_strncmp(arguments, "burning_ship", 13))
		fractal->fractal_set = BURNING_SHIP;
	else
	{
		printf("Usage:\n./fractol <mandelbrot | julia | burning_ship> [theme]\n");
		exit(EXIT_SUCCESS);
	}
}

void	parse_fractal_color_theme(t_fractal *fractal, char *argument)
{
	if (argument == NULL)
		fractal->fractal_color_theme = GREEN;
	else if (!ft_strncmp(argument, "white", 6))
		fractal->fractal_color_theme = WHITE;
	else if (!ft_strncmp(argument, "red", 4))
		fractal->fractal_color_theme = RED;
	else if (!ft_strncmp(argument, "green", 6))
		fractal->fractal_color_theme = GREEN;
	else if (!ft_strncmp(argument, "blue", 5))
		fractal->fractal_color_theme = BLUE;
	else if (!ft_strncmp(argument, "yellow", 7))
		fractal->fractal_color_theme = YELLOW;
	else if (!ft_strncmp(argument, "teal", 5))
		fractal->fractal_color_theme = TEAL;
	else if (!ft_strncmp(argument, "purple", 7))
		fractal->fractal_color_theme = PURPLE;
	else
		fractal->fractal_color_theme = GREEN;
}

void	parse_fractal_extra(t_fractal *fractal, char **args, int argc)
{
	if (fractal->fractal_set == JULIA)
	{
		if (argc >= 4)
		{	
			fractal->extra_param_1 = ft_atod(args[0]);
			fractal->extra_param_2 = ft_atod(args[1]);
		}
		else
		{
			printf("Usage:\n./fractol julia <re> <im> [theme]\n");
			exit(EXIT_SUCCESS);
		}
	}
}
