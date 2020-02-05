# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svan-der <svan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/04 16:50:47 by svan-der       #+#    #+#                 #
#    Updated: 2020/02/04 17:51:26 by svan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = checker

CFLAGS = -g -Wall -Wextra -Werror

HEADERS = -I./includes

LIB_HEADER = -I./libft/includes

LIB_BINARY = -L./libft -lft

LIB = libft/libft.a

SRCS = main.c checker.c print_stack.c push.c rotate.c utils.c

SRCDIR = srcs
OBJDIR = objects

OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

all: $(LIB) $(NAME)

$(LIB):
		@make -s -C libft re

$(OBJDIR):
		@mkdir $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
		@$(CC) $(CFLAGS) $(HEADERS) $(LIBFT_HEADER) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
		@echo "$(PURPLE)Compiling checker$(RESET)"
		@$(CC) $(CFLAGS) $(OBJS) $(LIB_BINARY) -o $@
		@echo "$(GREEN)Checker is ready!$(RESET)"

clean:
		@echo "$(RED)Deleting object files...$(RESET)"
		@/bin/rm -f $(OBJS)
		@rm -rf $(OBJDIR)
		@make -s -C ./libft clean

fclean: clean
		@echo "$(RED)Deleting executables...$(RESET)"
		@/bin/rm -f $(NAME)
		@/bin/rm -f $(LIB)

re: fclean clean all

.PHONY: all so clean fclean re libft

RED	= \033[0;31m
PURPLE = \033[0;35m
GREEN =	\033[0;32m
RESET = \033[0m