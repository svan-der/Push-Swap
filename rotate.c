/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:15:26 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/24 17:54:07 by svan-der      ########   odam.nl         */
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

int		rotate_b(t_stack **stack_b)
{
	t_stack *new;
	t_stack *last;
	t_stack *temp;

	temp = (*stack_b);
	printf("in rotate b function\n");
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
		temp->prev = NULL;
		ft_stackaddend(&temp, new);
		*stack_b = temp;
		print_stack(*stack_b, 1);
	}
	return (1);
}

int		rotate_a(t_stack **stack_a, t_stack **tail)
{
	t_stack *new;
	t_stack *last;
	t_stack *temp;

	temp = (*stack_a);
	if (temp && temp->next)
	{
		last = (*tail);
		if (last)
		{
			last->next = NULL;
			last->tail = NULL;
		}
		printf("in rotate a function\n");
		new = ft_stackpop(&temp);
		new->prev = last;
		temp->prev = NULL;
		ft_stackaddend(&temp, new);
		*stack_a = temp;
		print_stack(*stack_a, 1);
	}
	return (1);
}
