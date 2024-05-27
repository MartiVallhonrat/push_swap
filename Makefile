NAME = push_swap

GCC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

LIBFT = libs/libft
FT_PRINTF = libs/ft_printf

SRCS_FILES = main.c \
			 get_args.c \
			 check_args.c \
			 split_custom.c \
			 atoi_custom.c \
			 create_lst.c \
			 lst_utils.c \
			 operations.c \
			 operations2.c \
			 operations3.c \
			 sort.c \
			 sort_utils.c \
			 sort_utils2.c \
			 do_sort.c \
			 do_sort2.c \

HEAD = push_swap.h
MAKE = Makefile

SRCS_DIR = srcs/
OBJS_DIR = objs/


OBJS_FILES = $(SRCS_FILES:.c=.o)
DEPS_FILES = $(SRCS_FILES:.c=.d)

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))
DEPS = $(addprefix $(OBJS_DIR), $(DEPS_FILES))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(GCC) $(CFLAGS) -c -MMD $< -o $@

$(NAME): $(OBJS) $(HEAD) $(MAKE) libft.a
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@make -C $(FT_PRINTF)
	@cp $(FT_PRINTF)/libftprintf.a .
	$(GCC) $(CFLAGS) $(OBJS) libft.a libftprintf.a -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	@make clean -C $(LIBFT)
	@make clean -C $(FT_PRINTF)

fclean: clean
	$(RM) $(NAME)
	$(RM) libft.a
	$(RM) libftprintf.a
	$(RM) $(LIBFT)/libft.a
	$(RM) $(FT_PRINTF)/libftprintf.a

re: fclean all

-include $(DEPS)

.PHONY: clean fclean re all
