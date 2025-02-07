/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 12:27:49 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/12 14:03:13 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	l;
	char	*src;
	char	*dst;

	i = 0;
	l = 0;
	src = (char *)s2;
	dst = s1;
	while (dst[i] != '\0')
	{
		i++;
	}
	while (src[l] != '\0' && l < n)
	{
		dst[i] = src[l];
		i++;
		l++;
	}
	dst[i] = '\0';
	return (dst);
}
