/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 17:42:09 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/12 14:02:18 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*src;
	char	*dst;
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	src = (char*)s2;
	dst = s1;
	while (dst[i] != '\0')
		i++;
	while (src[l] != '\0')
	{
		dst[i] = src[l];
		i++;
		l++;
	}
	dst[i] = '\0';
	return (dst);
}
