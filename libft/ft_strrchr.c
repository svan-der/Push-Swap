/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:48:00 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/11 16:45:49 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;

	str = (char*)s;
	if (ft_strchr(str, c) == NULL)
		return (NULL);
	while (*str)
	{
		str++;
	}
	while (*str != c)
	{
		str--;
	}
	return (str);
}
