# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/06 15:07:33 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/08/07 14:01:07 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= fract_ol
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g
HEADER	= -I include

SRC		= main.c

LIBFT	= src/libft/libft.a
MLX		= src/minilibx_linux/libmlx.a -lXext -lX11 -lm -lz

SRCS 	= $(addprefix src/, $(SRC))
OBJS	= $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(NAME): $(OBJS)
	make -C src/libft
	make -C src/minilibx_linux
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)
	/bin/rm -f .DS_Store
	/bin/rm -f a.out

fclean:
	/bin/rm -f $(NAME)
	/bin/rm -rf obj

re: fclean all

test: $(NAME)
	./fract_ol

.PHONY: all clean fclean re
