# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svan-der <svan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/11 15:22:00 by svan-der       #+#    #+#                 #
#    Updated: 2020/02/10 11:47:38 by svan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
LIB_HEADER = -Iincludes/
PRINT_HEADER = -I./includes/ft_printf

LIB_SRC = ft_memchr.c ft_putnbr_fd.c ft_striter.c\
	ft_strnew.c ft_atoi.c ft_abs.c ft_pow.c\
	ft_memcmp.c ft_putstr.c ft_itoa.c ft_gridset.c\
	ft_bzero.c ft_memcpy.c ft_putstr_fd.c ft_strjoin.c ft_strrchr.c\
	ft_isalnum.c ft_memdel.c ft_strcat.c ft_strlcat.c ft_strstr.c\
	ft_memmove.c ft_strchr.c ft_strlen.c ft_strsub.c\
	ft_isascii.c ft_memset.c ft_tolower.c\
	ft_isdigit.c ft_strcmp.c ft_min_max.c ft_numlen.c\
	ft_strcpy.c ft_strncat.c ft_strsplit.c\
	ft_strdel.c ft_memalloc.c get_next_line.c\
	ft_memccpy.c ft_putnbr.c \
	ft_strtrim.c ft_strarrdel.c ft_find_word.c ft_lstmap.c\
	ft_count_words.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
	ft_lstadd.c ft_lstiter.c ft_memdup.c\

PRINT_SRC = dispatch.c finish.c frac.c ft_ftoap.c ft_ldtoap.c\
			ft_ftoap.c ft_ldtoap.c ft_printf.c ft_vprintf.c\
			ftoa.c getarg.c ntoap.c padding.c parsing.c utils.c\

OBJ = $(LIB_SRC:%.c=%.o)		
PRINT_DIR = ft_printf/
PRINT_OBJ = $(PRINT_SRC:%.c=$(PRINT_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ) $(PRINT_OBJ)
	@echo "$(PURPLE)Compiling libft$(RESET)"
	ar rcs $(NAME) $(OBJ) $(PRINT_OBJ)
	@echo "$(GREEN)Libft ready!$(RESET)"

$(PRINT_DIR)%.o: %.c
	$(CC) $(FLAGS) $(PRINT_HEADER) $(LIB_HEADER) -c -o $@ $<

%.o: %.c
	$(CC) $(FLAGS) $(LIB_HEADER) -c -o $@ $<	

clean:
	@echo "$(RED)Deleting object files...$(RESET)"
	rm -f $(OBJ)
	rm -f $(PRINT_OBJ)
	@echo "$(GREEN)Libft clean!$(RESET)"

fclean: clean
	@echo "$(RED)Deleting executables...$(RESET)"
	rm -f $(NAME)
	@echo "$(GREEN)Libft fclean!$(RESET)"

re: fclean all

rebug: fclean debug

.PHONY: all so clean fclean re debug rebug libft

RED	= \033[0;31m
PURPLE = \033[0;35m
GREEN =	\033[0;32m
RESET = \033[0m