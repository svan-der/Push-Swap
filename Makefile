# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svan-der <svan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/04 16:50:47 by svan-der      #+#    #+#                  #
#    Updated: 2020/04/29 16:59:52 by svan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME_CHK = checker
NAME_PSW = push_swap

CC = clang
CFLAGS = -Wall -Wextra -Werror
DFLAGS = $(CFLAGS) -g

HEADERS = -Iincludes

LIB_HEADER = -I./libft/includes
LIB_BINARY = -L./libft -lft
LIB = libft/libft.a

SRCDIR = srcs/
CHK_DIR = chkr/
# PSW_DIR = psw/

SRCS = print_stack.c push.c rotate.c utils.c init_ins.c init_stack.c\

CHK_SRC = $(addprefix $(CHK_DIR), checker.c exec_checker.c)

# PSW_SRC = $(addprefix $(PSW_DIR), push_swap.c exec_pushswap.c conquer.c conquer_opts.c divide.c)

OBJ = $(SRCS:%.c=$(SRCDIR)%.o)
CHK_OBJ =$(CHK_SRC:%.c=$(SRCDIR)%.o)
# PSW_OBJ = $(PSW_SRC:%.c=$(SRCDIR)%.o)

# all: $(LIB) $(NAME_CHK) $(NAME_PSW)

all: $(LIB) $(NAME_CHK)

$(LIB):
	make -s -C libft re

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) $(LIB_HEADER) -c -o $@ $<

$(SRCDIR)%.o: %.c
		$(CC) $(CFLAGS) $(HEADERS) $(LIB_HEADER) -c $< -o $@

$(CHK_DIR)%.o: %.c
		$(CC) $(CFLAGS) $(HEADERS) $(LIB_HEADER) -c $< -o $@

$(NAME_CHK): $(OBJ) $(CHK_OBJ) $(LIB)
		echo "$(PURPLE)Compiling checker$(RESET)"
		$(CC) $(CFLAGS) $(HEADERS) $(CHK_OBJ) $(OBJ) $(LIB_BINARY) -o $@
		echo "$(GREEN)Checker is ready!$(RESET)"

# $(PSW_DIR)%.o: %.c
# 		$(CC) $(CFLAGS) $(HEADERS) $(LIB_HEADER) -c $< -o $@

# $(NAME_PSW): $(OBJ) $(PSW_OBJ) $(LIB)
# 		echo "$(PURPLE)Compiling push_swap$(RESET)"
# 		$(CC) $(CFLAGS) $(HEADERS) $(PSW_OBJ) $(OBJ) $(LIB_BINARY) -o $@
# 		echo "$(GREEN)Push_swap is ready!$(RESET)"

clean:
		@echo "$(RED)Deleting object files...$(RESET)"
		@/bin/rm -rf $(OBJ)
		@/bin/rm -f $(CHK_OBJ)
		# @/bin/rm -f $(PSW_OBJ)
		@make -s -C ./libft clean
		@echo "$(GREEN)push_swap clean!$(RESET)"

fclean: clean
		@echo "$(RED)Deleting executables...$(RESET)"
		@/bin/rm -f $(NAME_CHK)
		# @/bin/rm -f $(NAME_PSW)
		@/bin/rm -f $(LIB)
		@echo "$(GREEN)push_swap fclean!$(RESET)"

re: fclean clean all

.PHONY: all so clean fclean re libft

RED	= \033[0;31m
PURPLE = \033[0;35m
GREEN =	\033[0;32m
RESET = \033[0m