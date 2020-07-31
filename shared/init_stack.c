/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:12:42 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/29 23:43:15 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/push_swap.h"

void	add_tail(t_stack **stack)
{
	t_stack *tail;

	tail = *stack;
	while (tail && tail->next != NULL)
		tail = tail->next;
	if (tail)
	{
		if (tail && tail->prev)
			tail->prev = tail->prev;
		else
			tail->prev = NULL;
		(*stack)->tail = tail;
	}
}

t_stack	*create_stack(int num)
{
	t_stack *stack;

	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->dist = 0;
	stack->dist_top = 0;
	stack->num = num;
	stack->next = NULL;
	stack->prev = NULL;
	stack->tail = NULL;
	return (stack);
}

int		stack_addnew(t_stack **stack, int num)
{
	t_stack *new;

	new = create_stack(num);
	if (new == NULL)
		return (0);
	if (*stack == NULL)
	{
		*stack = new;
		(new)->prev = NULL;
		(new)->tail = new;
		(new)->tail->next = NULL;
		return (1);
	}
	ft_stackaddend(stack, new);
	add_tail(stack);
	return (1);
}

void	ft_stackaddend(t_stack **stack_lst, t_stack *new)
{
	t_stack	*temp;

	temp = *stack_lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	temp->next->prev = temp;
}

t_stack	*fill_stack_begin(t_stack **head, t_stack *new)
{
	t_stack *temp;
	t_stack *new_node;

	temp = *head;
	new_node = new;
	if (*head != NULL)
	{
		new_node->next = temp;
		temp->prev = new_node;
		temp = new_node;
	}
	else
	{
		temp = new_node;
		temp->prev = NULL;
	}
	return (temp);
}
