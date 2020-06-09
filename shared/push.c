/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:51:18 by svan-der      #+#    #+#                 */
/*   Updated: 2020/06/09 18:04:00 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

int		swap_a(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *new;

	new = stvar->stack_a;
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
		stvar->stack_a = new;
	}
	// print_stack(&stvar->stack_a, 1);
	return (1);
}

int		swap_b(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *new;

	new = stvar->stack_b;
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
		stvar->stack_b = new;
	}
	// print_stack_b(stack_b, 1);
	return (1);
}

int		swap_ss(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *temp1;

	temp = stvar->stack_a;
	temp1 = stvar->stack_b;
	// ft_printf("inside swap ss\n");
	if (temp != NULL && temp->next != NULL)
		swap_a(stvar);
	if ((temp1 != NULL && temp1->next != NULL))
		swap_b(stvar);
	// print_stack(&stvar->stack_a, 1);
	// print_stack_b(&stvar->stack_b, 1);
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

int		push_b(t_pw_var *stvar)
{
	t_stack *tmp;
	t_stack	*new;

	if (stvar->stack_a == NULL)
		return (0);
	new = stvar->stack_b;
	tmp = stvar->stack_a->next;
	stvar->stack_a->next = NULL;
	new = fill_stack_begin(&new, stvar->stack_a);
	new->prev = NULL;
	stvar->stack_a = tmp;
	if (stvar->stack_a)
		stvar->stack_a->prev = NULL;
	stvar->stack_b = new;
	// add_tail(&stvar->stack_a);
	// print_stack(stack_a, 1);
	// print_stack_b(&stvar->stack_b, 1);
	return (1);
}

int		push_a(t_pw_var *stvar)
{
	t_stack *tmp;
	t_stack *new;

	// print_stack_list(stvar->stack_a, 'a');
	// print_stack_list(stvar->stack_b, 'b');
	// ft_printf("ptr is:%p\n", (*stvar).stack_b);
	// ft_printf("ptr is:%p\n", stvar->stack_b);
	if (stvar->stack_b == NULL)
		return (0);
	new = (*stvar).stack_a;
	tmp = (*stvar).stack_b->next;
	(*stvar).stack_b->next = NULL;
	// ft_printf("ptr next is:%p\n", (*stvar).stack_b->next);
	new = fill_stack_begin(&new, stvar->stack_b);
	new->prev = NULL;
	(*stvar).stack_b = tmp;
	if ((*stvar).stack_b)
	{
		// ft_printf("ptr is:%p\n", (*stvar).stack_b);
		(*stvar).stack_b->prev = NULL;
	}
	// ft_printf("ptr is:%p\n", (*stvar).stack_b->prev);
	// if ((*stvar).stack_b && (*stvar).stack_b->next != NULL)
	// 	(*stvar).stack_b->prev = NULL;
	(*stvar).stack_a = new;
	// add_tail(&stvar->stack_b);
	// print_stack_list(stvar->stack_b, 'b');
	// print_stack_list(stvar->stack_a, 'a');
	// print_stack(stack_a, 1);
	// print_stack_b(stack_b, 1);
	return (1);
}
