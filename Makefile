# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 17:37:18 by mtani             #+#    #+#              #
#    Updated: 2024/04/30 13:19:29 by cbaroi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = $(addprefix srcs/, so_long.c get_next_line.c get_next_line_utils.c check_args.c check_map.c check_map02.c check_map03.c game_init.c update_image.c handle_key.c)

OBJS = $(SRCS:.c=.o) 

MLX = "https://github.com/42Paris/minilibx-linux.git"
MLX_DIR = mlx
FLAGS = -Lmlx -lmlx -lX11 -lXext

%.o: %.c
	cc -Wall -Wextra -Werror -g $(FLAGS) -c $< -o $@

all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
	@git clone $(MLX) mlx
	@cd $(MLX_DIR) && ./configure

$(NAME): $(OBJS)
	cc -o $(NAME) -Wall -Wextra -Werror -g $(OBJS) $(FLAGS)
	rm -rf $(OBJS)
	rrm -rf $(MLX_DIR)

clean:
	rm -rf $(MLX_DIR)
	rm -rf $(OBJS)

fclean:
	rm -f $(NAME)
	rm -rf $(MLX_DIR)
	
re: fclean all
