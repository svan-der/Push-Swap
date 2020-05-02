/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 18:46:22 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/01 15:42:20 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
// #include "../includes/list.h"

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
