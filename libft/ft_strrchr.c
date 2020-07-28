/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:48:00 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/28 16:09:45 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
