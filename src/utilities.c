/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:52:44 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/19 13:53:22 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	putpixel(t_var *v, int x, int y, int color)
{
	const char	*dst = v->addr + (y * v->addr_vars.line_len
		+ x * (v->addr_vars.bits_pp / 8));

	*(unsigned int *)dst = color;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	refresh_image(t_var *v)
{
	main_hook(v);
}

void	close_window(t_var *v)
{
	mlx_destroy_image(v->mlx, v->img);
	mlx_destroy_window(v->mlx, v->win);
	ft_free((void **)&v);
	exit(EXIT_SUCCESS);
}
