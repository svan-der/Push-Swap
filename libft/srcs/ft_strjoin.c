/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 16:48:24 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/11 16:45:26 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnw;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	strnw = (char*)malloc(sizeof(char) * (len + 1));
	if (strnw == NULL)
		return (NULL);
	ft_strcpy(strnw, s1);
	ft_strcat(strnw, s2);
	return (strnw);
}
