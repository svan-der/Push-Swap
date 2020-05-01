/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frac.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/22 01:29:46 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/01 12:39:24 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	check_five(t_ldbl val, t_ull i, int x, int round)
{
	int	bank;

	x = (i == 5 && x == 0) ? 500 : x;
	x = (i == 5 && x != 500) ? x + 1 : x;
	bank = (x == 500) ? 1 : 0;
	while (x)
	{
		val = val - i;
		i = i / 10;
		val *= 10;
		i = (int)val;
		if (i > 0 && bank)
			round = -1;
		x--;
	}
	if (i > 4)
		round = 1;
	return (round);
}

static int	frac_calc(t_ldbl *value, t_ull *i, int x, int *nine)
{
	t_ldbl	val;
	int		round;
	int		prec;

	round = 0;
	prec = x;
	val = *value;
	while (x)
	{
		if (*i == 9)
			*nine += 1;
		x -= 1;
		val -= *i;
		*i = *i / 10;
		val = (val * 10);
		*i = (t_ull)val;
		if (x == 1 && *i >= 5)
			round = check_five(val, *i, x, round);
		x = (*nine == prec && x == 0 && *i == 9) ? 1 : x;
		x = (*value > MAX_UINT && x == 0) ? 1 + round : x;
	}
	if (*i == 9)
		round = 1;
	*value = val;
	return (round);
}

char		*ft_addfrac(char *str, t_dtoa *dtoa, t_ntoa *pref)
{
	int		i;
	t_uint	x;
	t_u128	val;
	size_t	total;
	char	*digit;

	x = (dtoa->neg) ? 1 : 0;
	total = dtoa->int_len + x;
	digit = (pref->upper) ? HEX_UP : HEX;
	i = dtoa->total - 1;
	val = dtoa->frac;
	x = pref->prec;
	while (x)
	{
		str[i] = digit[val % dtoa->base];
		val /= dtoa->base;
		x--;
		i--;
	}
	if (val == 0 && x != 0)
		ft_memset(str + total, '0', pref->prec);
	i = total;
	if (dtoa->dec)
		str[i] = '.';
	return (str);
}

static void	frac_sum(int prec, t_dtoa *dtoa, int nine, int round)
{
	t_ull i;

	dtoa->frac /= 10;
	i = dtoa->len;
	if (round && prec > 0)
	{
		if (i % 10 != 0)
			dtoa->frac += 1;
		dtoa->frac = (t_u128)dtoa->frac;
		i = (t_ull)dtoa->frac;
		if (i % 10 == 0 && nine >= prec)
			dtoa->int_val += 1;
	}
}

void		ft_round(t_ldbl frac, t_ntoa *pref, t_dtoa *dtoa)
{
	int		x;
	t_ull	i;
	int		round;
	int		nine;
	t_u128	int_val;

	int_val = dtoa->int_val;
	nine = 0;
	round = 0;
	x = (pref->prec < 0) ? 0 : pref->prec;
	i = (t_ull)frac;
	if (i == 5 && pref->prec == 0)
	{
		dtoa->even = (int_val % 2 == 0) ? 1 : 0;
		round = check_five(frac, i, x, round);
	}
	round = frac_calc(&frac, &i, x, &nine);
	round = (i > 4 && !dtoa->even) ? 1 : round;
	dtoa->int_val = (round == -1 && i % 2 == 0) ? int_val - 1 : int_val;
	dtoa->int_val = (pref->prec == 0 && round) ? int_val + 1 : int_val;
	x = i;
	i = (t_ull)dtoa->frac;
	dtoa->len = (x > 0 && x != 9) ? x : i;
	frac_sum(pref->prec, dtoa, nine, round);
	dtoa->frac = (t_u128)dtoa->frac;
}
