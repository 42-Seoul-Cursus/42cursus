.SUFFIXES : .cpp .o

NAME    := brain
CXX     := c++
CFLAGS  := -std=c++98 -Werror -Wall -Wextra
DEBUG   := -g
MEMORY  := -g3 -fsanitize=address

BLACK   := \033[30m
RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE    := \033[34m
MAGENTA := \033[35m
CYAN    := \033[36m
WHITE   := \033[37m
RESET   := \033[0m

SRC_DIR := ./src
INCLUDE := -I./inc

SRC     := \
		main.cpp \
		AMateria.cpp \
		AMateriaSource.cpp \
		ICharacter.cpp 
OBJ     := $(addprefix $(SRC_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)
	@echo "$(GREEN)$(NAME) created successfully$(RESET)"

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(WHITE)Creating $@$(RESET)"

%.o: %.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "$(CYAN)Compiled:$(RESET) $< -> $@"

clean:
	@rm -f $(OBJ)
	@echo "$(BLUE)Cleaned up object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
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
	@echo "$(YELLOW)Executable compiled to enable LLDB debugging$(RESET)"

.PHONY: all clean fclean re mem lldb
