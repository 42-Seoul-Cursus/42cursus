.SUFFIXES : .c .o

NAME=so_long
CC=gcc
INCLUDE=-I./MiniLibX
CFLAGS=-Wall -Werror -Wextra
DEBUG=-g3 -fsanitize=address
LIBS=-L./MiniLibX
FRAMEWORKS=-lmlx -framework OpenGL -framework AppKit
LIBMLX=./MiniLibX/libmlx.a
SRCS=main.c parse.c hook.c valid.c dfs.c hook_utils.c protect.c get_next_line.c get_next_line_utils.c
OBJS=main.o parse.o hook.o valid.o dfs.o hook_utils.o protect.o get_next_line.o get_next_line_utils.o

all: $(NAME)

$(LIBMLX):
	$(MAKE) -C ./MiniLibX

$(NAME): $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJS) -o $(NAME) $(INCLUDE) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(MAKE) clean -C ./MiniLibX
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./MiniLibX
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(DEBUG)"

.PHONY: all clean fclean re debug
