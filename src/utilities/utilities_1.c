/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 21:52:44 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/08 21:54:49 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	putpixel(t_image image, int x, int y, int color)
{
	char	*dst;

	dst = image.addr + (y * image.line_length + x * (image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
