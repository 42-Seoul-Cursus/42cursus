.SUFFIXES : .c .o

NAME=push_swap
CC=gcc
CFLAGS=-Wall -Werror -Wextra
LIBFT=./libft/libft.a
INCLUDE=-I./libft
LIBS= -L./libft -lft
DEBUG=-g3 -fsanitize=address

SRCS=main.c deque.c cmd_push.c cmd_swap.c cmd_rotate.c parse.c set_idx.c sort.c utils.c find_min_rot.c find_min_rot_utils.c
OBJS=$(SRCS:.c=.o)

BONUS=checker
BONUS_SRCS=
BONUS_OBJS=$(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(FT_FRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

$(LIBFT):
	$(MAKE) bonus -C ./libft

bonus: $(BONUS) $(LIBFT) -L./get_next_line
	$(CC) $(CFLAGS) $(BONUS_SRCS) -o $(BONUS) $(LIBS) -I./get_next_line

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

.PHONY: all clean fclean re debug bonus
