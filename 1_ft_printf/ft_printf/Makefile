.SUFFIXES : .c .o

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRCS=$(shell echo *.c)
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
