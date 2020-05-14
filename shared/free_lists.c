/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_lists.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 18:08:43 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/14 14:46:37 by svan-der      ########   odam.nl         */
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

void	free_stack_list(t_stack **stack)
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
		ft_printf("addres:%p\n", temp);
		free(temp);
		ft_printf("addres free'd:%p\n", temp);
		temp = next;
	}
	*stack = NULL;
	stack = NULL;
}
