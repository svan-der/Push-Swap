/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 18:46:22 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/11 16:39:57 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;

	if (!lst && !f)
		return (0);
	current = f(lst);
	if (lst->next == NULL)
		return (current);
	current->next = ft_lstmap(lst->next, f);
	return (current);
}
