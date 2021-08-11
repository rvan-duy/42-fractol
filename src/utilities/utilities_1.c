/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:52:44 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/09 16:49:22 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <math.h>

void	putpixel(t_image image, int x, int y, int color)
{
	const char	*dst = image.addr + (y * image.line_length
		+ x * (image.bits_per_pixel / 8));

	*(unsigned int *)dst = color;
}

void	re_scale_coord(t_1d_coord *src, t_1d_coord *dst)
{
	const double	ratio = (src->point + abs(src->min_range))
		/ (src->max_range + abs(src->min_range));

	dst->point = (dst->max_range + abs(dst->min_range))
		* ratio + dst->min_range;
}

double	map(int original_point, int original_max, int new_min, int new_max)
{
	const double	ratio = (double)original_point / original_max;

	return ((new_max + abs(new_min)) * ratio + new_min);
}
