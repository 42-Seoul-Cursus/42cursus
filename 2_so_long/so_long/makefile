.SUFFIXES : .c .o

NAME=so_long
CC=gcc
INCLUDE=-I./minilibx -I./libft
CFLAGS=-Wall -Werror -Wextra
DEBUG=-g3 -fsanitize=address
LIBS=-L./Libft -lft -L./MiniLibX
FRAMEWORKS=-lmlx -framework OpenGL -framework AppKit
LIBFT=./libft/libft.a
LIBMLX=./minilibx/libmlx.a
SRCS=main.c hook.c get_next_line.c parse.c
OBJS=main.o hook.o get_next_line.o parse.o

all: $(NAME)

$(LIBMLX):
	$(MAKE) -C ./minilibx

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJS) -o $(NAME) $(INCLUDE) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(MAKE) clean -C ./minilibx
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./minilibx
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(DEBUG)"

.PHONY: all clean fclean re debug
