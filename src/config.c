/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/16 21:38:32 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/07 15:24:01 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static int	display_info(t_fractal *fractal)
{
	printf("max_iterations:%d\n", fractal->max_ite);
	printf("min_iterations:%d\n", fractal->min_ite);
	printf("speed:%.2f\n", fractal->speed);
	return (-2);
}

static int	execute_line(char *line, t_fractal *fractal)
{
	if (!ft_strncmp(line, "refresh", 7))
		return (0);
	else if (!ft_strncmp(line, "theme:", 6))
		parse_fractal_color_theme(fractal, line + 6);
	else if (!ft_strncmp(line, "max_iterations:", 15))
		fractal->max_ite = ft_atoi(line + 15);
	else if (!ft_strncmp(line, "min_iterations:", 15))
		fractal->min_ite = ft_atoi(line + 15);
	else if (!ft_strncmp(line, "display_info", 12))
		return (display_info(fractal));
	return (1);
}

void	start_config(t_var *v)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		ft_putstr_fd("[\x1b[92mfractol\x1b[0m - \x1b[31mconfig\x1b[0m] > ", 2);
		get_next_line(STDIN_FILENO, &line); // check malloc
		ret = execute_line(line, &v->fractal);
		ft_free((void **)&line);
	}
	if (ret == -2) // why?
		return ;
	ft_putendl_fd("[\x1b[92mfractol\x1b[0m Refreshing image...", 2);
	refresh_image(v);
}
