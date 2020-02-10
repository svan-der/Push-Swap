/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/28 10:53:12 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/11 16:39:25 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libdefs.h"

int		ft_isdigit_base(char c, unsigned int base)
{
	if (c < 0 || base == 0 || base > 16)
		return (0);
	if (base == 1)
		return (c == '1');
	return (!!ft_memchr(HEX, c, base));
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
