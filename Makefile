NAME = Cub3d
NAME_LIBFT = libft
SRCDIR = src/
OBJDIR = objs/
SRCS_FILL = cub3d.c parse/parse.c parse/parse_utils.c parse/parse_texture.c
SRCS = $(addprefix $(SRCDIR), $(SRCS_FILL))
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))
LIBFT = $(NAME_LIBFT)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(OBJDIR) $(NAME)

$(LIBFT):
	@make -C $(NAME_LIBFT) > /dev/null 2>&1

$(OBJDIR):
	@mkdir -p $(OBJDIR) $(addprefix $(OBJDIR), $(dir $(SRCS_FILL))) > /dev/null 2>&1
	@echo "$(GREEN)creating object files....$(RESET)"

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME) > /dev/null 2>&1
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
	@echo "$(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re