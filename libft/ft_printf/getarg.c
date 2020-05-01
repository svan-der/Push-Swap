/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getarg.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
<<<<<<< HEAD
/*   Created: 2019/12/21 18:34:50 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 12:14:15 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf/ft_printf.h"
=======
/*   Created: 2019/12/21 18:34:50 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/08 17:50:06 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf/ft_printf.h"
>>>>>>> parent of eb144b2... Modified Makefile and add README file

static int	get_flarg(t_spec *spec, char c, va_list ap)
{
	if (c == 'f')
	{
		if (spec->mod == L)
			spec->val.fl = va_arg(ap, t_ldb);
		else
			spec->val.fl = (t_ldb)va_arg(ap, double);
	}
	return (1);
}

static int	get_strarg(t_spec *spec, char c, va_list ap)
{
	if (c == 'c')
		spec->val.c = va_arg(ap, int);
	if (c == 's')
		spec->val.s = va_arg(ap, char *);
	if (c == 'p')
		spec->val.p = va_arg(ap, unsigned long long);
	return (1);
}

static int	get_uint_arg(t_spec *spec, va_list ap, t_flags *flag)
{
	t_llong val;
	int		prec_set;

	prec_set = spec->prec_set;
	if (spec->mod == l)
		val = va_arg(ap, unsigned long);
	else if (spec->mod == ll)
		val = va_arg(ap, unsigned long long);
	else if (spec->mod == hh)
		val = (unsigned char)va_arg(ap, int);
	else if (spec->mod == h)
		val = (unsigned short int)va_arg(ap, int);
	else
		val = va_arg(ap, unsigned int);
	spec->val.oux = val;
	if (spec->val.oux == 0)
		if (spec->min_fw <= 0)
		{
			if (prec_set == 1 && spec->prec <= 0 && !flag->hash)
				return (0);
			if (prec_set == 1 && spec->prec <= 0 && !flag->hash)
				return (0);
		}
	return (1);
}

static int	get_int_arg(t_spec *spec, va_list ap)
{
	t_llong val;
	int		prec_set;

	prec_set = spec->prec_set;
	if (spec->mod == l)
		val = va_arg(ap, long);
	else if (spec->mod == ll)
		val = va_arg(ap, t_llong);
	else if (spec->mod == hh)
		val = (signed char)va_arg(ap, int);
	else if (spec->mod == h)
		val = (short int)va_arg(ap, int);
	else
		val = va_arg(ap, int);
	spec->val.di = val;
	if (spec->val.di == 0 && prec_set && spec->prec <= 0 && spec->min_fw <= 0)
		return (0);
	return (1);
}

int			get_arg(int i, t_spec *spec, t_flags *flag, va_list ap)
{
	int prec_set;

	prec_set = spec->prec_set;
	if (i < 4)
		return (get_strarg(spec, spec->c, ap));
	if (i == 4 || i == 5)
		return (get_int_arg(spec, ap));
	if (i > 9)
		return (get_flarg(spec, spec->c, ap));
	else
		return (get_uint_arg(spec, ap, flag));
}
