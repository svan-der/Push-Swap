/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 15:05:54 by svan-der       #+#    #+#                */
/*   Updated: 2019/12/21 17:14:38 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstpop(t_list **aparent, t_list *elem)
{
	t_list	*next;

	if (aparent && elem)
	{
		next = (*aparent)->next;
		if (*aparent == elem)
		{
			ft_lstdelone(aparent, content_del);
			*aparent = next;
		}
		else
			ft_lstpop(&(*aparent)->next, elem);
	}
}

void	content_del(void *content, size_t size)
{
	free(content);
	(void)size;
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		del((*alst)->content, (*alst)->content_size);
	}
	free(*alst);
	*alst = NULL;
}
