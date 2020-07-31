/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dispatch.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/17 11:35:10 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/29 16:16:09 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/fndm.h"

/*
** processes float arguments
*/

static t_list	print_float(char c, t_spec *spec, t_ntoa *pref, char **argv)
{
	t_dtoa		dtoa;

	ft_memset(&dtoa, 0, sizeof(dtoa));
	if (c == 'f')
	{
		if (spec->prec == 0)
			pref->prec_set = 0;
		else
			pref->prec_set = 1;
	}
	pref->prec = (spec->prec == -1 && !spec->prec_set) ? 6 : spec->prec;
	dtoa.dec = (spec->flags.hash || pref->prec > 0) ? 1 : 0;
	if (spec->mod == L)
		return (ft_ldtoa(argv, &dtoa, spec, pref));
	return (ft_dtoa(argv, &dtoa, spec, pref));
}

/*
** processes integer arguments
*/

static t_list	print_dioux(char c, t_spec *spec, t_ntoa *pref, char **argv)
{
	size_t			size;
	t_uint			base;

	if (c == 'd' || c == 'i')
	{
		if (pref->prec_set && spec->prec <= 0 && spec->val.di == 0)
			return ((t_list){NULL, 0, NULL});
		size = ft_itoap_base(argv, spec->val.di, 10, pref);
	}
	else
	{
		if (pref->prec_set && spec->prec <= 0 && spec->val.oux == 0)
			return ((t_list){NULL, 0, NULL});
		if (spec->index == 6)
			base = 8;
		if (spec->index == 7)
			base = 10;
		if (spec->index == 8 || spec->index == 9)
			base = 16;
		size = ft_utoap_base(argv, spec->val.oux, base, pref);
	}
	return ((t_list){*argv, size, NULL});
}

/*
** processes string arguments
*/

static t_list	print_csp(char c, t_spec *spec, t_ntoa *pref, char **argv)
{
	size_t		size;

	if (c == 'c' || (c == '%' && spec->index == 3))
	{
		size = 1;
		*argv = ft_strnew(size);
		*argv = ft_memset(*argv, spec->val.c, 1);
	}
	if (c == 's')
	{
		size = ft_strlen(spec->val.s);
		size = (pref->prec_set) ? ft_min_size(size, pref->prec) : size;
		*argv = ft_strnew(size);
		if (spec->val.s)
			*argv = ft_memcpy(*argv, spec->val.s, size);
		else
			*argv = ft_memcpy(*argv, "(null)", 7);
	}
	if (c == 'p')
		size = ft_utoap_base(argv, spec->val.p, 16, pref);
	return ((t_list){*argv, size, NULL});
}

static int		add(t_list *ret, t_spec *spec, t_list **tail, t_ntoa *pref)
{
	size_t content_size;

	if (!ret[0].content && spec->min_fw <= 0)
		if ((spec->flags.hash && spec->c != 'o') || (!pref->pre))
			return (0);
	if (!ret[0].content)
	{
		ret[0] = ft_minfw(spec->index, spec, ret[0].content_size, pref);
		return (ft_lstaddnew(tail, ret[0].content, ret[0].content_size));
	}
	if (ret[0].content)
		ft_lstaddnew(tail, ret[0].content, ret[0].content_size);
	!spec->flags.min && ret[0].content ? tail = &(*tail)->next : 0;
	content_size = ret[0].content_size;
	ret[1] = ft_minfw(spec->index, spec, ret[0].content_size, pref);
	if (ret[1].content_size != 0)
		return (ft_lstaddnew(tail, ret[1].content, ret[1].content_size));
	return (content_size >= spec->min_fw);
}

/*
** searches and executes corresponding function of the conversion specifier
** saves the address and value of the argument in val variable
*/

int				dispatch(t_list **tail, t_spec *spec, va_list ap, char **argv)
{
	static t_list	(*const f[])(char, t_spec*, t_ntoa*, char**) = \
	{print_csp, print_csp, print_csp, print_csp, print_dioux, print_dioux,
	print_dioux, print_dioux, print_dioux, print_dioux, print_float};
	t_ntoa			pref;
	t_flags *const	flag = &spec->flags;
	t_list			ret[2];
	int				rets;

	ft_memset(&pref, 0, sizeof(pref));
	*argv = NULL;
	spec->index = ft_strchri("csp%diouxXf", spec->c);
	if (spec->index == -1)
		return (-1);
	if (!get_arg(spec->index, spec, flag, ap)\
		&& (spec->min_fw <= 0 && !flag->space && !flag->plus))
		return (0);
	parse_flags(&pref, (spec->index == 4 || spec->index == 5), spec, flag);
	ret[0] = f[spec->index](spec->c, spec, &pref, argv);
	rets = add(ret, spec, tail, &pref);
	if (*argv != NULL)
		ft_strdel(argv);
	if (spec->pad_str != NULL)
		ft_strdel(&spec->pad_str);
	return (rets);
}
