/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 16:31:14 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/11 17:15:59 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst)
	{
		new->next = *alst;
		*alst = new;
	}
}
