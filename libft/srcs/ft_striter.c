/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 11:54:41 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/11 16:45:21 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str2;

	i = 0;
	if (!s)
		return (NULL);
	str2 = ft_strdup((const char *)s);
	if (str2 == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str2[i] = f((unsigned char)i, str2[i]);
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str2;
	int		i;

	if (!s)
		return (NULL);
	str2 = ft_strdup((const char*)(s));
	i = 0;
	if (str2 == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str2[i] = (f)(s[i]);
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;

	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(i, s + i);
			i++;
		}
	}
}

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		while (*s != '\0')
		{
			f(s);
			s++;
		}
	}
}
