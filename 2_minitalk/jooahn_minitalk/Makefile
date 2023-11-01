CFLAGS = -Wall -Wextra -Werror
INC = includes
LIB_DIR = ./libft
OBJS_DIR = obj/

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c

CLIENT_OBJS = $(OBJS_DIR)$(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(OBJS_DIR)$(SERVER_SRCS:.c=.o)

CLIENT_BONUS_OBJS = $(OBJS_DIR)$(CLIENT_BONUS_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(OBJS_DIR)$(SERVER_BONUS_SRCS:.c=.o)

CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	make -C $(LIB_DIR) all
	cc $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) -L$(LIB_DIR) -lft

$(SERVER): $(SERVER_OBJS)
	make -C $(LIB_DIR) all
	cc $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) -L$(LIB_DIR) -lft

$(OBJS_DIR)%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I$(INC)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS)
	make -C $(LIB_DIR) all
	cc $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_OBJS) -L$(LIB_DIR) -lft

$(SERVER_BONUS): $(SERVER_BONUS_OBJS)
	make -C $(LIB_DIR) all
	cc $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_OBJS) -L$(LIB_DIR) -lft

clean:
	make -C $(LIB_DIR) clean
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re:
	make -C $(LIB_DIR) re
	make fclean
	make all

.PHONY: all clean fclean re bonus
