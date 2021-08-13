/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 16:28:01 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/12 21:10:39 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>

enum e_fractal_set {
	MANDELBROT,
	JULIA
};

typedef struct s_image {
	void	*addr;
	int		bpp;
	int		ll;
	int		end;
}	t_image;

typedef struct s_fractal {
	int		fractal_set;
	int		variant;
	double	zoom;
	double	zoom_modifier;
	int		x_pos;
	int		y_pos;
}	t_fractal;

typedef struct s_var {
	void		*mlx;
	void		*win;
	void		*img;
	t_image		*img_vars;
	t_fractal	fractal;
}	t_var;

#endif
