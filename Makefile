NAME = Cub3d
NAME_LIBFT = libft
NAME_MINILIBX = minilibx-linux
SRCDIR = src/
OBJDIR = objs/
SRCS_FILL = cub3d.c draw/draw_line.c draw/draw_map.c \
			parse/parse.c parse/parse_utils.c parse/parse_texture.c parse/parse_error.c\
			hook/hook.c hook/hook_key.c \
			raycast/raycast.c raycast/draw_ray.c raycast/ray_utils.c
SRCS = $(addprefix $(SRCDIR), $(SRCS_FILL))
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))
MINILIBX = $(NAME_MINILIBX)/libmlx_Linux.a
LIBFT = $(NAME_LIBFT)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror -O3
2FLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz -lXrandr -lXrender -lbsd
RM = rm -rf

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(OBJDIR) $(NAME)

$(LIBFT):
	@make -C $(NAME_LIBFT) > /dev/null 2>&1

$(MINILIBX):
	@make -C $(NAME_MINILIBX) all > /dev/null 2>&1

$(OBJDIR):
	@mkdir -p $(OBJDIR) $(addprefix $(OBJDIR), $(dir $(SRCS_FILL))) > /dev/null 2>&1
	@echo "$(GREEN)creating object files....$(RESET)"

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(OBJS) $(FLAGS) $(2FLAGS) $(LIBFT) $(MINILIBX) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) > /dev/null 2>&1
	@make -C $(NAME_LIBFT) fclean > /dev/null 2>&1
	@echo "$(RED)object files were deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME) > /dev/null 2>&1
	@make -C $(NAME_LIBFT) fclean > /dev/null 2>&1
	@make -C $(NAME_MINILIBX) clean > /dev/null 2>&1
	@echo "$(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re