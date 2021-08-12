/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:55:07 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/12 13:32:07 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "structs.h"
# include <stdbool.h>

void	putpixel(t_image image, int x, int y, int color);
bool	zoom_if_possible(t_mlx *mlx);
int     create_trgb(int t, int r, int g, int b);

#endif