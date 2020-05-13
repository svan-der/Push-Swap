/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:51:18 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/13 17:50:23 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

int		swap_a(t_stack **stack_a)
{
	t_stack *temp;
	t_stack *new;

	new = *stack_a;
	if (new && new->next != NULL)
	{
		temp = new->next;
		new->prev = new->next;
		if (temp->next != NULL)
			temp->next->prev = new;
		new->next = temp->next;
		temp->next = new;
		new = temp;
		new->prev = NULL;
		*stack_a = new;
	}
	print_stack(*stack_a, 1);
	return (1);
}

int		swap_b(t_stack **stack_b)
{
	t_stack *temp;
	t_stack *new;

	new = *stack_b;
	if (new && new->next != NULL)
	{
		temp = new->next;
		new->prev = new->next;
		if (temp->next != NULL)
			temp->next->prev = new;
		new->next = temp->next;
		temp->next = new;
		new = temp;
		new->prev = NULL;
		*stack_b = new;
	}
	print_stack_b(*stack_b, 1);
	return (1);
}

int		swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack *temp1;

	temp = *stack_a;
	temp1 = *stack_b;
	ft_printf("inside swap ss\n");
	if (temp != NULL && temp->next != NULL)
		swap_a(stack_a);
	if ((temp1 != NULL && temp1->next != NULL))
	{
		ft_printf("in swap_b\n");
		swap_b(stack_b);
	}
	print_stack(*stack_a, 1);
	print_stack_b(*stack_b, 1);
	return (1);
}

/**
	the obective of this function is to take the first element of list A
	and plkace it to the biginning of list b

	stack a
	check if there are elements, stack_a is the 2nd node of stack_a,
	prev set back to when i am pushing NULL, next

	stack b
	the next of my "element" will be the entierty of list b
**/

int		push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	if (*stack_a == NULL)
		return (0);
	tmp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	// ft_printf("in stack_b:|%d|\n", (*(*stack_a)->num));
	fill_stack_begin(stack_b, (*stack_a));
	*stack_a = tmp;
	if (*stack_a && (*stack_a)->next != NULL)
		(*stack_a)->prev = NULL;
	// ft_printf("\n");
	print_stack(*stack_a, 1);
	// print_stack_b(*stack_b, 1);
	return (1);
}

int		push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	if (*stack_b == NULL)
		return (0);
	tmp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	// ft_printf("in stack_b:|%d|\n", (*(*stack_b)->num));
	fill_stack_begin(stack_a, (*stack_b));
	*stack_b = tmp;
	if (*stack_b && (*stack_b)->next != NULL)
		(*stack_b)->prev = NULL;
	print_stack(*stack_a, 1);
	print_stack_b(*stack_b, 1);
	return (1);
}
