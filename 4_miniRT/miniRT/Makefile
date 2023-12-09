.SUFFIXES : .c .o

NAME=miniRT
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g3 -fsanitize=address
DEBUG=-g3 -fsanitize=address

INCLUDE=-I./MiniLibX
LIBS=-L./MiniLibX
FRAMEWORKS=-lmlx -framework OpenGL -framework AppKit
LIBMLX=./MiniLibX/libmlx.a
SRCS=main.c \
	operations.c \
	operations2.c \
	pixel.c
OBJS=$(SRCS:.c=.o)

# -----make practiceMLX-----
p:
	$(MAKE) 'SRCS=practiceMLX.c' 'NAME=practiceMLX' all
# -----make practiceMLX-----

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
