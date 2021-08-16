/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:55:07 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/16 21:25:08 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "structs.h"
# include "mlx.h"
# include "hooks.h"

void	putpixel(t_var *v, int x, int y, int color);
int		create_rgb(int r, int g, int b);
void	refresh_image(t_var *v);
void	close_window(t_var *v);

#endif
