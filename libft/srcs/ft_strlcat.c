/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 15:45:13 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/11 16:45:33 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	deslen;
	size_t	srclen;

	i = 0;
	k = 0;
	deslen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= deslen)
		return (srclen + size);
	while ((dst[i] != '\0') && i < (size - 1))
		i++;
	while ((src[k]) && i < (size - 1))
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (deslen + srclen);
}
