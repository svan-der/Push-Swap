/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/04 16:40:51 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

void	ft_stackaddend(t_stack **stack_lst, t_stack *new)
{
	t_stack	*temp;

	if (*stack_lst == NULL)
	{
		*stack_lst = new;
		return ;
	}
	temp = *stack_lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

t_stack	*ft_stackpop(t_stack **stack_lst)
{
	t_stack *tmp;
	t_stack *new;

	new = *stack_lst;
	tmp = *stack_lst;
	printf("same\n");
	if ((*stack_lst)->next == *stack_lst)
	{
		printf("stack_lst is NULL\n");
		*stack_lst = NULL;
	}
	else
		new = (new)->next;
	tmp->prev = NULL;
	tmp->next = NULL;
	*stack_lst = new;
	return (tmp);
}

void	add_node(t_stack **stack_b, t_stack *new)
{
	if (stack_b)
	{
		new->next = *stack_b;
		*stack_b = new;
	}
}

void	stack_push(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		new->prev = (*stack)->prev;
		new->next = (*stack);
		(*stack)->next->next = NULL;
		(*stack)->prev = new;
	}
	while (new->next != NULL)
		new = new->next;
	*stack = new;
}

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
	printf("num is: %d\n", num);
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
