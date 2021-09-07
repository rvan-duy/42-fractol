/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/16 15:00:47 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/07 15:18:37 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structs.h"
# include "libft.h"
# include <stdio.h>

void	parse_fractal_type(t_fractal *fractal, char *argument);
void	parse_fractal_color_theme(t_fractal *t_fractal, char *argument);
void	parse_fractal_extra_values(t_fractal *t_fractal, char **argument);

#endif
