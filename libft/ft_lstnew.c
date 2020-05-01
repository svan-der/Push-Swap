/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 11:32:22 by svan-der       #+#    #+#                */
/*   Updated: 2019/12/21 17:09:34 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	if (!content)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = (void *)ft_memdup(content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}

int		ft_lstaddnew(t_list **head, const void *content, size_t content_size)
{
	t_list *newlist;

	newlist = ft_lstnew(content, content_size);
	if (!newlist)
		return (0);
	ft_lstadd(head, newlist);
	return (1);
}
