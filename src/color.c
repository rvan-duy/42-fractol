/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/16 14:39:24 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/16 16:27:30 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// saved mandelbrots
// max 80 min 50, k * 255, k * 255, 0 with and without cos
// other color inputs
// max 130 min 50, k * 255, k * 255, 0 without cos
// max 200 min 150, k * 255, k * 255, 0 without cos << any color
				// k = (cos(k * 3.14159 + 3.14159) + 1) / 2;
// max 300 min 0, k * 255, k * 255, 0

void	apply_color_theme(t_var v, int row, int col, int iteration)
{
	int		rgb;
	double	k;

	if (iteration < v.fractal.max_ite)
	{
		k = fabs((double)(iteration - v.fractal.min_ite)
				/ (v.fractal.max_ite - v.fractal.min_ite));
		rgb = create_rgb(k * v.fractal.red, k * v.fractal.green,
				k * v.fractal.blue);
		putpixel(&v, col, row, rgb);
	}
	else
		putpixel(&v, col, row, 0x000000);
}
