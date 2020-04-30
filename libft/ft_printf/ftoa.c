/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftoa.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:03:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 11:56:36 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf/ftoa.h"
#include "../includes/list.h"

static int	check_sign(t_ldbl value)
{
	t_epf check;

	check.val = value;
	if ((check.dbl[4] >> 15) == -1)
		return (1);
	return (0);
}

t_list		ft_ldtoa(t_dtoa *dtoa, t_spec *spec, t_ntoa *pref)
{
	char	*str;
	int		ret;
	size_t	size;

	dtoa->base = 10;
	dtoa->ldb_val = spec->val.fl;
	str = NULL;
	ret = check_sign(dtoa->ldb_val);
	if (ret)
	{
		dtoa->neg = 1;
		pref->sign = "-";
		pref->pre = 1;
		if (!spec->flags.hash && !pref->zero)
			pref->pref = 1;
	}
	size = ft_ldtoap(&str, dtoa, pref, ret);
	return ((t_list){str, size, NULL});
}

t_list		ft_dtoa(t_dtoa *dtoa, t_spec *spec, t_ntoa *pref)
{
	char	*str;
	int		ret;
	size_t	size;

	str = NULL;
	dtoa->base = 10;
	dtoa->ldb_val = (t_ldbl)spec->val.fl;
	ret = check_sign(dtoa->ldb_val);
	if (ret)
	{
		dtoa->neg = 1;
		pref->sign = "-";
		pref->pre = 1;
		if (!spec->flags.hash && !pref->zero)
			pref->pref = 1;
	}
	size = ft_dtoap(&str, dtoa, pref, ret);
	return ((t_list){str, size, NULL});
}
