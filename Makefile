GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3
CFLAGS2 = -lXext -lX11 -lm

NAME = ./cub3d
HEADERS_DIR = ./includes/
HEADERS_LIST = cub3D.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_INCLUDES) -I$(MLX_PATH)

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
SRCS_LIST =	 					\
			cub3d.c					\
			parse.c					\
			parse_color.c			\
			parse_color_utils.c		\
			parse_map.c				\
			parse_map_utils.c		\
			parse_utils.c			\
			parse_texture.c			\
			parse_texture_utils.c	\
			draw_background.c		\
			draw_raycasting_1.c		\
			draw_raycasting_2.c		\
			draw_minimap.c			\
			draw_map.c				\
			draw_fov.c				\
			draw_player.c			\
			free_1.c				\
			free_2.c				\
			hooks.c					\
			loop.c					\
			init_mlx.c				\
			init_minimap.c			\
			init_player.c			\
			init_texture.c			\
			init_animation_1.c		\
			init_animation_2.c		\
			key_press_func.c		\
			handle_animation.c		\
			handle_movement.c		\
			handle_rotation.c		\

OBJS_DIR = objs
OBJS = $(SRCS_LIST:.c=.o)
OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

LIBFT_PATH = ./libft
LIBFT_INCLUDES = $(LIBFT_PATH)/includes
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx.a

$(OBJS_DIR)/%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS_PATH) $(MLX)
	@$(CC) $(CFLAGS) $(CFLAGS2) $(OBJS_PATH) $(LIBFT) $(MLX) -Lminilibx-linux -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_PATH) > /dev/null 2>&1

$(MLX):
	@make -C $(MLX_PATH) all > /dev/null 2>&1

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR) > /dev/null 2>&1
	@echo "$(GREEN)creating object files....$(RESET)"

clean:
	@make -C $(LIBFT_PATH) clean > /dev/null 2>&1
	@make -C $(MLX_PATH) clean > /dev/null 2>&1
	@rm -rf $(OBJS_DIR) > /dev/null 2>&1
	@echo "$(RED)object files were deleted$(RESET)"

fclean: clean
	@make -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@rm -rf $(NAME) > /dev/null 2>&1
	@echo "$(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
