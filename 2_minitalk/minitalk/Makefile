.SUFFIXES : .c .o

CLIENT=client
SERVER=server
CC=gcc
CFLAGS=-Wall -Werror -Wextra
DEBUG=-g3 -fsanitize=address

LIBFT=./Libft/libft.a
FT_PRINTF=./ft_printf/libftprintf.a

CLIENT_SRCS=client.c
CLIENT_OBJS=$(CLIENT_SRCS:.c=.o)

SERVER_SRCS=server.c
SERVER_OBJS=$(SERVER_SRCS:.c=.o)

all: $(CLIENT) $(SERVER)

client: $(CLIENT)

server: $(SERVER)

$(CLIENT): $(LIBFT) $(FT_PRINTF) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT) $(LIBFT) $(FT_PRINTF)

$(SERVER): $(LIBFT) $(FT_PRINTF) $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	$(MAKE) bonus -C ./Libft

$(FT_PRINTF):
	$(MAKE) all -C ./ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./Libft
	$(MAKE) clean -C ./ft_printf
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	$(MAKE) fclean -C ./Libft
	$(MAKE) fclean -C ./ft_printf
	rm -f $(CLIENT) $(SERVER)

re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY: all clean fclean re debug client server
