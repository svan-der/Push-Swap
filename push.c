/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:51:18 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/24 17:34:06 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

// void	ft_stackpop(t_stack **stack_lst, t_stack *elem)
// {
// 	t_stack	*next;

// 	printf("in stackpop\n");
// 	if (stack_lst && elem)
// 	{
// 		printf("in the function\n");
// 		next = (*stack_lst)->next;
// 		printf("elem to be popped:%d\n\n", elem->num);
// 		printf("list elem:%d\n\n", (*stack_lst)->num);
// 		if ((*stack_lst)->num == elem->num)
// 		{
// 			printf("inside fpop\n");
// 			*stack_lst = next;
// 		}
// 		else
// 		{
// 			printf("pop else\n");
// 			printf("next elem:%d\n", next->num);
// 			ft_stackpop(&(*stack_lst)->next, elem);
// 		}
// 	}
// }

void	add_node(t_stack **stack_b, t_stack *new)
{
	if (stack_b)
	{
		new->next = *stack_b;
		*stack_b = new;
	}
}

// void 	stack_push(t_stack **stack, t_stack *new)
// {
// 	if (*stack)
// 		stack_push(&(*stack)->next, new);
// 	else
// 		*stack = new;
// }

t_stack	*ft_stackpop(t_stack **stack_lst)
{
	t_stack *tmp;
	t_stack *new;

	new = *stack_lst;
	tmp = *stack_lst;
	printf("same\n");
	if ((*stack_lst)->next == *stack_lst)
	{
		printf("same\n");
		*stack_lst = NULL;
	}
	else
	{
		printf("same\n");
		if ((new)->prev)
			(new)->prev->next = (new->next);
		if ((new)->prev)
			(new)->prev->prev = (new)->prev;
		new = (new)->next;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
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
		(*stack)->prev->next = new;
		(*stack)->prev = new;
	}
	*stack = new;
}

// void	stack_delete_end(t_stack **stack, t_stack *node)
// {

// }

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

	(void)new_b;
	new_a = *stack_a;
	new_b = *stack_b;
	if (new_a == NULL)
		return (0);
	printf("here push b\n\n");
	tmp = new_a->next;
	new_a->next = NULL;
	printf("in stack_a:|%d|\n", new_a->num);
	fill_stack_begin(&new_b, new_a->num);
	// if (new_b == NULL && new_b->next == NULL)
	// 	fill_stack_begin(&new_b, new_a->num);
	new_a = tmp;
	if (new_a && new_a->next == NULL)
		new_a->prev = NULL;
	*stack_b = new_b;
	*stack_a = new_a;
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
	// if (*stack_a == NULL && (*stack_a)->next == NULL)
	// 	fill_stack_begin(stack_a, new_a->num);
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

