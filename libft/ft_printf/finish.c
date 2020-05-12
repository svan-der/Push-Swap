/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finish.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 15:53:26 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/12 14:16:54 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** writes output from the buffer
*/

int		print_buffer(t_list *buffer, int fd, char **astr, size_t size)
{
	size_t	len;
	int		ret;

	if (!buffer && astr)
		if (!(*astr))
			if (!ft_strpnew(astr, size))
				return (-1);
	if (!buffer)
		return (0);
	len = buffer->content_size;
	ret = print_buffer(buffer->next, fd, astr, size + len);
	if (!astr)
		write(fd, buffer->content, len);
	else if (ret != -1)
		ft_memcpy(*astr + ret, buffer->content, len);
	if (buffer->content != NULL)
		free(buffer->content);
	if (buffer != NULL)
		free(buffer);
	return ((ret != -1) ? (signed)(ret + len) : -1);
}
