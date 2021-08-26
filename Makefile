# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/06 15:07:33 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/08/26 13:49:27 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC		= gcc
FLAGS	= -Ofast -Wall -Wextra -Werror -g -fsanitize=address
HEADER	= -I src -I src/libft

HEADER_LINUX = -I src/minilibx_linux
HEADER_MACOS = -I src/minilibx_macos

SRC		= fractol.c \
			init.c \
			parse.c \
			hooks.c \
			set.c \
			draw.c \
			mandelbrot.c \
			burning_ship.c \
			color.c \
			utilities.c \
			config.c

LIBFT		= src/libft/libft.a
MLX_LINUX	= src/minilibx_linux/libmlx.a -lXext -lX11 -lm -lz
MLX_MACOS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

BOLD = \e[1m
RESET = \e[0m
LIGHT_GREEN = \e[92m
LIGHT_CYAN = \e[96m

SRCS 	= $(addprefix src/, $(SRC))
OBJS	= $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

#MacOS
ifeq ($(shell uname), Darwin)
obj/%.o: src/%.c
	@mkdir -p $(@D)
	@printf "${LIGHT_CYAN}${BOLD}make${RESET}   [${LIGHT_GREEN}fractol${RESET}] : "
	$(CC) $(FLAGS) $(HEADER) ${HEADER_MACOS} -c $< -o $@

$(NAME): $(OBJS)
	@make -C src/libft
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX_MACOS) -o $(NAME)
	@printf "${LIGHT_CYAN}${BOLD}make${RESET}   [${LIGHT_GREEN}fractol${RESET}] : "
	@printf "./$(NAME) created\n"

#Linux
else
obj/%.o: src/%.c
	@mkdir -p $(@D)
	@printf "${LIGHT_CYAN}${BOLD}make${RESET}   [${LIGHT_GREEN}fractol${RESET}] : "
	$(CC) $(FLAGS) $(HEADER) ${HEADER_LINUX} -c $< -o $@

$(NAME): $(OBJS)
	@make -C src/libft
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX_LINUX) -o $(NAME)
	@printf "${LIGHT_CYAN}${BOLD}make${RESET}   [${LIGHT_GREEN}fractol${RESET}] : "
	@printf "./$(NAME) created\n"
endif

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
