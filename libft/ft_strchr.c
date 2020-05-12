/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 11:43:40 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/12 14:02:24 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char*)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

int		ft_strchri(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strchrni(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
