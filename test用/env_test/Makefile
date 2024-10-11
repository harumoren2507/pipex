NAME=env
CC=clang
CFLAGS=-Wall -Wextra -Werror
INCLUDES= -I ./includes -I./libft/includes
LIBFT=libft/libft.a
SRCDIR=srcs/
SRCFILES=env.c

SRCS= $(addprefix $(SRCDIR), $(SRCFILES))
OBJS=$(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
$(LIBFT):
	make -C libft
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make clean -C libft
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

