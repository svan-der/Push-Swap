# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svan-der <svan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/11 15:22:00 by svan-der      #+#    #+#                  #
#    Updated: 2020/06/02 17:35:28 by svan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
INCL = ../includes/
PRINTF_DIR = ft_printf
LIB_OBJDIR = objects
PRINTF_OBJDIR = ft_printf/objects
# AR = $(Push_swap)/bin/libft.a-ar
# RANLIB = $(Push_swap)/bin/libft.a-ranlib

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
	ft_memccpy.c ft_putnbr.c ft_intround.c ft_memdup.c\
	ft_strtrim.c ft_strarrdel.c ft_find_word.c ft_lstmap.c\
	ft_count_words.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
	ft_lstadd.c ft_lstiter.c\

PRINTF_SRC = dispatch.c finish.c frac.c ft_ftoap.c ft_ldtoap.c\
			ft_printf.c ft_vprintf.c ftoa.c getarg.c ntoap.c\
			padding.c parsing.c utils.c\

LIB_OBJ = $(LIB_SRC:%.c=$(LIB_OBJDIR)/%.o)
PRINTF_OBJ = $(PRINTF_SRC:%.c=$(PRINTF_OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(LIB_OBJ) $(PRINTF_OBJ)
	ar -rcs $(NAME) $(LIB_OBJ) $(PRINTF_OBJ)

$(LIB_OBJDIR)/%.o: %.c $(INCL)
	@mkdir -p $(LIB_OBJDIR)
	@$(CC) -c -o $@ $<
	@$(CC) $(CFLAGS) -c -o $@ $<

$(PRINTF_OBJDIR)/%.o: $(PRINTF_DIR)/%.c $(INCL)
	@mkdir -p $(PRINTF_OBJDIR)
	@$(CC) -c -o $@ $<
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(LIB_OBJDIR)
	@rm -rf $(PRINTF_OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
