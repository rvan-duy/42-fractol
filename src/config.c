/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/16 21:38:32 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/16 21:52:25 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static int	execute_line(char *line, t_var *v)
{
	if (!ft_strncmp(line, "refresh", 7))
		return (0);
	else if (!ft_strncmp(line, "fractal_color_theme:", 20))
		parse_fractal_color_theme(&v->fractal, line + 20);
	else if (!ft_strncmp(line, "max_iterations:", 15))
		v->fractal.max_ite = ft_atoi(line + 15);
	else if (!ft_strncmp(line, "min_iterations:", 15))
		v->fractal.min_ite = ft_atoi(line + 15);
	return (1);
}

void	start_config(t_var *v)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		ft_putstr_fd("[\e[92mfractol\e[0m - \e[31mconfig\e[0m] > ", 2);
		get_next_line(STDIN_FILENO, &line);
		ret = execute_line(line, v);
		ft_free((void **)&line);
	}
	ft_putendl_fd("[\e[92mfractol\e[0m] Refreshing image...", 2);
	refresh_image(v);
}
