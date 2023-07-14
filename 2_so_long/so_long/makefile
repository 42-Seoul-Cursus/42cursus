NAME=so_long
CC=gcc
INCLUDE=-I./Libft -I./MiniLibX
CFLAGS=-Wall -Werror -Wextra
LIBS=-L./Libft -lft -L./MiniLibX
FRAMEWORKS=-Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT=./Libft/libft.a
LIBMLX=./MiniLibX/libmlx.a
SRCS=main.c
OBJS=main.o

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./Libft

$(LIBMLX):
	$(MAKE) -C ./MiniLibX

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME) $(LIBS) $(FRAMEWORKS)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(MAKE) clean -C ./MiniLibX
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./MiniLibX
	$(MAKE) fclean -C ./Libft
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
