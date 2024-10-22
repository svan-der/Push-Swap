/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 14:56:02 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/12 13:58:57 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*srcs;
	size_t			i;

	dest = (unsigned char*)dst;
	srcs = (unsigned char*)src;
	if (len > (size_t)dest - (size_t)srcs)
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			dest[i] = srcs[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = srcs[i];
			i++;
		}
	}
	return (dest);
}
