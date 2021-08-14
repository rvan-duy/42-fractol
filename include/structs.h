/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 16:28:01 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/14 17:04:29 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>

enum e_fractal_set {
	MANDELBROT,
	JULIA
};

typedef struct s_addr {
	int		bits_pp;
	int		line_len;
	int		endian;
}	t_addr;

typedef struct s_fractal {
	int		fractal_set;
	void	(*fractal_arr[2])(void *);
	int		variant;
	double	zoom;
	double	speed;
	double	x_offset;
	double	y_offset;
	int		min_ite;
	int		max_ite;
}	t_fractal;

typedef struct s_var {
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	t_addr		addr_vars;
	t_fractal	fractal;
}	t_var;

typedef struct s_math_vars {
	int		row;
	int		col;
	double	comp_real;
	double	comp_imag;
	int		ite;
}	t_math_vars;

#endif
