/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 14:23:36 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/12 13:58:30 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*s11 != *s22)
			return (*s11 - *s22);
		s11++;
		s22++;
		i++;
	}
	return (0);
}
