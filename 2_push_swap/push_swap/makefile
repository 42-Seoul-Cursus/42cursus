.SUFFIXES : .c .o

NAME=push_swap
CC=gcc
INCLUDE=-I./libft
CFLAGS=-Wall -Werror -Wextra
DEBUG=-g3 -fsanitize=address
LIBS= -L./libft -lft -L./ft_printf -lftprintf

FT_FRINTF=./ft_printf/libftprintf.a
LIBFT=./libft/libft.a
SRCS=main.c utils.c
OBJS=main.o utils.o

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(FT_FRINTF):
	$(MAKE) -C ./ft_printf

$(NAME): $(LIBFT) $(FT_FRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY: all clean fclean re debug
