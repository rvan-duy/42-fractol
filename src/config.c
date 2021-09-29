/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/16 21:38:32 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/29 17:32:19 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static int	display_info(t_fractal *fractal)
{
	printf("red: %d\n", fractal->red);
	printf("green: %d\n", fractal->green);
	printf("blue: %d\n", fractal->blue);
	printf("max_iterations:%d\n", fractal->max_ite);
	printf("min_iterations:%d\n", fractal->min_ite);
	printf("speed: %.2f\n", fractal->speed);
	printf("zoom: %.2f\n", fractal->zoom);
	printf("x_offset: %.2f\n", fractal->x_offset);
	printf("y_offset: %.2f\n", fractal->y_offset);
	return (-2);
}

static void	display_help(void)
{
	printf("Avaiable commands:\n");
	printf("- help\n");
	printf("- refresh\n");
	printf("- theme: [theme]\n");
	printf("- theme_list\n");
	printf("- max_iterations: [iterations]\n");
	printf("- min_iterations: [iterations]\n");
	printf("- display_info\n");
}

static void	display_themes(void)
{
	printf("themes:\n");
	printf("- white\n");
	printf("- red\n");
	printf("- green\n");
	printf("- blue\n");
	printf("- yellow\n");
	printf("- teal\n");
	printf("- purple\n");
}

static int	execute_line(char *line, t_fractal *fractal)
{
	if (!ft_strncmp(line, "refresh", 7))
		return (0);
	else if (!ft_strncmp(line, "help", 4))
		display_help();
	else if (!ft_strncmp(line, "theme:", 6))
		parse_fractal_color_theme(fractal, line + 6);
	else if (!ft_strncmp(line, "theme_list", 14))
		display_themes();
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
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == -1)
			exit(EXIT_FAILURE);
		ret = execute_line(line, &v->fractal);
		ft_free((void **)&line);
	}
	if (ret == -2)
		return ;
	ft_putendl_fd("[\x1b[92mfractol\x1b[0m] Redrawing image...", 2);
	refresh_image(v);
}
