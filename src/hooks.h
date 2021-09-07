/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/08 22:51:06 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/09/07 15:48:39 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "fractol.h"
# include "draw.h"
# include "config.h"
# include "set.h"
# include <stdio.h>

# define KEY_PRESS 2
# define DESTORY_NOTIFY 17
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5

# define KEY_ESC 53
# define KEY_M 46
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

int	main_hook(t_var *v);
int	key_hook(int keycode, t_var *v);
int	mouse_scroll_start(int scroll, int x, int y, t_var *v);

#endif
