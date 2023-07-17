.SUFFIXES : .c .o

NAME=so_long
CC=gcc
INCLUDE=-I./Libft -I./MiniLibX
CFLAGS=-Wall -Werror -Wextra
DEBUG=-g3 -fsanitize=address
LIBS=-L./Libft -lft -L./MiniLibX
FRAMEWORKS=-lmlx -framework OpenGL -framework AppKit

LIBFT=./Libft/libft.a
LIBMLX=./MiniLibX/libmlx.a
SRCS=main.c src.c color.c hook.c
OBJS=main.o src.o color.o hook.o

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./Libft

$(LIBMLX):
	$(MAKE) -C ./MiniLibX

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJS) -o $(NAME) $(INCLUDE) $(LIBS)

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

debug:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY: all clean fclean re debug
