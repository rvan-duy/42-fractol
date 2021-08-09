/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 22:51:06 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/08 23:04:19 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "structs.h"

int	main_hook(t_mlx *mlx);
int	key_hook(int keycode, t_mlx *mlx);

#endif
