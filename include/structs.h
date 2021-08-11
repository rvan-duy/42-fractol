/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 16:28:01 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/11 16:58:26 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define MANDELBROT 0
# define JULIA 1

# include <stdlib.h>

typedef struct s_image {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_fractol {
	int	fractol_set;
	int	variant;
}	t_fractol;

typedef struct s_mlx {
	void		*mlx;
	void		*win;
	t_image		img;
	t_fractol	fractol_info;
	double		zoom;
}	t_mlx;

typedef struct s_1d_coord {
	int		min_range;
	int		max_range;
	double	point;
}	t_1d_coord;

#endif
