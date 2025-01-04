# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 18:26:02 by phuocngu          #+#    #+#              #
#    Updated: 2025/01/04 22:47:00 by phuocngu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src

SRC_FILES = $(SRC_DIR)/main.c \
			$(SRC_DIR)/mandelbrot.c \
			$(SRC_DIR)/julia.c \
			$(SRC_DIR)/initial_setup.c \
			$(SRC_DIR)/utils/get_color.c \
			$(SRC_DIR)/utils/zoom.c \
			$(SRC_DIR)/utils/esc_key_func.c \
			$(SRC_DIR)/utils/is_within_radius.c \
			$(SRC_DIR)/utils/calc_complex.c \
			$(SRC_DIR)/libft/ft_atof.c \
			$(SRC_DIR)/libft/ft_strcmp.c \
			$(SRC_DIR)/libft/ft_putstr_fd.c \

OBJS = $(SRC_FILES:.c=.o)

NAME = fractol

MLX42_DIR = $(shell pwd)/MLX42
MLX42_NAME = libmlx42.a
MLX42_INCLUDE = -I$(MLX42_DIR)/include
MLX42_LIB = -L$(MLX42_DIR)/build
MLX42_FLAGS = $(MLX42_INCLUDE) $(MLX42_LIB) -lmlx42 -ldl -lglfw -lm -lpthread

%.o: %.c
	$(CC) $(CFLAGS) $(MLX42_INCLUDE) -c $< -o $@

all: $(MLX42_DIR)/build/$(MLX42_NAME) $(NAME)

$(MLX42_DIR)/build/$(MLX42_NAME):
	cd $(MLX42_DIR) && cmake -B build && cmake --build build -j4

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX42_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
