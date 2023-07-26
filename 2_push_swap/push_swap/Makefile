.SUFFIXES : .c .o

NAME=push_swap
CC=gcc
INCLUDE=-I./Libft
CFLAGS=-Wall -Werror -Wextra
DEBUG=-g3 -fsanitize=memory
LIBS= -L./Libft -lft -L./ft_printf -lftprintf

FT_FRINTF=./ft_printf/libftprintf.a
LIBFT=./Libft/libft.a
SRCS=main.c
OBJS=main.o

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./Libft

$(FT_FRINTF):
	$(MAKE) -C ./ft_printf

$(NAME): $(LIBFT) $(FT_FRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./Libft
	$(MAKE) clean -C ./ft_printf
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./Libft
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY: all clean fclean re debug
