.SUFFIXES : .c .o

NAME=push_swap
CC=gcc
INCLUDE=-I./libft
CFLAGS=-Wall -Werror -Wextra
DEBUG=-g3 -fsanitize=address
LIBS= -L./libft -lft

LIBFT=./libft/libft.a
SRCS=${wildcard *.c}
OBJS=$(SRCS:.c=.o)

CHECKER=checker
CHECKER_SRCS=${wildcard checker/*.c} cmd.c deque.c

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(NAME): $(LIBFT) $(FT_FRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"

checker:
	$(CC) $(CFLAGS) $(CHECKER_SRCS) -o $(CHECKER) $(LIBS)

.PHONY: all clean fclean re debug checker
