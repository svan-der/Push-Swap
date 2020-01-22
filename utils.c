/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/22 15:18:33 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

void	print_backwards(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	if (stack == NULL)
		return ;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		printf("stack number:|%d|\n", tmp->num);
		tmp = tmp->prev;
	}
}

void	fill_stack_begin(t_stack **stack, int num)
{
	t_stack *tmp;

	tmp = create_stack(num);
	tmp->tail = *stack;
	printf("stack-tail num in begin: %d\n", num);
	if (*stack == NULL)
	{
		printf("stack_b is NULL\n");
		*stack = tmp;
		printf("stack-b num: %d\n", tmp->num);
		return ;
	}
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

t_stack	*swap_a(t_stack **new)
{
	t_stack *temp;
	t_stack *stack_a;

	stack_a = *new;
	if (stack_a && stack_a->next != NULL)
	{
		temp = stack_a->next;
		printf("sort list:|%d|\n", temp->num);
		stack_a->next = temp->next;
		printf("sort list:|%d|\n", stack_a->num);
		temp->next = stack_a;
		printf("sort list:|%d|\n", temp->num);
		stack_a = temp;
		printf("sort list:|%d|\n", stack_a->num);
	}
	// print_stack(stack_a, 1);
	return (stack_a);
}

t_stack	*swap_b(t_stack **new)
{
	t_stack *temp;
	t_stack *stack_b;

	stack_b = *new;
	temp = stack_b->next;
	printf("sort list:|%d|\n", temp->num);
	stack_b->next = temp->next;
	printf("sort list:|%d|\n", stack_b->num);
	temp->next = stack_b;
	printf("sort list:|%d|\n", temp->num);
	stack_b = temp;
	printf("sort list:|%d|\n", stack_b->num);
	// print_stack_b(stack_b, 1);
	return (stack_b);
}

int		swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack *temp1;

	temp = *stack_a;
	temp1 = *stack_b;
	printf("inside swap ss\n");
	if (temp && temp->next != NULL)
		temp = swap_a(stack_a);
	if ((temp1 != NULL && temp1->next != NULL))
	{
		printf("in swap_b\n");
		temp1 = swap_b(stack_b);
	}
	if (temp != NULL)
		*stack_a = temp;
	if (temp1 != NULL && temp1->next != NULL)
		*stack_b = temp1;
	print_stack(*stack_a, 1);
	print_stack_b(*stack_b, 1);
	return (1);
}

int		print_stack_b(t_stack *stack_b, int ret)
{
	t_stack *tail;

	while (stack_b != NULL)
	{
		tail = stack_b;
		if (ret != -1)
			printf("|%d|\n", stack_b->num);
		stack_b = stack_b->next;
	}
	if (ret != -1)
	{
		printf(" --\n");
		printf(" B\n");
	}
	else
		printf("Error\n");
	stack_b ? (stack_b = stack_b->next) : 0;
	return (1);
}
