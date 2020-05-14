/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_lists.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 18:08:43 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/14 17:53:32 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"
#include <stdio.h>

void	free_inst_list(t_inst **inst_lst)
{
	t_inst *next;
	t_inst *temp;

	// printf("inside free inst list\n\n");
	temp = *inst_lst;
	while (temp != NULL)
	{
		// printf("instr is:%s\n", temp->operation);
		// printf("addr is:%p\n", temp);
		// ft_printf("free at last\n");
		next = temp->next;
		ft_strdel(&(temp)->operation);
		free(temp);
		// printf("addr is:%p\n", temp);
		temp = next;
	}
	*inst_lst = NULL;
	inst_lst = NULL;
}

static void	free_stack(t_stack **stack)
{
	t_stack *next;
	t_stack *temp;

	ft_printf("inside free_stack_list\n");
	// ft_printf("addres stack is:%p\n");
	// ft_printf("stack_num is:%d\n", stack->num);
	temp = *stack;
	while (temp != NULL)
	{
		next = temp->next;
		ft_printf("prev adress: %p\n", temp->prev);
		ft_printf("addres:%p\n", temp);
		ft_printf("adress after:%p\n", temp->next);
		free(temp);
		ft_printf("addres free'd:%p\n", temp);
		temp = next;
	}
	*stack = NULL;
	stack = NULL;
}

void	free_stack_list(t_stack **stack_a, t_stack **stack_b)
{
	// t_stack *temp;

	// temp = *stack_b;
	// ft_printf("prev adress: %p\n", temp->prev);
	// ft_printf("addres:%p\n", temp);
	// ft_printf("adress after:%p\n", temp->next);
	if (*stack_a != NULL)
		free_stack(stack_a);
	if (*stack_b != NULL)
		free_stack(stack_b);
}
