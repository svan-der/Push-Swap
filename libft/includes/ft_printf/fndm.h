/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fndm.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/12 15:28:18 by svan-der       #+#    #+#                */
/*   Updated: 2019/12/23 10:21:10 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FNDM_H
# define FNDM_H
# include "ft_printf.h"
# include <stdarg.h>
# include "ntoa.h"

/*
** conversion specifier union
*/

typedef struct	s_input
{
	char		c;
	char		*s;
	t_ull		p;
	t_llong		di;
	t_ull		oux;
	t_ldbl		fl;
}				t_input;

/*
** format string length modifiers
*/

typedef enum	e_mods
{
	null, h, hh, l, ll, L
}				t_mods;

typedef struct	s_flags
{
	int			hash;
	int			zero;
	int			min;
	int			space;
	int			plus;
	int			apos;
}				t_flags;

/*
** format string specifiers
*/

typedef struct	s_spec
{
	t_flags		flags;
	t_mods		mod;
	size_t		min_fw;
	int			prec;
	int			prec_set;
	char		c;
	char		*pref;
	int			pre;
	int			index;
	t_ldbl		ldb_reg;
	t_input		val;
}				t_spec;

/*
** format string struct
*/

typedef struct	s_format
{
	int			index;
	int			fd;
	size_t		argc;
	size_t		*max;
	t_list		*argv;
	t_list		*buffer;
}				t_format;

t_list			ft_minfw(int i, t_spec *spec, size_t len, t_ntoa *s);
void			insert_pad(char *str, int i, t_ntoa *pref, t_uint base);
void			insert_prefix(char *str, t_ntoa *pref, size_t *size, int i);
void			parse_flags(t_ntoa *pref, int i, t_spec *spec, t_flags *flag);
int				get_arg(int i, t_spec *spec, t_flags *flag, va_list ap);
int				print_buffer(t_list *buffer, int fd, char **astr, size_t size);
int				dispatch(t_list **tail, t_spec *spec, va_list ap);
int				process(t_format *fmt, const char *str, va_list ap);

#endif
