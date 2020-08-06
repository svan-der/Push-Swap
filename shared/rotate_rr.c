/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_rr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:15:26 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:16:09 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"

int		rotate_rrr(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *temp1;

	temp = stvar->stack_a;
	temp1 = stvar->stack_b;
	if (temp != NULL && temp->next != NULL)
		rotate_reva(stvar);
	if (temp1 != NULL && temp1->next != NULL)
		rotate_revb(stvar);
	return (1);
}

int		rotate_rr(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *temp1;

	temp = stvar->stack_a;
	temp1 = stvar->stack_b;
	if (temp != NULL && temp->next != NULL)
		rotate_a(stvar);
	if (temp1 != NULL && temp1->next != NULL)
		rotate_b(stvar);
	return (1);
}

int		rotate_revb(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *new;

	new = stvar->stack_b;
	if (new != NULL && new->next != NULL)
	{
		while (new->next->next != NULL)
			new = new->next;
		temp = new->next;
		new->next = NULL;
		while (new->prev != NULL)
			new = new->prev;
		new->prev = temp;
		temp->next = new;
		temp->prev = NULL;
		stvar->stack_b = temp;
	}
	return (1);
}

int		rotate_reva(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *new;

	new = (*stvar).stack_a;
	if (new != NULL && new->next != NULL)
	{
		while (new->next->next != NULL)
			new = new->next;
		temp = new->next;
		new->next = NULL;
		while (new->prev != NULL)
			new = new->prev;
		new->prev = temp;
		temp->next = new;
		temp->prev = NULL;
		(*stvar).stack_a = temp;
	}
	return (1);
}
