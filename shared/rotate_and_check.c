/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_and_check.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 15:11:05 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:37:17 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"

int		check_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	int		valid;

	temp = *stack_a;
	valid = 1;
	if (*stack_b != NULL)
		valid = 0;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->num > temp->next->num)
			valid = 0;
		temp = temp->next;
	}
	if (valid == 0)
		return (0);
	else
		return (1);
}

int		rotate_b(t_pw_var *stvar)
{
	t_stack *new;
	t_stack *temp;

	temp = (*stvar).stack_b;
	if (temp != NULL && temp->next != NULL)
	{
		new = (*stvar).stack_b->next;
		new->prev = NULL;
		while (temp->next)
			temp = temp->next;
		temp->next = (*stvar).stack_b;
		temp->next->prev = temp;
		(*stvar).stack_b->next = NULL;
		(*stvar).stack_b = new;
	}
	return (1);
}

int		rotate_a(t_pw_var *stvar)
{
	t_stack *new;
	t_stack *temp;

	temp = (*stvar).stack_a;
	if (temp != NULL && temp->next != NULL)
	{
		new = (*stvar).stack_a->next;
		new->prev = NULL;
		while (temp->next)
			temp = temp->next;
		temp->next = (*stvar).stack_a;
		temp->next->prev = temp;
		(*stvar).stack_a->next = NULL;
		(*stvar).stack_a = new;
	}
	return (1);
}
