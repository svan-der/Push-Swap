/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:51:18 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/03 11:00:13 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	add_node(t_stack **stack_b, t_stack *new)
{
	if (stack_b)
	{
		new->next = *stack_b;
		*stack_b = new;
	}
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
	tmp->tail = NULL;
	*stack_lst = new;
	return (tmp);
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
		if (new->tail && new->tail->next)
			new->tail->prev = NULL;
		(*stack)->prev = new;
	}
	while (new->next != NULL)
		new = new->next;
	*stack = new;
}

void	ft_stackaddend(t_stack **stack_lst, t_stack *new)
{
    t_stack  *temp;

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

/*
	the obective of this function is to take the first element of list A
	and plkace it to the biginning of list b

	stack a
	check if there are elements, stack_a is the 2nd node of stack_a,
	prev set back to when i am pushing NULL, next

	stack b
	the next of my "element" will be the entierty of list b
*/

int	push_b(t_stack **stack_a, t_stack **stack_b)
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
	if (new_a && new_a->next == NULL)
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
	if (new_b && new_b->next == NULL)
		new_b->prev = NULL;
	*stack_b = new_b;
	*stack_a = new_a;
	print_stack(*stack_a, 1);
	print_stack_b(*stack_b, 1);
	return (1);
}

