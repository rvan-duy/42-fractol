/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 22:47:57 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/16 17:16:23 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	main_hook(t_var *v)
{
	v->img = mlx_new_image(v->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	v->addr = mlx_get_data_addr(v->img, &v->addr_vars.bits_pp,
			&v->addr_vars.line_len, &v->addr_vars.endian);
	init_visuals(&v->fractal);
	draw_fractal(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
}

static void	config(t_var *v)
{
	int		ret;
	char	*line;

	ret = 1;
	ft_putendl_fd("config console:", 2);
	while (ret > 0)
	{
		ft_putstr_fd("> ", 2);
		get_next_line(STDIN_FILENO, &line);
		if (!ft_strncmp(line, "end", 3))
			ret = 0;
		else if (!ft_strncmp(line, "fractal_color_theme:", 20))
			parse_fractal_color_theme(&v->fractal, line + 20);
		else if (!ft_strncmp(line, "max_iterations:", 15))
			v->fractal.max_ite = ft_atoi(line + 15);
		ft_putnbr_fd(v->fractal.max_ite, 2);
		ft_free((void **)&line);
	}
	ft_putendl_fd("Refreshing window...", 2);
	refresh_window(v);
}

int	key_hook(int keycode, t_var *v)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC_LINUX || keycode == ESC_MACOS)
		close_window(v);
	if (keycode == Z_LINUX)
	{
		v->fractal.zoom *= 2;
		v->fractal.speed *= 1.5;
		refresh_window(v);
	}
	if (keycode >= 65361 && keycode <= 65364)
	{
		if (keycode == 65361)
			v->fractal.x_offset -= (0.05 / v->fractal.speed);
		else if (keycode == 65362)
			v->fractal.y_offset -= (0.05 / v->fractal.speed);
		else if (keycode == 65363)
			v->fractal.x_offset += (0.05 / v->fractal.speed);
		else if (keycode == 65364)
			v->fractal.y_offset += (0.05 / v->fractal.speed);
		refresh_window(v);
	}
	if (keycode == 60)
		config(v);
	return (0);
}
