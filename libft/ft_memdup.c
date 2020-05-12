/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 18:09:28 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/12 13:58:53 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_memdup(void const *content, size_t content_size)
{
	void *new;

	new = malloc(sizeof(unsigned char) * content_size);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, content, content_size);
	return (new);
}
