/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/16 23:30:34 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/28 13:51:46 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

static void	set_rgb(t_fractal *fractal, int red, int green, int blue)
{
	fractal->red = red;
	fractal->green = green;
	fractal->blue = blue;
}

void	set_visuals(t_fractal *fractal)
{
	if (fractal->fractal_color_theme == WHITE)
		set_rgb(fractal, 255, 255, 255);
	else if (fractal->fractal_color_theme == RED)
		set_rgb(fractal, 255, 0, 0);
	else if (fractal->fractal_color_theme == GREEN)
		set_rgb(fractal, 0, 255, 0);
	else if (fractal->fractal_color_theme == BLUE)
		set_rgb(fractal, 0, 0, 255);
	else if (fractal->fractal_color_theme == YELLOW)
		set_rgb(fractal, 255, 255, 0);
	else if (fractal->fractal_color_theme == TEAL)
		set_rgb(fractal, 0, 255, 255);
	else if (fractal->fractal_color_theme == PURPLE)
		set_rgb(fractal, 255, 0, 255);
}

static void	set_both_ite(t_fractal *fractal, int min_ite, int max_ite)
{
	fractal->min_ite = min_ite;
	fractal->max_ite = max_ite;
}

void	set_iterations(t_fractal *fractal)
{
	if (fractal->fractal_color_theme >= WHITE
		&& fractal->fractal_color_theme <= PURPLE)
		set_both_ite(fractal, 0, 40);
}

void	set_simple_color(t_fractal *fractal)
{
	if (fractal->fractal_color_theme >= WHITE
		&& fractal->fractal_color_theme <= PURPLE)
		fractal->simple_color = true;
}
