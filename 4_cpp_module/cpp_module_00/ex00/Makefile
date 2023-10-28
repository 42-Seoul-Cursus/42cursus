NAME=megaphone
CC=c++
CFLAGS=-std=c++98 -Werror -Wall -Wextra
DEBUG=-g
MEMORY=-g3 -fsanitize=address

SRCS=megaphone.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -rf $(NAME) $(NAME).dSYM

re:
	@$(MAKE) fclean
	@$(MAKE) all

mem:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) $(MEMORY)"

lldb:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY: all clean fclean re mem lldb
