# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 18:48:54 by bpalchet          #+#    #+#              #
#    Updated: 2025/04/08 15:24:04 by bpalchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -Iminilibx-linux
MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# Codici colore ANSI
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

FT_PRINTF_DIR = includes/ft_printf
FT_PRINTF_FLAGS = -L$(FT_PRINTF_DIR) -lftprintf
GNL_DIR = includes/get_next_line
GNL_FLAGS = -L$(GNL_DIR) -lgnl
LIBFT_DIR = includes/libft
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

SRCS = src/main.c src/game.c src/map.c src/graphics.c src/events.c src/render.c \
		src/controls.c src/map_utils.c src/map_utils_2.c

BONUS_SRCS = src/bonus/main_bonus.c src/bonus/game_bonus.c src/bonus/map_bonus.c \
				src/bonus/graphics_bonus.c src/bonus/events_bonus.c src/bonus/render_bonus.c \
				src/bonus/controls_bonus.c src/bonus/map_utils_bonus.c src/bonus/map_utils_2_bonus.c \
				src/bonus/bonus.c
		
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(MLX_DIR)/libmlx.a
	@echo "$(YELLOW)Compiling Libft..."
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled!"
	@echo "$(YELLOW)Compiling ft_printf..."
	@make -s -C $(FT_PRINTF_DIR)
	@echo "$(GREEN)ft_printf compiled!"
	@echo "$(YELLOW)Compiling get_next_line..."
	@make -s -C $(GNL_DIR)
	@echo "$(GREEN)get_next_line compiled!"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) $(GNL_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) successfully compiled!"

$(BONUS_NAME): $(BONUS_OBJS) $(MLX_DIR)/libmlx.a
	@echo "$(YELLOW)Compiling Libft..."
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled!"
	@echo "$(YELLOW)Compiling ft_printf..."
	@make -s -C $(FT_PRINTF_DIR)
	@echo "$(GREEN)ft_printf compiled!"
	@echo "$(YELLOW)Compiling get_next_line..."
	@make -s -C $(GNL_DIR)
	@echo "$(GREEN)get_next_line compiled!"
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) $(GNL_FLAGS) $(MLX_FLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)$(BONUS_NAME) successfully compiled!"

$(MLX_DIR)/libmlx.a:
	@echo "$(YELLOW)Building Minilibx...$(RESET)"
	@make -s -C $(MLX_DIR) 2>/dev/null || (echo "$(RED)Minilibx compilation failed!$(RESET)" && exit 1)
	@echo "$(GREEN)Minilibx compiled!"

%.o: %.c
	@echo "$(BLUE)Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

src/bonus/%.o: src/bonus/%.c
	@echo "$(MAGENTA)Compiling bonus file $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files..."
	rm -f $(OBJS) $(BONUS_OBJS)
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(FT_PRINTF_DIR) clean
	@make -s -C $(GNL_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@echo "$(GREEN)Cleaning done!"
		
fclean: clean
	@echo "$(RED)Full cleaning in progress..."
	rm -f $(NAME) $(BONUS_NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(FT_PRINTF_DIR) fclean
	@make -s -C $(GNL_DIR) fclean
	@echo "$(GREEN)Full cleaning done!"

re: fclean all

.PHONY: all clean fclean re
