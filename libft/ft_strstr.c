/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:22:49 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/24 20:07:00 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t l;

	i = 0;
	l = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		l = 0;
		while (needle[l] == haystack[i + l] && i + l < len)
		{
			if (needle[l + 1] == '\0')
				return ((char*)haystack + i);
			l++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		l = 0;
		while (needle[l] == haystack[i + l])
		{
			if (needle[l + 1] == '\0')
				return ((char*)haystack + i);
			l++;
		}
		i++;
	}
	return (NULL);
}
