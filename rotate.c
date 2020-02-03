/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:15:26 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/29 14:44:06 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int		rotate_revb(t_stack **stack_b)
{
	t_stack *new;
	t_stack *last;
	t_stack *temp;
	t_stack *ttail;

	temp = (*stack_b);
	new = (*stack_b);
	if (temp && temp->next)
	{
		last = ((*stack_b)->tail);
		ttail = last;
		if (last && last->next)
		{
			last = last->next;
			last->prev = NULL;
			last->next = NULL;
		}
		ttail->next = NULL;
		printf("in rotate b function\n");
		stack_push(&temp, ttail);
		ttail->prev = NULL;
		// reverse_list(&last);
		*stack_b = temp;
		print_stack(*stack_b, 1);
		printf("\n");
	}
	return (1);
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

// int		rotate_reva(t_stack **stack_a)
// {
// 	t_stack *temp;
// 	t_stack *ttail;
// 	t_stack *new;
// 	t_stack *last;

// 	temp = (*stack_a);
// 	ttail = (*stack_a)->tail;
// 	new = (*stack_a);
// 	if (temp && temp->next)
// 	{
// 		// last = new->tail;
// 		// ttail = temp->tail;
// 		last = ttail;
// 		if (last)
// 		{
// 			if (last->next)
// 				last = last->next;
// 			last->prev = NULL;
// 			last->next = NULL;
// 		}
// 		ttail->next = NULL;
// 		printf("in rotate a function\n");
// 		stack_push(&temp, ttail);
// 		ttail->prev = NULL;
// 		(*stack_a)->tail = reverse_list(&last);
// 		new = new->next;
// 		*stack_a = temp;
// 		print_stack(*stack_a, 1);
// 		printf("\n");
// 	}
// 	return (1);
// }

int		rotate_reva(t_stack **stack_a)
{
	t_stack *temp;
	t_stack *new;

	temp = (*stack_a)->tail->next;
	new = temp;
	new->next = (*stack_a);
	stack_a = &new;
	temp->next = NULL;
	print_stack(*stack_a, 1);
	printf("\n");
	return (1);
}

int		rotate_b(t_stack **stack_b)
{
	t_stack *new;
	t_stack *last;
	t_stack *temp;

	temp = (*stack_b);
	if (temp && temp->next)
	{
		last = ((*stack_b)->tail);
		if (last)
		{
			last->next = NULL;
			last->tail = NULL;
		}
		printf("in rotate b function\n");
		new = ft_stackpop(&temp);
		new->prev = last;
		if (temp)
			temp->prev = NULL;
		temp->tail = new;
		ft_stackaddend(&temp, new);
		*stack_b = temp;
		print_stack_b(*stack_b, 1);
		printf("\n");
	}
	return (1);
}

int		rotate_a(t_stack **stack_a)
{
	t_stack *new;
	t_stack *last;
	t_stack *temp;

	temp = (*stack_a);
	if (temp && temp->next)
	{
		last = ((*stack_a)->tail);
		if (last)
		{
			last->next = NULL;
			last->tail = NULL;
		}
		printf("in rotate a function\n");
		new = ft_stackpop(&temp);
		if (temp)
			temp->prev = NULL;
		temp->tail = new;
		ft_stackaddend(&temp, new);
		*stack_a = temp;
		print_stack(*stack_a, 1);
		printf("\n");
	}
	return (1);
}
