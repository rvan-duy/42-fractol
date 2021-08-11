/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:55:07 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/09 15:30:11 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "structs.h"

void	putpixel(t_image image, int x, int y, int color);
void	re_scale_coord(t_1d_coord *src, t_1d_coord *dst);
double	map(int original_point, int original_max, int new_min, int new_max);

#endif