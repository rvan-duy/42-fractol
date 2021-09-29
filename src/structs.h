/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 16:28:01 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/29 17:44:07 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <stdbool.h>

enum e_fractal_set {
	MANDELBROT,
	JULIA,
	BURNING_SHIP
};

enum e_fractal_color {
	WHITE,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	TEAL,
	PURPLE
};

typedef struct s_addr {
	int		bits_pp;
	int		line_len;
	int		endian;
}	t_addr;

typedef struct s_var	t_var;
typedef struct s_fractal {
	int		fractal_set;
	void	(*fractal_arr[3])(t_var *);
	int		fractal_color_theme;
	int		red;
	int		green;
	int		blue;
	bool	simple_color;
	double	zoom;
	double	speed;
	double	x_offset;
	double	y_offset;
	int		min_ite;
	int		max_ite;
	double	extra_param_1;
	double	extra_param_2;
}	t_fractal;

typedef struct s_var {
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	t_addr		addr_vars;
	t_fractal	fractal;
	bool		needs_draw;
	bool		is_drawing;
}	t_var;

#endif
