/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ntoa.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 17:54:21 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:35:27 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NTOA_H
# define NTOA_H
# include "ft_printf.h"

typedef struct	s_ntoa
{
	t_uchar	space;
	size_t	padding;
	t_uchar	delimit;
	t_uchar	upper;
	t_uchar	min;
	t_uchar	pref;
	t_uchar	prec_set;
	t_uchar	zero;
	t_uchar	plus;
	char	*sign;
	char	*prefix;
	size_t	pre;
	int		prec;
}				t_ntoa;

char			*ft_utoa(t_ull n);
char			*ft_itoa_base(t_llong n, t_uint b);
char			*ft_utoa_base(t_ull n, t_uint b);
int				ft_itoap(char **a, t_llong n, t_ntoa *s);
int				ft_utoap(char **a, t_ull n, t_uint b, t_ntoa *s);
int				ft_itoap_base(char **a, t_llong n, t_uint b, t_ntoa *s);
int				ft_utoap_base(char **a, t_ull n, t_uint b, t_ntoa *s);
#endif
