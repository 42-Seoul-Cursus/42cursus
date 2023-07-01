NAME=pipex
CC=gcc
INCLUDE=-I./Libft
CFLAGS=-Wall -Werror -Wextra
LIBS= -L./Libft -lft

LIBFT=./Libft/libft.a
SRCS=main.c
OBJS=main.o


all: $(NAME)

$(LIBFT): ./Libft/*.c
	$(MAKE) bonus -C ./Libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
