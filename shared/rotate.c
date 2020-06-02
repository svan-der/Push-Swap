/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:15:26 by svan-der      #+#    #+#                 */
/*   Updated: 2020/06/01 16:31:35 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"
#include "../includes/checker.h"

int		rotate_rrr(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *temp1;

	temp = stvar->stack_a;
	temp1 = stvar->stack_b;
	if (temp != NULL && temp->next != NULL)
	{
		// ft_printf("rotate_a on\n\n");
		rotate_reva(stvar);
	}
	if (temp1 != NULL && temp1->next != NULL)
	{
		// ft_printf("rotate_b on\n\n");
		rotate_revb(stvar);
	}
	// print_stack(stack_a, 1);
	// print_stack_b(stack_b, 1);
	return (1);
}

int		rotate_rr(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *temp1;

	temp = stvar->stack_a;
	temp1 = stvar->stack_b;
	if (temp != NULL && temp->next != NULL)
	{
		// ft_printf("rotate_a on\n\n");
		rotate_a(stvar);
	}
	if (temp1 != NULL && temp1->next != NULL)
	{
		// ft_printf("rotate_b on\n\n");
		rotate_b(stvar);
	}
	// print_stack(stack_a, 1);
	// print_stack_b(stack_b, 1);
	return (1);
}

int		rotate_b(t_pw_var *stvar)
{
	t_stack *new;
	t_stack *temp;

	temp = (*stvar).stack_b;
	if (temp != NULL && temp->next != NULL)
	{
		new = (*stvar).stack_b->next;
		// ft_printf("new:%i\n", new->num);
		new->prev = NULL;
		while (temp->next)
			temp = temp->next;
		temp->next = (*stvar).stack_b;
		// ft_printf("new:%i\n", temp->next->num);
		temp->next->prev = temp;
		(*stvar).stack_b->next = NULL;
		// ft_printf("new:%i\n", temp->next->num);
		(*stvar).stack_b = new;
		print_stack_b(&stvar->stack_b, 1);
	}
	return (1);
}

int		rotate_revb(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *new;

	new = stvar->stack_b;
	if (new != NULL && new->next != NULL)
	{
		while (new->next->next != NULL)
			new = new->next;
		temp = new->next;
		new->next = NULL;
		while (new->prev != NULL)
			new = new->prev;
		new->prev = temp;
		temp->next = new;
		temp->prev = NULL;
		stvar->stack_b = temp;
		// print_stack_b(stack_b, 1);
	}
	return (1);
}

int		rotate_reva(t_pw_var *stvar)
{
	t_stack *temp;
	t_stack *new;

	// ft_printf("inside function reva\n");
	new = (*stvar).stack_a;
	print_stack_list(stvar->stack_a, 'a');
	ft_printf("num next is:%i\n", new->next->num);
	if (new != NULL && new->next != NULL)
	{
		// print_stack_list(stvar->stack_a, 'a');
		while (new->next->next != NULL)
		{
			new = new->next;
		}
		temp = new->next;
		new->next = NULL;
		// print_stack_list(stvar->stack_a, 'a');
		// ft_printf("num is:%i\n", new->num);
		while (new->prev != NULL)
		{
			new = new->prev;
		}
		new->prev = temp;
		temp->next = new;
		temp->prev = NULL;
		(*stvar).stack_a = temp;
			// print_stack_list(stvar->stack_a, 'a');
		// print_stack(&stvar->stack_a, 1);
	}
	return (1);
}

int		rotate_a(t_pw_var *stvar)
{
	t_stack *new;
	t_stack *temp;

	temp = (*stvar).stack_a;
	if (temp != NULL && temp->next != NULL)
	{
		new = (*stvar).stack_a->next;
		// ft_printf("new:%i\n", new->num);
		new->prev = NULL;
		while (temp->next)
			temp = temp->next;
		temp->next = (*stvar).stack_a;
		// ft_printf("new:%i\n", temp->next->num);
		temp->next->prev = temp;
		(*stvar).stack_a->next = NULL;
		// ft_printf("new:%i\n", temp->next->num);
		(*stvar).stack_a = new;
		// print_stack_list(stvar->stack_a, 'a');
		// print_stack(&stvar->stack_a, 1);
	}
	return (1);
}
