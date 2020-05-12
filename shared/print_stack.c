/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:33:59 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/06 10:39:31 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"
#include <stdio.h>

int		print_stack(t_stack *stack_a, int ret)
{
	// t_stack *tail;

	while (stack_a != NULL)
	{
		// tail = stack_a;
		if (ret != -1)
		{
			// printf("|this is tail : %d|\n", (*tail->num));
			printf("|%d|\n", (*stack_a->num));
		}
		stack_a = stack_a->next;
	}
	if (ret != -1)
	{
		printf(" --\n");
		printf(" A\n\n");
	}
	else
		printf("Error\n");
	return (1);
}

int		print_stack_b(t_stack *stack_b, int ret)
{
	t_stack *tail;

	while (stack_b != NULL)
	{
		tail = stack_b;
		if (ret != -1)
			printf("|%d|\n", (*stack_b->num));
		stack_b = stack_b->next;
	}
	if (ret != -1)
	{
		printf(" --\n");
		printf(" B\n");
	}
	else
		printf("Error\n");
	return (1);
}
