/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ldtoap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:54:16 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/25 19:25:30 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftoa.h"

static char		*make_flstr(char *str, t_dtoa *dtoa, t_ntoa *pref, size_t len)
{
	char	*digit;
	t_u128	val;
	t_i128	i;

	val = dtoa->int_val;
	digit = (pref->upper) ? HEX_UP : HEX;
	i = (len && dtoa->int_len > 1) ? dtoa->int_len + len - 1 : dtoa->int_len;
	i = (i == 0 || (i == (t_i128)dtoa->int_len && dtoa->neg)) ? i + 1 : i;
	if (val <= 0)
		str[i - 1] = '0';
	while (val)
	{
		i--;
		str[i] = digit[val % dtoa->base];
		val /= dtoa->base;
	}
	if (pref->sign && pref->pref)
		*str = *pref->sign;
	if (dtoa->dec)
		str = ft_addfrac(str, dtoa, pref);
	return (str);
}

static size_t	ft_dtoa_base(t_ldbl n, t_ldb value, t_uint base)
{
	size_t len;
	t_u128 val;

	len = 1;
	val = (t_u128)n;
	if (val == 0)
		val = value;
	if (val == 9)
	{
		n -= val;
		n *= 10;
		val = (t_u128)n;
		if (val == 9)
			len++;
	}
	while (val / base)
	{
		val /= base;
		len++;
	}
	return (len);
}

static char		*ft_ldtoa_base(char *astr, t_dtoa *dtoa, t_ntoa *pref, size_t i)
{
	t_ldbl	frac;
	int		base;

	base = dtoa->base;
	dtoa->ldb_val = ft_ldabs(dtoa->ldb_val);
	dtoa->frac = (dtoa->ldb_val - dtoa->int_val) * ft_pow(base, pref->prec + 1);
	frac = dtoa->ldb_val - dtoa->int_val;
	frac = (frac * 10);
	ft_round(frac, pref, dtoa);
	astr = make_flstr(astr, dtoa, pref, i);
	return (astr);
}

size_t			ft_ftoap(char **astr, t_dtoa *dtoa, t_ntoa *pref)
{
	t_ldbl	val;
	size_t	len[3];
	size_t	total;

	val = dtoa->ldb_val;
	if (!astr)
		return (-1);
	dtoa->neg = (pref->sign && pref->pref) ? 1 : 0;
	dtoa->int_val = (t_u128)ft_ldabs(dtoa->ldb_val);
	len[0] = (dtoa->dec + dtoa->neg);
	len[1] = ft_dtoa_base(val, dtoa->int_val, dtoa->base);
	len[2] = (pref->delimit) ? (len[1] / 3) - !(len[1] % 3) : 0;
	total = (len[0] + ft_max_size(pref->prec + len[1], len[1]) + len[2]);
	if (!*astr)
		if (!ft_strpnew(astr, total))
			return (-1);
	dtoa->int_len = len[1];
	dtoa->total = total;
	*astr = ft_ldtoa_base(*astr, dtoa, pref, len[0]);
	if (*astr != NULL)
		free(*astr);
	return (total);
}
