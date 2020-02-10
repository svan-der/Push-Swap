/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftoa.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:11:54 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/08 17:21:10 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTOA_H
# define FTOA_H
# include "../libft.h"
# include "../mathlib.h"
# include "fndm.h"
# include "ntoa.h"

typedef struct	s_opt
{
	t_uchar		nan;
	t_uchar		inf;
	t_uchar		neg_inf;
	t_uchar		plus;
}				t_opt;

typedef struct	s_dtoa
{
	t_opt		inval;
	t_u128		frac;
	t_u128		int_val;
	t_ldb		ldb_val;
	t_uint		total;
	t_u128		int_len;
	size_t		len;
	t_uchar		even;
	t_uchar		dec;
	t_uchar		neg;
	t_uint		base;
}				t_dtoa;

typedef union	u_epf
{
	t_ldbl		val;
	short		dbl[5];
}				t_epf;

char			*ft_addfrac(char *str, t_dtoa *dtoa, t_ntoa *pref);
void			ft_round(t_ldb frac, t_ntoa *pref, t_dtoa *dtoa);
size_t			ft_ldtoap(char **astr, t_dtoa *dtoa, t_ntoa *pref, int i);
size_t			ft_dtoap(char **astr, t_dtoa *dtoa, t_ntoa *pref, int i);
size_t			ft_ftoap(char **astr, t_dtoa *dtoa, t_ntoa *pref);
t_list			ft_ldtoa(t_dtoa *dtoa, t_spec *spec, t_ntoa *pref);
t_list			ft_dtoa(t_dtoa *dtoa, t_spec *spec, t_ntoa *pref);
size_t			handle_invalid(char **astr, t_opt *inval, t_ntoa *pref, int i);
#endif
