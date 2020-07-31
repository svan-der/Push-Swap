# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svan-der <svan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/01 13:41:54 by svan-der      #+#    #+#                  #
#    Updated: 2020/07/31 20:28:29 by svan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap
LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CHECKER_SRCDIR = chkr
CHECKER_OBJDIR = objects
PUSHSWAP_SRCDIR = psw
PUSHSWAP_OBJDIR = objects
SHARED_SRCDIR = shared
SHARED_OBJDIR = objects

SRC = exec_sort.c push.c rotate_and_check.c rotate_rr.c utils.c\
	init_ins.c init_stack.c print_lists.c free_lists.c\

CHK_SRC = checker.c exec_checker.c

PSW_SRC = calc_dist.c push_swap.c conquer.c conquer_opts.c\
	divide.c find.c find_solution.c sort_specified.c\
	stack_utils.c find_top_bottom_part.c\

OBJ = $(SRC:%.c=$(SHARED_OBJDIR)/%.o)
CHK_OBJ =$(CHK_SRC:%.c=$(CHECKER_OBJDIR)/%.o)
PSW_OBJ = $(PSW_SRC:%.c=$(PUSHSWAP_OBJDIR)/%.o)

all: $(NAME_CHECKER) $(NAME_PUSHSWAP)

$(LIBFT):
	@make -C libft

$(NAME_CHECKER): $(CHK_OBJ) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(CHK_OBJ) $(OBJ) -o $(NAME_CHECKER) $(LIBFT)

$(NAME_PUSHSWAP): $(PSW_OBJ) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(PSW_OBJ) $(OBJ) -o $(NAME_PUSHSWAP) $(LIBFT)

$(SHARED_OBJDIR)/%.o: $(SHARED_SRCDIR)/%.c $(LIBFT)
	@mkdir -p $(SHARED_OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(CHECKER_OBJDIR)/%.o: $(CHECKER_SRCDIR)/%.c $(LIBFT)
	@mkdir -p $(CHECKER_OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(PUSHSWAP_OBJDIR)/%.o: $(PUSHSWAP_SRCDIR)/%.c $(LIBFT)
	@mkdir -p $(PUSHSWAP_OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
		@echo "$(RED)Deleting object files...$(RESET)"
		@/bin/rm -rf $(SHARED_OBJDIR)
		@/bin/rm -rf $(CHECKER_OBJDIR)
		@/bin/rm -rf $(PUSHSWAP_OBJDIR)
		@make -s -C ./libft clean
		@echo "$(GREEN)push_swap clean!$(RESET)"

fclean: clean
		@echo "$(RED)Deleting executables...$(RESET)"
		@/bin/rm -rf $(NAME_CHECKER)
		@/bin/rm -rf $(NAME_PUSHSWAP)
		@/bin/rm -rf $(LIBFT)
		@echo "$(GREEN)push_swap fclean!$(RESET)"

re: fclean clean all

.PHONY: all so clean fclean re libft

RED	= \033[0;31m
PURPLE = \033[0;35m
GREEN =	\033[0;32m
RESET = \033[0m%
