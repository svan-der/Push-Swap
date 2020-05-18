# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svan-der <svan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/01 13:41:54 by svan-der      #+#    #+#                  #
#    Updated: 2020/05/18 09:08:47 by svan-der      ########   odam.nl          #
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
EXEDIR = ./

SRC = print_stack.c push.c rotate.c utils.c init_ins.c init_stack.c print_lists.c free_lists.c
CHK_SRC = checker.c exec_checker.c
PSW_SRC = push_swap.c exec_pushswap.c conquer.c conquer_opts.c divide.c

OBJ = $(SRC:%.c=$(SHARED_OBJDIR)/%.o)
CHK_OBJ =$(CHK_SRC:%.c=$(CHECKER_OBJDIR)/%.o)
PSW_OBJ = $(PSW_SRC:%.c=$(PUSHSWAP_OBJDIR)%.o)

all: $(EXEDIR)$(NAME_CHECKER) $(EXEDIR)$(NAME_PUSHSWAP)

$(LIBFT):
	make -C libft

$(EXEDIR)$(NAME_CHECKER): $(CHK_OBJ) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CHK_OBJ) $(OBJ) -o $(EXEDIR)$(NAME_CHECKER) $(LIBFT)

$(EXEDIR)$(NAME_PUSHSWAP): $(CHK_OBJ) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CHK_OBJ) $(OBJ) -o $(EXEDIR)$(NAME_PUSHSWAP) $(LIBFT)

$(SHARED_OBJDIR)/%.o: $(SHARED_SRCDIR)/%.c $(LIBFT)
	mkdir -p $(SHARED_OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(CHECKER_OBJDIR)/%.o: $(CHECKER_SRCDIR)/%.c $(LIBFT)
	mkdir -p $(CHECKER_OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PUSHSWAP_OBJDIR)/%.o: $(PUSHSWAP_SRCDIR)/%.c %(LIBFT)
	mkdir -p $(PUSHSWAP_OBJDIR)
	(CC) $(CFLAGS) -c -o $@ $<

clean:
		@echo "$(RED)Deleting object files...$(RESET)"
		@/bin/rm -rf $(OBJ)
		@/bin/rm -f $(CHK_OBJ)
		@/bin/rm -f $(PSW_OBJ)
		@make -s -C ./libft clean
		@echo "$(GREEN)push_swap clean!$(RESET)"

fclean: clean
		@echo "$(RED)Deleting executables...$(RESET)"
		@/bin/rm -f $(NAME_CHK)
		@/bin/rm -f $(NAME_PSW)
		@/bin/rm -f $(LIBFT)
		@echo "$(GREEN)push_swap fclean!$(RESET)"

re: fclean clean all

.PHONY: all so clean fclean re libft

RED	= \033[0;31m
PURPLE = \033[0;35m
GREEN =	\033[0;32m
RESET = \033[0m%