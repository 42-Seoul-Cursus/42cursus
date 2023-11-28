.SUFFIXES : .cpp .o

NAME=replace
CC=c++
CFLAGS=-std=c++98 -Werror -Wall -Wextra
DEBUG=-g
MEMORY=-g3 -fsanitize=address

SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

mem:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(MEMORY)"

lldb:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY: all clean fclean re mem deb
