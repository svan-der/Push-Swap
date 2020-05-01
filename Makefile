# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svan-der <svan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/04 16:50:47 by svan-der      #+#    #+#                  #
#    Updated: 2020/04/30 23:03:47 by svan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME_CHK = checker
NAME_PSW = push_swap

CC = clang
CFLAGS = -Wall -Wextra -Werror
DFLAGS = $(CFLAGS) -g

HEADERS = -I./includes

LIBFT_HEADER = -I./libft/includes
PRINTF_HEADER = -I./libft/includes/printf
LIBFT_BINARY = -L./libft -lft
LIBFT = libft/libft.a

SRCDIR = srcs
OBJ_DIR = srcs/objects
CHK_DIR = srcs/chkr
CHK_OBJDIR = srcs/chkr/objects
# PSW_DIR = psw/

SRCS = print_stack.c push.c rotate.c utils.c init_ins.c init_stack.c

CHK_SRC = checker.c exec_checker.c\

# PSW_SRC = $(addprefix $(PSW_DIR), push_swap.c exec_pushswap.c conquer.c conquer_opts.c divide.c)

OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
CHK_OBJ = $(CHK_SRC:%.c=$(CHK_OBJDIR)/%.o)
# PSW_OBJ = $(PSW_SRC:%.c=$(SRCDIR)%.o)

# all: $(LIBFT) $(NAME_CHK) $(NAME_PSW)

all: $(NAME_CHK)

$(LIBFT):
	make -s -C libft re

$(NAME_CHK): $(OBJ) $(CHK_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CHK_OBJ) $(OBJ) $(LIBFT) -o $@

# $(NAME_CHK): $(OBJ) $(CHK_OBJ) $(LIBFT)
# 	ar rcs $(NAME_CHK) $(CHK_OBJ) $(OBJ) $(LIBFT) $< $@

# %.o: %.c
# 	$(CC) $(CFLAGS) -c -o $@ $<
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRCDIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) $(LIBFT_HEADER) -c $< -o $@
	# mkdir -p $(OBJ_DIR)
	# $(CC) -c -o $@ $<
	# $(CC) $(CFLAGS) -c -o $@ $<

$(CHK_OBJDIR)/%.o: $(CHK_DIR)/%.c
	mkdir -p $(CHK_OBJDIR)
	$(CC) -c -o $@ $<
	$(CC) $(CFLAGS) -c -o $@ $<
	# $(CC) $(CFLAGS) $(LIBFT) $(HEADERS) -c -o $@ $<


# $(CHK_DIR)%.o: %.c
# 		$(CC) $(CFLAGS) $(HEADERS) $(LIBFT_HEADER) -c $< -o $@

# $(NAME_CHK) $(OBJ) $(CHK_OBJ) $(LIBFT)
# 		echo "$(PURPLE)Compiling checker$(RESET)"
# 		$(CC) $(CHK_OBJ) $(OBJ) $(LIBFT_BINARY) -o $@
# 		echo "$(GREEN)Checker is ready!$(RESET)"

# $(CHK_DIR)/%.o: %.c $(LIBFT)
# 		echo "$(PURPLE)Compiling checker$(RESET)"
# 		mkdir -p $(CHK_DIR)
# 		$(CC) -c -o $@ $<
# 		$(CC) $(CFLAGS) $(HEADER) -c -o $@ $<
		# echo "$(GREEN)Checker is ready!$(RESET)"

# $(PSW_DIR)%.o: %.c
# 		$(CC) $(CFLAGS) $(HEADERS) $(LIBFT_HEADER) -c $< -o $@

# $(NAME_PSW): $(OBJ) $(PSW_OBJ) $(LIBFT)
# 		echo "$(PURPLE)Compiling push_swap$(RESET)"
# 		$(CC) $(CFLAGS) $(HEADERS) $(PSW_OBJ) $(OBJ) $(LIBFT_BINARY) -o $@
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
		@/bin/rm -f $(LIBFT)
		@echo "$(GREEN)push_swap fclean!$(RESET)"

re: fclean clean all

.PHONY: all so clean fclean re libft

RED	= \033[0;31m
PURPLE = \033[0;35m
GREEN =	\033[0;32m
RESET = \033[0m