.SUFFIXES : .c .o

NAME=so_long
CC=gcc
INCLUDE=-I./minilibx
CFLAGS=-Wall -Werror -Wextra
DEBUG=-g3 -fsanitize=address
LIBS=-L./MiniLibX
FRAMEWORKS=-lmlx -framework OpenGL -framework AppKit
LIBMLX=./minilibx/libmlx.a
SRCS=main.c hook.c get_next_line.c get_next_line_utils.c parse.c protect.c
OBJS=main.o hook.o get_next_line.o get_next_line_utils.o parse.o protect.o

all: $(NAME)

$(LIBMLX):
	$(MAKE) -C ./minilibx

$(NAME): $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJS) -o $(NAME) $(INCLUDE) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(MAKE) clean -C ./minilibx
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./minilibx
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(DEBUG)"

.PHONY: all clean fclean re debug
