CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

HEADERS_DIR = ./includes/
HEADERS_LIST = libft.h	get_next_line.h	ft_printf.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
INCLUDES = -I$(HEADERS_DIR)

SRCS_DIR = ./sources/
SRCS_LIST = ft_atoi.c 		ft_bzero.c 		ft_calloc.c 		ft_isalnum.c \
			ft_isalpha.c	ft_isascii.c	ft_isdigit.c		ft_isprint.c \
			ft_itoa.c 		ft_memchr.c 	ft_memcmp.c 		ft_memcpy.c \
			ft_memmove.c	ft_memset.c 	ft_putchar_fd.c		ft_putendl_fd.c \
			ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c			ft_strchr.c \
			ft_strdup.c		ft_striteri.c	ft_strjoin.c		ft_strlcat.c \
			ft_strlcpy.c 	ft_strlen.c 	ft_strmapi.c 		ft_strncmp.c \
			ft_strnstr.c 	ft_strrchr.c 	ft_strtrim.c 		ft_substr.c \
			ft_tolower.c 	ft_toupper.c	get_next_line.c \
			ft_flags_utils_1.c	ft_flags_utils_2.c	ft_print_c.c	ft_print_d_1.c \
			ft_print_d.c		ft_printf.c			ft_print_p.c	ft_print_s.c \
			ft_print_u_1.c		ft_print_u.c		ft_print_x_1.c	ft_print_x.c \
			ft_isspace.c	ft_strcmp.c

# ft_lstadd_back.c	ft_lstadd_front.c \
# ft_lstclear.c	ft_lstdelone.c 	ft_lstiter.c		ft_lstlast.c \
# ft_lstmap.c		ft_lstnew.c 	ft_lstsize.c \

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR = objects/
OBJS_LIST = $(SRCS_LIST:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@ar rcs $@ $(OBJS)
	@echo "object files created"
	@echo "$(NAME) created"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(OBJS_DIR) created"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(OBJS_DIR) deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
