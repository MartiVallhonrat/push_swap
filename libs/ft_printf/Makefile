NAME = libftprintf.a

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -f

SRCS = main_printf.c check_placeholder.c \
	   ft_putchar_count.c ft_putstr_count.c \
	   ft_strlen.c ft_putnbr_count.c \
	   ft_putnbr_count_uns.c ft_putnbr_base_count_uns.c\
	   ft_putnbr_base_count_ulong.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
HEAD = ft_printf.h

%.o: %.c
	$(GCC) $(CFLAGS) -c -MMD $<

$(NAME): $(OBJS) $(HEAD) Makefile
	$(LIB) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
