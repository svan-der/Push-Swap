/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:15:26 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/25 18:01:59 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

// int     rotate_a(t_stack **stack_a, t_stack **tail)
// {
//     // t_stack *ttail;
//     // t_stack *thead;
//     t_stack *new;

//     new = NULL;
//     (void)stack_a;
//     printf("in rotate a function\n");
//     // ttail = (*stack_a)->prev;
//     // thead = (*stack_a)->next;
//     // (*stack_a)->next = NULL;
//     // (*tail)->prev = NULL;
//     // (*stack_a)->prev = (*tail);
//     // (*tail)->next = thead;
//     // ttail->next = (*stack_a);
//     // thead->prev = (*tail);
//     // (*tail) = ttail->next;
//     // (*stack_a) = thead->next;
//     // (*tail)->next = ttail;
//     (*tail)->next = new;
//     (*stack_a)->prev = (*tail);
//     (*stack_a)->prev->next = 
//     // (*tail) = new;
//     return (1);
// }

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
		new->prev = last;
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
