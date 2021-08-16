/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 18:37:10 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/16 15:12:20 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "fractol.h"
# include "structs.h"

void	init_var(t_fractal *fractal);
void	init_mlx(t_var *v);
void	init_visuals(t_fractal *fractal);

#endif
