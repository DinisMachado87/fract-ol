# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 15:08:24 by dimachad          #+#    #+#              #
#    Updated: 2025/05/17 20:52:58 by dimachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
DEBUG_NAME	= fractol_debug
CC			= cc
RM			= rm -f

FLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -Wall -Werror -Wextra -g -O0

LIBFT_DIR	= libft/
MLX_DIR		= minilibx/

LIBFT		= -L$(LIBFT_DIR) -lft
MLX			= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC			= main.c
OBJ			= $(SRC:.c=.o)
DEBUG_OBJ	= $(SRC:.c=_debug.o)

# Add header dependency
HEADERS		= fractol.h

# Recompile .o if .h changes
main.o: main.c $(HEADERS)
main_debug.o: main.c $(HEADERS)

.c.o:
	$(CC) $(FLAGS) -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

%_debug.o: %.c
	$(CC) $(DEBUG_FLAGS) -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(MLX)

debug: $(DEBUG_NAME)

$(DEBUG_NAME): $(DEBUG_OBJ)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(DEBUG_FLAGS) $(DEBUG_OBJ) -o $(DEBUG_NAME) $(LIBFT) $(MLX)

clean:
	$(RM) $(OBJ) $(DEBUG_OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME) $(DEBUG_NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re debug

