/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:51:18 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/09 17:43:35 by svan-der      ########   odam.nl         */
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
		printf("sort list:|%d|\n", temp->num);
		new->next = temp->next;
		printf("sort list:|%d|\n", new->num);
		temp->next = new;
		printf("sort list:|%d|\n", temp->num);
		new = temp;
		new->prev = NULL;
		printf("sort list:|%d|\n", new->num);
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
		printf("sort list:|%d|\n", temp->num);
		new->next = temp->next;
		printf("sort list:|%d|\n", new->num);
		temp->next = new;
		printf("sort list:|%d|\n", temp->num);
		new = temp;
		new->prev = NULL;
		printf("sort list:|%d|\n", new->num);
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

int		push_b(t_stack *stack_a, t_stack **stack_b)
{
	stack_addnew(stack_b, (*stack_a->num));
	if (stack_a->num != NULL)
		free(stack_a->num);
	if (stack_a != NULL)
		free(stack_a);
	// if ((*stack_a) != NULL)
	// 	free(*stack_a);
	// *stack_a = (*stack_a)->next;
	// if (*stack_a && (*stack_a)->next != NULL)
	// 	(*stack_a)->prev = NULL;
	// print_stack_b(*stack_b, 1);
	// print_stack(*stack_a, 1);
	return (1);
}

int		push_a(t_stack **stack_a, t_stack **stack_b)
{
	stack_addnew(stack_a, (*(*stack_b)->num));
	ft_stackpop(stack_b, *stack_b);
	print_stack_b(*stack_b, 1);
	print_stack(*stack_a, 1);
}
