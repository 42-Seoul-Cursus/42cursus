.SUFFIXES : .c .o

NAME = libftprintf.a
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

INCLUDE = -I./include
SRC_DIR = ./src

SRC = \
	ft_printf.c \
	utils.c
OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(WHITE)Creating $@$(RESET)"
	@ar cr $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) created successfully$(RESET)"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "$(CYAN)Compiled:$(RESET) $< -> $@"

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

mem:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) $(MEMORY)"

lldb:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY: all clean fclean re bonus mem lldb
