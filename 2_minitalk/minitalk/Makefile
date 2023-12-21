.SUFFIXES : .c .o

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MEMORY = -g3 -fsanitize=address
DEBUG = -g

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
RESET = \033[0m

BLACK_ = \033[40m
RED_ = \033[41m
GREEN_ = \033[42m
YELLOW_ = \033[43m
BLUE_ = \033[44m
MAGENTA_ = \033[45m
CYAN_ = \033[46m
WHITE_ = \033[47m

INCLUDE = -I./include -I./Libft/include -I./ft_printf/include
SRC_DIR = ./src
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_OBJS = $(addprefix $(SRC_DIR)/, $(CLIENT_SRCS:.c=.o))
SERVER_OBJS = $(addprefix $(SRC_DIR)/, $(SERVER_SRCS:.c=.o))

CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_OBJS = $(addprefix $(SRC_DIR)/, $(CLIENT_BONUS_SRCS:.c=.o))
SERVER_BONUS_OBJS = $(addprefix $(SRC_DIR)/, $(SERVER_BONUS_SRCS:.c=.o))

all: $(FT_PRINTF) $(LIBFT) $(CLIENT) $(SERVER)
	@echo "$(GREEN)All compiled successfully$(RESET)"

$(FT_PRINTF):
	@$(MAKE) all -C ./ft_printf
	@echo "$(GREEN)ft_printf compiled successfully$(RESET)"

$(LIBFT):
	@$(MAKE) all -C ./Libft
	@echo "$(GREEN)Libft compiled successfully$(RESET)"

$(CLIENT): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF)
	@echo "$(CYAN)Compiled:$(RESET) $(CLIENT)"

$(SERVER): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)
	@echo "$(CYAN)Compiled:$(RESET) $(SERVER)"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "$(CYAN)Compiled:$(RESET) $<"

bonus: $(FT_PRINTF) $(LIBFT) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "$(GREEN)All compiled successfully$(RESET)"

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_OBJS) $(LIBFT) $(FT_PRINTF)
	@echo "$(CYAN)Compiled:$(RESET) $(CLIENT_BONUS)"

$(SERVER_BONUS): $(SERVER_BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_OBJS) $(LIBFT) $(FT_PRINTF)
	@echo "$(CYAN)Compiled:$(RESET) $(SERVER_BONUS)"

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./ft_printf
	@rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)
	@echo "$(BLUE)Cleaned up object files$(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./ft_printf
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "$(BLUE)Cleaned up executable and library$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

mem:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) $(MEMORY)"
	@echo "$(YELLOW)Executable compiled with memory sanitizer$(RESET)"

lldb:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"
	@echo "$(YELLOW)Executable compiled with LLDB debugging symbols$(RESET)"

.PHONY: all clean fclean re bonus mem lldb
