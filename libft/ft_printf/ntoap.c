/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ntoap.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/22 17:57:12 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/12 17:07:07 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	make(char *str, t_ull n, t_uint base, t_ntoa *pref)
{
	char	*digit;
	int		i;

	digit = (pref->upper) ? HEX_UP : HEX;
	i = -(n == 0);
	if (n == 0)
		if (!pref->prefix || (pref->prefix && pref->pref))
			if ((pref->prec > 0 && pref->prec_set) || !pref->prec_set)
				str[-1] = '0';
	if (base == 1)
		ft_memset(str - n, '1', n);
	else
		while (n)
		{
			i--;
			if ((-i % 3 == 1) && i < -3 && pref->delimit)
			{
				str[i] = ',';
				str--;
			}
			str[i] = digit[n % base];
			n /= base;
		}
	insert_pad(str, i, pref, base);
}

void	make_signstr(char *str, t_llong n, t_uint base, t_ntoa *pref)
{
	char	*digit;
	int		i;

	n = (n < 0) ? -n : n;
	digit = (pref->upper) ? HEX_UP : HEX;
	i = -(n == 0);
	if (n == 0)
		str[-1] = '0';
	else
		while (n)
		{
			i--;
			if ((-i % 3 == 1) && i < -3 && pref->delimit)
			{
				str[i] = ',';
				str--;
			}
			str[i] = digit[n % base];
			n /= base;
		}
	insert_pad(str, i, pref, base);
}

int		ft_itoap_base(char **argv, t_llong n, t_uint base, t_ntoa *pref)
{
	size_t	len[3];
	size_t	total;
	char	max;

	max = (n < -1 * (__LONG_LONG_MAX__) || n > (__LONG_LONG_MAX__)) ? 1 : 0;
	len[0] = (pref->pref && pref->sign) ? 1 : 0;
	len[1] = (max != 1) ? ft_count_num(n) : ft_numlen_base(n, 10);
	if (!len[1])
		return (0);
	len[2] = (pref->delimit) ? (len[1] / 3) - !(len[1] % 3) : 0;
	total = (len[0] + ft_max_size(pref->prec, len[1]) + len[2]);
	if (!*argv)
		if (!ft_strpnew(argv, total))
			return (-1);
	if (max)
		make(*argv + total, n, base, pref);
	if (!max)
		make_signstr(*argv + total, n, base, pref);
	if (pref->pref && pref->sign)
		*argv[0] = *pref->sign;
	return (total);
}

int		ft_utoap_base(char **argv, t_ull n, t_uint base, t_ntoa *pref)
{
	size_t	len[3];
	size_t	total;

	len[1] = ft_numlen_base(n, base);
	if (!len[1])
		return (0);
	len[0] = pref->pref ? pref->pre : 0;
	len[0] = (len[0] == 1 && ((size_t)pref->prec > len[1])) ? 0 : len[0];
	len[2] = (pref->delimit) ? (len[1] / 3) - !(len[1] % 3) : 0;
	total = len[0] + ft_max_size(pref->prec, len[1]) + len[2];
	if (!*argv)
		if (!ft_strpnew(argv, total))
			return (error_handler(-1));
	make(*argv + total, n, base, pref);
	if (pref->pref && (pref->pre == 2 || pref->pre == 3))
		ft_memcpy(*argv, pref->prefix, len[0] + 1);
	return (total);
}
