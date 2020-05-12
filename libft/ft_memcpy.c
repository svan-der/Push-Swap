/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 12:56:39 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/12 13:58:43 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (i < n && src1 != NULL)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}
