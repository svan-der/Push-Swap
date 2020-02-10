/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 13:42:55 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/08 17:50:32 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf/ft_printf.h"

static void		ft_prefix(t_ntoa *pref, t_ull val, t_spec *spec)
{
	pref->pref = (!val && !pref->min) ? 0 : 1;
	if (spec->c == 'X' || spec->c == 'x')
	{
		if (spec->c == 'x' && val)
			pref->prefix = "0x";
		if (spec->c == 'X' && val)
			pref->prefix = "0X";
		if (pref->zero && pref->padding)
			pref->pref = 0;
	}
	if (spec->c == 'o')
	{
		if (val != 0 || (!val && spec->prec <= 0 && pref->prec_set))
			pref->prefix = "0";
		if (val == 0 && spec->prec <= 0 && pref->prec_set)
			pref->pref = 0;
	}
	if (spec->c == 'p')
	{
		pref->pref = (pref->min || spec->val.p == 0) ? 1 : 0;
		pref->prefix = "0x";
	}
	pref->pre = (pref->prefix) ? ft_strlen(pref->prefix) : 0;
}

static void		ft_spsign(t_ntoa *pref, t_input *val, t_flags *flag, int i)
{
	char	*sign;
	int		neg;
	t_llong int_val;
	t_ldb	value;
	int		padding;

	padding = pref->padding;
	neg = 0;
	int_val = val->di;
	value = val->fl;
	pref->pref = (!pref->min && ((!value && !i) || (!int_val && i))) ? 0 : 1;
	neg = ((int_val < 0 && i) || (value < 0 && !i)) ? 1 : 0;
	sign = "+- ";
	if (flag->plus || (neg && !i) || int_val < 0)
		pref->sign = (flag->plus && !neg) ? &sign[0] : &sign[1];
	if (!flag->plus && flag->space && !neg)
		pref->sign = &sign[2];
	pref->pref = (pref->sign && pref->zero && padding != 0) ? 0 : pref->pref;
	pref->pre = (pref->sign) ? 1 : 0;
}

void			parse_flags(t_ntoa *pref, int sign, t_spec *spec, t_flags *flag)
{
	if (spec->min_fw)
		pref->padding = spec->min_fw;
	if (spec->min_fw < 0)
	{
		pref->padding = spec->min_fw * -1;
		pref->min = 1;
	}
	if (!flag->min && !pref->min && flag->zero)
		pref->zero = 1;
	if (flag->min)
		pref->min = 1;
	if (sign && flag->apos)
		pref->delimit = 1;
	if (sign || spec->c == 'f' || spec->c == 'F')
		ft_spsign(pref, &spec->val, flag, sign);
	if (!pref->sign && flag->space && spec->val.di >= 0)
		pref->space = 1;
	if (spec->prec_set)
		pref->prec_set = 1;
	if (spec->prec != -1 && spec->prec_set)
		pref->prec = (size_t)spec->prec;
	if ((!sign && spec->c != 'f' && flag->hash) || spec->c == 'p')
		ft_prefix(pref, spec->val.oux, spec);
	if (spec->c == 'X' || spec->c == 'F')
		pref->upper = 1;
}

void			insert_prefix(char *str, t_ntoa *pref, size_t *size, int i)
{
	size_t len;
	size_t total;

	total = *size;
	len = 0;
	if ((pref->pre == 1 && (!pref->pref)) || (pref->pref && total == 0))
	{
		len = (i == 0 && !pref->min) ? *size - 1 : 0;
		ft_memcpy(str + len, pref->prefix, 1);
	}
	else if (pref->pre == 2 && (!pref->pref || (pref->pref && total == 0)))
	{
		len = (i == 0 && !pref->min) ? *size - 2 : 0;
		ft_memcpy(str + len, pref->prefix, 2);
	}
}

void			insert_pad(char *str, int i, t_ntoa *pref, t_uint base)
{
	int		padding;
	int		len;

	padding = pref->prec;
	len = (i < 0) ? i * -1 : i;
	padding = (padding && (padding - len > 0)) ? padding - len : 0;
	if (padding == 0 && base == 8)
		padding = (pref->pref && pref->pre == 1 && str[i] != 0) ? pref->pre : 0;
	if (padding != 0)
		ft_memset(str + i - padding, '0', padding);
}
