/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 09:51:25 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/15 19:11:15 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcpnew(char **str, size_t size, char c)
{
	if (!ft_strpnew(str, size))
		return (0);
	ft_memset(*(void**)str, c, size);
	return (1);
}

int		ft_strpnew(char **str, size_t size)
{
	*str = ft_strnew(size);
	return (!!*str);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)(malloc(size + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
