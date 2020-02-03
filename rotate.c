/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:15:26 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/03 18:01:22 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

t_stack	*reverse_list(t_stack **new)
{
	t_stack *tmp;
	t_stack *new_list;

	tmp = NULL;
	new_list = *new;
	if (new_list && !new_list->next)
		return (*new);
	// new_list->prev->next = NULL;
	while (new_list != NULL)
	{
		tmp = new_list->prev;
		new_list->prev = new_list->next;
		new_list->next = tmp;
		new_list = new_list->prev;
	}
	if (tmp != NULL)
		new = &tmp->prev;
	return (*new);
}

int		rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack *temp1;

	temp = (*stack_a);
	temp1 = (*stack_b);
	if (temp && temp->next)
	{
		printf("rotate_a on\n\n");
		rotate_a(stack_a);
	}
	if (temp1 && temp1->next)
	{
		printf("rotate_b on\n\n");
		rotate_b(stack_b);
	}
	return (1);
}

int		rotate_b(t_stack **stack_b)
{
	t_stack *new;
	t_stack *temp;

	if (*stack_b == NULL)
		return (0);
	new = (*stack_b)->next;
	new->prev = NULL;
	temp = (*stack_b);
	while (temp->next)
		temp = temp->next;
	temp->next = (*stack_b);
	temp->next->prev = temp;
	(*stack_b)->next = NULL;
	*stack_b = new;
	print_stack_b(*stack_b, 1);
	printf("\n");
	return (1);
}

int		rotate_revb(t_stack **stack_b)
{
	t_stack *temp;
	t_stack *new;

	if (*stack_b == NULL)
		return (0);
	new = *stack_b;
	temp = *stack_b;
	while (new->next->next != NULL)
		new = new->next;
	temp = new->next;
	new->next = NULL;
	temp->next = new->prev;
	temp->prev = NULL;
	if (temp->next)
		temp->next->prev = temp;
	if (!temp->next)
		temp->next = new;
	(*stack_b) = temp;
	print_stack_b(*stack_b, 1);
	printf("\n");
	return (1);
}

int		rotate_reva(t_stack **stack_a)
{
	t_stack *temp;
	t_stack *new;

	new = NULL;
	if (*stack_a == NULL)
		return (0);
	temp = *stack_a;
	while (temp->next->next)
		temp = temp->next;
	temp = temp->next;
	new = temp->prev;
	temp->prev = NULL;
	while (new->next->next)
	{
		new = new->next;
	}
	new->prev = NULL;
	// (*stack_a)->prev = new;
	new->next = *stack_a;
	*stack_a = new;
	temp->next = NULL;
	print_stack(*stack_a, 1);
	printf("\n");
	return (1);
}

int		rotate_a(t_stack **stack_a)
{
	t_stack *new;
	t_stack *temp;

	if (*stack_a == NULL)
		return (0);
	new = (*stack_a)->next;
	new->prev = NULL;
	temp = (*stack_a);
	while (temp->next)
		temp = temp->next;
	temp->next = (*stack_a);
	temp->next->prev = temp;
	(*stack_a)->next = NULL;
	*stack_a = new;
	print_stack(*stack_a, 1);
	printf("\n");
	return (1);
}
