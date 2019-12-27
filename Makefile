# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 20:05:36 by qdang             #+#    #+#              #
#    Updated: 2019/12/25 19:29:49 by qdang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra -g

MLX_PATH = ./minilibx
MLX_LINK = -I $(MLX_PATH) -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

LIB_PATH = ./libft
LIB_LINK = -I $(MLX_PATH) -L $(LIB_PATH) -lft

$(NAME):
	@make -C $(MLX_PATH)
	@make -C $(LIB_PATH)
	@gcc -g -c *.c
	@gcc $(MLX_LINK) $(LIB_LINK) *.o -o $(NAME)

all: $(NAME)

clean:
	@make clean -C $(MLX_PATH)
	@make fclean -C $(LIB_PATH)
	@rm *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
