/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:51:18 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/22 13:49:20 by svan-der      ########   odam.nl         */
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

	tmp = *stack_lst;
	printf("same");
	if ((*stack_lst)->next == *stack_lst)
	{
		printf("same");
		*stack_lst = NULL;
	}
	else
	{
		printf("same");
		(*stack_lst)->prev->next = (*stack_lst)->next;
		(*stack_lst)->prev->prev = (*stack_lst)->prev;
		*stack_lst = (*stack_lst)->next;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
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
        temp = temp->next;
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

int	push_b(t_stack **new_a, t_stack **new_b)
{
	t_stack *tmp;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = *new_a;
	stack_b = *new_b;
	if (stack_a == NULL)
		return (0);
	if (stack_a != NULL)
	{
		printf("here push b\n\n");
		tmp = stack_a->next;
		stack_a->next = NULL;
		printf("in stack_a:|%d|\n", stack_a->num);
		fill_stack_begin(&stack_b, stack_a->num);
		stack_a = tmp;
		if (stack_a && stack_a->next == NULL)
			stack_a->prev = NULL;
	}
	*new_b = stack_b;
	*new_a = stack_a;
	// print_stack(*stack_a, 1);
	// printf("that was stack_a\n\n");
	// push_b(stack_a, stack_b);
	// print_stack_b(*stack_b, 1);
	// push_b(stack_a, stack_b);
	// push_a(stack_a, stack_b);
	return (1);
}



// t_stack	*push_b(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_stack *tmp;
// 	t_stack *stack;

// 	stack = NULL;
// 	if (stack_a == NULL)
// 		return (stack_b);
// 	if (stack_a != NULL)
// 	{
// 		printf("here push b\n\n");
// 		tmp = stack_a->next;
// 		stack_a->next = NULL;
// 		printf("in stack_a:|%d|\n", stack_a->num);
// 		fill_stack_begin(&stack, stack_a->num);
// 		stack_a = tmp;
// 		if (stack_a && stack_a->next == NULL)
// 			stack_a->prev = NULL;
// 	}
// 	stack_b = stack;
// 	// print_stack(*stack_a, 1);
// 	printf("that was stack_a\n\n");
// 	// print_stack_b(*stack_b, 1);
// 	// push_b(stack_a, stack_b);
// 	// push_a(stack_a, stack_b);
// 	return (stack_b);
// }

int		push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	tmp = stack_a->prev;
	if (stack_b == NULL)
		return (0);
	if (stack_b != NULL)
	{
		printf("here push b\n\n");
		tmp = stack_b->next;
		stack_b->next = NULL;
		printf("in stack_b:|%d|\n", stack_b->num);
		if (stack_a == NULL && stack_a->next == NULL)
			fill_stack_begin(&stack_a, stack_b->num);
		// fill_stack_begin(&stack_a, stack_b->num);
		stack_b = tmp;
		if (stack_b && stack_b->next == NULL)
			stack_b->prev = NULL;
	}
	print_stack(stack_a, 1);
	printf("that was stack_a\n\n");
	print_stack_b(stack_b, 1);
	push_a(stack_a, stack_b);
	return (1);
}

