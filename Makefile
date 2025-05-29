# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 19:46:07 by dimachad          #+#    #+#              #
#    Updated: 2025/05/26 14:22:37 by dimachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
DEBUG_NAME = fractol_debug
CC = cc
RM = rm -f
FLAGS = -Wall -Werror -Wextra -O2
DEBUG_FLAGS = -Wall -Werror -Wextra -g -O0
LIBFT_DIR = libft/
MLX_DIR = minilibx-linux/
LIBFT = -L$(LIBFT_DIR) -lft
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
SRC = main.c \
	  init.c \
	  render_fractal.c \
	  str_to_float.c \
	  events.c
OBJ = $(SRC:.c=.o)
DEBUG_OBJ = $(SRC:.c=_debug.o)

# Header dependencies
HEADERS = fractol.h

all: $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(NAME)

debug: $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(DEBUG_NAME)

# Library building rules
$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "Cloning minilibx..."; \
		git clone https://github.com/42paris/minilibx-linux.git $(MLX_DIR); \
	fi
	cd $(MLX_DIR) && ./configure
	make -C $(MLX_DIR)

# Header dependencies
$(OBJ): $(HEADERS)
$(DEBUG_OBJ): $(HEADERS)

# Main executable
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

# Debug executable
$(DEBUG_NAME): $(DEBUG_OBJ)
	$(CC) $(DEBUG_FLAGS) $(DEBUG_OBJ) $(LIBFT) $(MLX) -o $(DEBUG_NAME)

# Compilation rules
%.o: %.c
	$(CC) $(FLAGS) -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

%_debug.o: %.c
	$(CC) $(DEBUG_FLAGS) -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

# Cleaning rules
clean:
	$(RM) $(OBJ) $(DEBUG_OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME) $(DEBUG_NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

# Debug rebuild
re_debug: fclean debug

.PHONY: all debug clean fclean re re_debug
