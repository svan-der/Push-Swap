/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/07 16:52:43 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include "psw_env.h"

int		check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	printf("inside check sorted\n\n");
	print_stack(stack_a, 1);
	print_stack_b(stack_b, 1);
	if (stack_b != NULL)
	{
		printf("KO\n");
		return (-1);
	}
	while (stack_a != NULL && stack_a->next != NULL)
	{
		printf("this is num: %i\n", stack_a->num);
		printf("this is num next: %i\n", stack_a->next->num);
		if (stack_a->num > stack_a->next->num)
		{
			printf("KO\n");
			return (-1);
		}
		stack_a = stack_a->next;
	}
	printf("OK\n");
	return (1);
}

void	fill_stack_begin(t_stack **head, t_stack *new)
{
	if (head)
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}
