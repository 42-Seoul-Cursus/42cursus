.SUFFIXES : .c .o

NAME=philo
CC=cc
PRINTF=printf
CFLAGS=-Werror -Wall -Wextra -pthread
DEBUG=-g
THREAD=-g3 -fsanitize=thread
MEMORY=-g3 -fsanitize=address

SRCS= main.c \
	init.c \
	routine.c \
	mornitor.c \
	utils.c \
	cleanup.c \
	print.c
OBJS=$(SRCS:.c=.o)

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

ASCII_ART="\
..............................................................\n\
. \n\
.        :::::::::  :::    ::: ::::::::::: :::        ::::::::\n\
.       :+:    :+: :+:    :+:     :+:     :+:       :+:    :+:\n\
.      +:+    +:+ +:+    +:+     +:+     +:+       +:+    +:+\n\
.     +\#++:++\#+  +\#++:++\#++     +\#+     +\#+       +\#+    +:+\n\
.    +\#+        +\#+    +\#+     +\#+     +\#+       +\#+    +\#+\n\
.   \#+\#        \#+\#    \#+\#     \#+\#     \#+\#       \#+\#    \#+\#\n\
.  \#\#\#        \#\#\#    \#\#\# \#\#\#\#\#\#\#\#\#\#\# \#\#\#\#\#\#\#\#\#\# \#\#\#\#\#\#\#\#\n\
. \n\
..............................................................\
"

all: clear $(NAME)

clear:
	clear
	@echo "$(CYAN)"
	@echo $(ASCII_ART)
	@echo "$(DEFAULT)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@$(PRINTF) "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

th:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(THREAD)"

mem:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(MEMORY)"

deb:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY: all clean fclean re mem th deb
