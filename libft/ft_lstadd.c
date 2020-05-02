/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 16:31:14 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/01 15:44:09 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
// #include "../includes/list.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst)
	{
		new->next = *alst;
		*alst = new;
	}
}
