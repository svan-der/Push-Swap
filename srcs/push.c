/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:51:18 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/10 11:50:31 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "psw_env.h"
#include <stdio.h>

int		swap_a(t_stack **stack_a)
{
	t_stack *temp;
	t_stack *new;

	new = *stack_a;
	if (new && new->next != NULL)
	{
		temp = new->next;
		new->prev = new->next;
		if (temp->next != NULL)
			temp->next->prev = new;
		new->next = temp->next;
		temp->next = new;
		new = temp;
		new->prev = NULL;
		*stack_a = new;
	}
	print_stack(*stack_a, 1);
	return (1);
}

int		swap_b(t_stack **stack_b)
{
	t_stack *temp;
	t_stack *new;

	new = *stack_b;
	if (new && new->next != NULL)
	{
		temp = new->next;
		new->prev = new->next;
		if (temp->next != NULL)
			temp->next->prev = new;
		new->next = temp->next;
		temp->next = new;
		new = temp;
		new->prev = NULL;
		*stack_b = new;
	}
	print_stack_b(*stack_b, 1);
	return (1);
}

int		swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack *temp1;

	temp = *stack_a;
	temp1 = *stack_b;
	printf("inside swap ss\n");
	if (temp != NULL && temp->next != NULL)
		swap_a(stack_a);
	if ((temp1 != NULL && temp1->next != NULL))
	{
		printf("in swap_b\n");
		swap_b(stack_b);
	}
	print_stack(*stack_a, 1);
	print_stack_b(*stack_b, 1);
	return (1);
}

/**
	the obective of this function is to take the first element of list A
	and plkace it to the biginning of list b

	stack a
	check if there are elements, stack_a is the 2nd node of stack_a,
	prev set back to when i am pushing NULL, next

	stack b
	the next of my "element" will be the entierty of list b
**/

int		push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *new_a;
	t_stack *new_b;

	new_a = *stack_a;
	new_b = *stack_b;
	if (new_a == NULL)
		return (0);
	printf("here push b\n\n");
	tmp = new_a->next;
	new_a->next = NULL;
	printf("in stack_a:|%d|\n", new_a->num);
	fill_stack_begin(&new_b, new_a->num);
	new_a = tmp;
	if (new_a && new_a->next != NULL)
		new_a->prev = NULL;
	*stack_a = new_a;
	*stack_b = new_b;
	print_stack_b(*stack_b, 1);
	print_stack(*stack_a, 1);
	return (1);
}

int		push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *new_a;
	t_stack *new_b;

	new_b = *stack_b;
	new_a = *stack_a;
	if (new_b == NULL)
		return (0);
	printf("here push b\n\n");
	tmp = new_b->next;
	new_b->next = NULL;
	printf("in stack_b:|%d|\n", new_b->num);
	fill_stack_begin(&new_a, new_b->num);
	new_b = tmp;
	if (new_b && new_b->next != NULL)
		new_b->prev = NULL;
	*stack_b = new_b;
	*stack_a = new_a;
	print_stack(*stack_a, 1);
	print_stack_b(*stack_b, 1);
	return (1);
}
