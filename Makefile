# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/06 15:07:33 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/08/14 21:18:57 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g
HEADER	= -I include

SRC		= main/_main.c \
			main/init.c \
			hooks/hooks.c \
			fractals/draw_fractal.c \
			fractals/mandelbrot.c \
			utilities/utilities_1.c

LIBFT	= src/libft/libft.a
MLX		= src/minilibx_linux/libmlx.a -lXext -lX11 -lm -lz

BOLD = \e[1m
RESET = \e[0m
LIGHT_GREEN = \e[92m
LIGHT_CYAN = \e[96m

SRCS 	= $(addprefix src/, $(SRC))
OBJS	= $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(@D)
	@printf "${LIGHT_CYAN}${BOLD}make${RESET}   [${LIGHT_GREEN}fractol${RESET}] : "
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(NAME): $(OBJS)
	@make -C src/libft
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@printf "${LIGHT_CYAN}${BOLD}make${RESET}   [${LIGHT_GREEN}fractol${RESET}] : "
	@printf "./$(NAME) created\n"

clean:
	@printf "${LIGHT_CYAN}${BOLD}clean${RESET} [${LIGHT_GREEN}fractol${RESET}] : "
	/bin/rm -rf obj
	@make -C src/libft clean

fclean: clean
	@printf "${LIGHT_CYAN}${BOLD}fclean${RESET} [${LIGHT_GREEN}fractol${RESET}] : "
	/bin/rm -f $(NAME)
	@make -C src/libft fclean

re: fclean all

test: $(NAME)
	@printf "${LIGHT_CYAN}${BOLD}test${RESET}   [${LIGHT_GREEN}fractol${RESET}] : "
	./fractol mandelbrot

only_program: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

.PHONY: all clean fclean re
