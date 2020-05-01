/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
<<<<<<< HEAD
/*   Created: 2019/12/21 18:06:51 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 12:19:53 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf/ft_printf.h"
=======
/*   Created: 2019/12/21 18:06:51 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/08 17:50:26 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf/ft_printf.h"
>>>>>>> parent of eb144b2... Modified Makefile and add README file

static t_list	ft_cspad(int i, t_spec *spec, size_t total, t_ntoa *pref)
{
	size_t	pre;
	size_t	size;
	size_t	len;
	char	*pad;

	pad = NULL;
	pre = (spec->c == 'p' && !pref->pref) ? pref->pre : 0;
	size = (total < spec->min_fw && spec->min_fw) ? spec->min_fw - total : pre;
	if (!size)
		return ((t_list){pad, size, NULL});
	pad = ft_strnew(size);
	if (spec->min_fw != 0)
		ft_memset(pad, " 0"[i], size);
	len = (size != 0) ? size - pre : 0;
	if (spec->c == 'p' && !spec->val.p)
		ft_memcpy(pad + len, pref->prefix, pref->pre);
	if (spec->c == 'p' && !pref->min && spec->val.p)
	{
		if (!pref->min)
			len = (size != 0) ? size - pre : 0;
		ft_memcpy(pad + len, pref->prefix, pref->pre);
	}
	if (pad != NULL)
		free(pad);
	return ((t_list){pad, size, NULL});
}

static t_list	ft_intpad(int i, t_spec *spec, size_t total, t_ntoa *pref)
{
	size_t	size;
	size_t	len;
	char	*pad;
	size_t	padding;

	i = pref->zero && !pref->min && (spec->prec < 0);
	padding = spec->min_fw;
	pad = NULL;
	len = 0;
	size = (total < padding && padding) ? padding - total : 0;
	size = (size == 0 && pref->pre && !pref->pref) ? pref->pre : size;
	if (!size)
		return ((t_list){pad, size, NULL});
	pad = ft_strnew(size);
	if (padding != 0)
		ft_memset(pad, " 0"[i], size);
	if (pref->sign && (!pref->pref || (pref->pref && total == 0)))
	{
		len = (i == 0 && !pref->min) ? size - 1 : 0;
		ft_memcpy(pad + len, pref->sign, 1);
	}
	size = (size == (size_t)pref->pre) ? 1 : size;
	if (pad != NULL)
		free(pad);
	return ((t_list){pad, size, NULL});
}

static t_list	ft_uintpad(int i, t_spec *spec, size_t total, t_ntoa *pref)
{
	size_t	size;
	size_t	pad_len;
	size_t	len;
	char	*pad;
	size_t	padding;

	i = pref->zero && !pref->min && (spec->prec < 0);
	padding = spec->min_fw;
	pad = NULL;
	len = 0;
	size = (total < padding && padding) ? padding - total : 0;
	size = (size == 0 && pref->pre && !pref->pref) ? pref->pre : size;
	pad_len = size;
	if (!size)
		return ((t_list){pad, size, NULL});
	pad = ft_strnew(size);
	if (padding != 0)
		ft_memset(pad, " 0"[i], size);
	insert_prefix(pad, pref, &size, i);
	size = (size == (size_t)pref->pre) ? pref->pre : size;
	if (pad != NULL)
		free(pad);
	return ((t_list){pad, size, NULL});
}

static t_list	ft_fltpad(int i, t_spec *spec, size_t total, t_ntoa *pref)
{
	size_t	size;
	size_t	len;
	size_t	padding;
	char	*pad;

	pad = NULL;
	padding = spec->min_fw;
	len = 0;
	size = (total < padding && padding) ? padding - total : 0;
	size = (size == 0 && pref->pre && !pref->pref) ? pref->pre : size;
	if (!size)
		return ((t_list){pad, size, NULL});
	pad = ft_strnew(size);
	if (padding != 0)
		ft_memset(pad, " 0"[i], size);
	if (pref->sign && (!pref->pref || (pref->pref && total == 0)))
	{
		len = (i == 0 && !pref->min) ? size - 1 : 0;
		ft_memcpy(pad + len, pref->sign, 1);
	}
	size = (size == (size_t)pref->pre) ? 1 : size;
	if (pad != NULL)
		free(pad);
	return ((t_list){pad, size, NULL});
}

t_list			ft_minfw(int index, t_spec *spec, size_t total, t_ntoa *pref)
{
	static t_list	(*f[])(int, t_spec*, size_t, t_ntoa*) = \
	{ft_cspad, ft_cspad, ft_cspad, ft_cspad, ft_intpad, ft_intpad,\
	ft_uintpad, ft_uintpad, ft_uintpad, ft_uintpad, ft_fltpad, ft_fltpad};
	t_list			padding;
	int				i;

	i = pref->zero && !pref->min;
	padding = f[index](i, spec, total, pref);
	if (padding.content_size)
		return (padding);
	return ((t_list){NULL, 0, NULL});
}
