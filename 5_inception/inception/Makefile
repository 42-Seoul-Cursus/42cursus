FG_BLACK		:= \x1b[90m
FG_RED			:= \x1b[91m
FG_GREEN		:= \x1b[92m
FG_YELLOW		:= \x1b[93m
FG_BLUE			:= \x1b[94m
FG_MAGENTA		:= \x1b[95m
FG_CYAN			:= \x1b[96m
FG_WHITE		:= \x1b[97m
FG_DEFAULT		:= \x1b[39m

DEFAULT			:= \x1b[0m
BOLD			:= \x1b[1m
ITALIC			:= \x1b[3m
UNDERLINE		:= \x1b[4m
REVERSE			:= \x1b[7m
STRIKETHROUGH	:= \x1b[9m

BG_BLACK		:= \x1b[100m
BG_RED			:= \x1b[101m
BG_GREEN		:= \x1b[102m
BG_YELLOW		:= \x1b[103m
BG_BLUE			:= \x1b[104m
BG_MAGENTA		:= \x1b[105m
BG_CYAN			:= \x1b[106m
BG_WHITE		:= \x1b[107m
BG_DEFAULT		:= \x1b[49m

RESET 			:= \x1b[0m

all: 
	@make build
	@make up

build:
	@echo "🐳 $(FG_BLUE)Building images$(RESET) 🐳"
	@docker-compose -f srcs/docker-compose.yml -p "inception" build
	@echo "🛠  $(FG_GREEN)Built images$(RESET) 🛠"

up:
	@docker-compose -f srcs/docker-compose.yml -p "inception" up -d
	@echo "🛜  $(FG_GREEN)Connect to $(FG_WHITE)$(UNDERLINE)https://localhost$(RESET) 🛜"

down:
	@docker-compose -f srcs/docker-compose.yml -p "inception" down
	@echo "🚫 $(FG_RED)Disconnected$(RESET) 🚫"

stop:
	@docker-compose -f srcs/docker-compose.yml -p "inception" stop
	@echo "🛑 $(FG_YELLOW)Stopped$(RESET) 🛑"

start:
	@echo "$(FG_GREEN)Started$(RESET)"
	@docker-compose -f srcs/docker-compose.yml -p "inception" start
	@echo "$(FG_GREEN)Connect to $(FG_WHITE)$(UNDERLINE)https://localhost$(RESET)"

re:
	@echo "$(FG_GREEN)Restarted$(RESET)"
	@make clean
	@make all

log:
	@echo "📄 $(FG_CYAN)Logs$(RESET) 📄"
	@docker-compose -f srcs/docker-compose.yml -p "inception" logs -f

clean:
	@make down
	@docker volume rm -f inception_dbdata inception_wordpress
	@docker system prune -af --volumes
	@echo "🧹 $(FG_BLUE)Cleaned up$(RESET) 🧹"

.PHONY: all build up down stop start re log clean

