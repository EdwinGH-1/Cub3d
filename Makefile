# CC_ASAN = cc -g -fsanitize=address
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = ./cub3D
HEADERS_DIR = ./includes/
HEADERS_LIST = cub3D.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_INCLUDES)

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
SRCS_LIST = main.c				\

OBJS_DIR = objs
OBJS = $(SRCS_LIST:.c=.o)
OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

LIBFT_PATH = ./libft
LIBFT_INCLUDES = ./libft/includes
LIBFT = $(LIBFT_PATH)/libft.a

$(OBJS_DIR)/%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(OBJS_PATH) -lreadline -ltermcap $(LIBFT) -o $(NAME)
	@echo "$(NAME) created"

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "obj dir created"

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJS_DIR)
	@echo "removed obj dir"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)
	@echo "removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re libft
