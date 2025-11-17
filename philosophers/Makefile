# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-maga <vde-maga@student.42porto.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 10:36:25 by vde-maga          #+#    #+#              #
#    Updated: 2025/11/17 17:20:01 by vde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------- Variables ---------------------------------------------

# Executable
NAME = philo

# Commands
CC = cc
RM = rm -rf

# Directorys

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

# Compiling Flags
CFLAGS = -Wall -Wextra -Werror -g -pthread
INCLUDES = -I$(INC_DIR)

# SRCs Find
SRCS = $(shell find $(SRC_DIR) -name "*.c")

# OBJs Location
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Colors
TPUT := $(shell command -v tput 2>/dev/null || true)
ifneq ($(TPUT),)
	GREEN := $(shell tput setaf 2)
	RED := $(shell tput setaf 1)
	YELLOW := $(shell tput setaf 3)
	CYAN := $(shell tput setaf 6)
	RESET := $(shell tput sgr0)
else
	GREEN := \033[0;32m
	RED := \033[0;31m
	YELLOW := \033[0;33m
	CYAN := \033[0;36m
	RESET := \033[0m
endif

# ---------------------- Default -----------------------------------------------

all: $(NAME)

# ---------------------- Linking -----------------------------------------------

$(NAME): $(OBJS)
	@printf "\n"
	@printf "%b\n" "$(YELLOW)Linking Object Files to make $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@printf "%b\n" "$(GREEN)Done! Execute ./$(NAME)$(RESET)"
	@printf "%b\n" "$(YELLOW)NBR_PHILOS TIME_DIE TIME_EAT TIME_SLEEP EAT_TIMES$(RESET)"

# ---------------------- Compiling ---------------------------------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p "$(dir $@)"
	@printf "%b\n" "$(CYAN)\n Compiling $<... $(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "%b\n" "$(GREEN)Done Compiling $< $(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
tester: re
	@printf "%b\n" "$(CYAN)\n Cloning Online Tester $<... $(RESET)"
	@git clone https://github.com/dantonik/42-philosophers-tester.git
	@cd 42-philosophers-tester && ./test.sh

# ---------------------- Cleaning ----------------------------------------------

clean:
	@printf "%b\n" "$(CYAN)\n Cleaning Object Files $(RESET)"
	@$(RM) $(OBJ_DIR)
	@printf "%b\n" "$(CYAN)\n Cleaning Tester Files $(RESET)"
	@$(RM) 42-philosophers-tester
	@printf "%b\n" "$(GREEN) Done Cleaning Object Files $(RESET)"


fclean: clean
	@printf "%b\n" "$(RED)Removing executables...$(RESET)"
	@$(RM) $(NAME)
	@printf "%b\n" "$(GREEN)Done Removing the Executables $(RESET)"

re: fclean all

.PHONY: all clean fclean re tester
