/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
<<<<<<< HEAD
/*   Created: 2019/12/10 14:19:09 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 11:53:19 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf/ft_printf.h"
=======
/*   Created: 2019/12/10 14:19:09 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/08 17:51:19 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf/ftoa.h"
#include "../includes/ft_printf/ntoa.h"
>>>>>>> parent of eb144b2... Modified Makefile and add README file

size_t		handle_invalid(char **astr, t_opt *inval, t_ntoa *pref, int ret)
{
	size_t	len;
	size_t	size;
	char	sign;

	sign = (pref->sign && (!inval->neg_inf || !ret)) ? '+' : '-';
	len = (pref->plus || inval->neg_inf || (pref->pref && pref->sign)) ? 1 : 0;
	size = (inval->nan || (inval->inf && !pref->sign)) ? 3 : 4;
	if (!*astr)
		if (!ft_strpnew(astr, size))
			return (-1);
	if (inval->nan)
		ft_memcpy(*astr, "nan", 3);
	else
	{
		ft_memcpy(*astr + len, "inf", 3);
		(len) ? ft_memcpy(*astr, &sign, 1) : 0;
	}
	if (pref->sign && pref->pref)
		astr[len] = pref->sign;
	if (*astr != NULL)
		free(*astr);
	return (size);
}

static int	check_ldbval(t_ldbl val, t_opt *inval)
{
	t_ldbl tmp;

	tmp = val;
	if (val != val)
		inval->nan = 1;
	if (val >= __LDBL_MAX__)
		inval->inf = 1;
	if (val <= -1 * __LDBL_MAX__)
		inval->neg_inf = 1;
	if (inval->nan || inval->inf || inval->neg_inf)
		return (1);
	return (0);
}

static int	check_dbval(double val, t_opt *inval)
{
	if (val != val)
		inval->nan = 1;
	if (val > __LDBL_MAX__)
		inval->inf = 1;
	if (val < -1 * __LDBL_MAX__)
		inval->neg_inf = 1;
	if (inval->nan || inval->inf || inval->neg_inf)
		return (1);
	return (0);
}

size_t		ft_dtoap(char **astr, t_dtoa *dtoa, t_ntoa *pref, int i)
{
	if (check_dbval(dtoa->ldb_val, &dtoa->inval))
		return (handle_invalid(astr, &dtoa->inval, pref, i));
	return (ft_ftoap(astr, dtoa, pref));
}

size_t		ft_ldtoap(char **astr, t_dtoa *dtoa, t_ntoa *pref, int i)
{
	if (check_ldbval(dtoa->ldb_val, &dtoa->inval))
		return (handle_invalid(astr, &dtoa->inval, pref, i));
	return (ft_ftoap(astr, dtoa, pref));
}
