/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_word.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 16:08:21 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/11 16:39:07 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find_word(char const *s, char c)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (ft_strsub(s, 0, i));
}
