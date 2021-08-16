/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 22:51:06 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/16 14:19:49 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "fractol.h"
# include "utilities.h"
# include "libft.h"
# include "draw.h"
# include <stdio.h>

# define KEY_PRESS 2
# define DESTORY_NOTIFY 17

# define ESC_LINUX 65307
# define ESC_MACOS 53
# define Z_LINUX 122

int	main_hook(t_var *v);
int	key_hook(int keycode, t_var *v);

#endif
