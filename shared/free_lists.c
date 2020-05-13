/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_lists.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 18:08:43 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/13 18:16:25 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"
#include <stdio.h>

void	free_inst_list(t_inst *inst_lst)
{
	t_inst *next;

	printf("inside free inst list\n\n");
	if (inst_lst != NULL)
		printf("instr is:%s\n\n", inst_lst->operation);
	while (inst_lst != NULL)
	{
		ft_printf("free at last\n");
		next = inst_lst->next;
		if (next != NULL)
		{
			free(inst_lst->operation);
			free(inst_lst);
		}
		inst_lst = next;
	}
}

void	free_stack_list(t_stack *stack)
{
	t_stack *next;

	while (stack != NULL)
	{
		next = stack->next;
		if (next != NULL)
		{
			// free(stack->num);
			free(stack);
		}
		stack = next;
	}
	stack = NULL;
}
