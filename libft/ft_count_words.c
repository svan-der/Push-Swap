/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_words.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 16:03:05 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/12 13:55:38 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_count_words(char const *s, char c)
{
	size_t i;
	size_t word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word);
}
