NAME=pipex
CC=cc
CFLAGS=Wall -Wextra -Werror
INCLUDES= -I ./includes -I./libft/includes
LIBFT=libft/libft.a
SRCDIR=srcs/
SRCFILES=parent.c

SRCS= $(addprefix $(SRCDIR), $(SRCFILES))
OBJS=libftprintf.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) ./$(NAME)
	ar rcs $(NAME) $(OBJS)
$(LIBFT):
	make -C libft
$.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	make clean -C libft

