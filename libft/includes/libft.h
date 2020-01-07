/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 16:38:44 by svan-der       #+#    #+#                */
/*   Updated: 2019/12/21 17:18:59 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "mathlib.h"
# include "libdefs.h"

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
void				ft_putnbr(int n);
void				ft_gridset(void **grid, char c, size_t y, size_t x);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strnew(size_t size);
int					ft_strpnew(char **str, size_t size);
int					ft_strcpnew(char **str, size_t size, char c);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memalloc(size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strdup(const char *s1);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_isdigit(int c);
int					ft_isdigit_base(char c, unsigned int base);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(const char *str, char c);
size_t				ft_strchrni(const char *str, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_itoa(int n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strrchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, unsigned int base);
int					ft_atoip(const char *str, int *dest);
int					ft_atoip_base(const char *str, unsigned int base,\
					int *dest);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strdel(char **as);
void				ft_strarrdel(char ***str, size_t size);
size_t				ft_count_words(char const *s, char c);
char				*ft_find_word(char const *s, char c);
int					ft_whitespace(char c);

#endif
