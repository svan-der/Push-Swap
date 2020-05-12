/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_lists.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 18:08:43 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/05 22:19:55 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"

void	free_inst_list(t_inst *inst_lst)
{
	t_inst	*tail;

	while (inst_lst != NULL)
	{
		tail = inst_lst;
		if (inst_lst->next != NULL)
			free(inst_lst->operation);
		inst_lst = inst_lst->next;
	}
}

// void	free_stack_list(t_stack *stack)
// {
// 	t_inst	*tail;

// 	while (tail != NULL)
// 	{
// 		tail = stack;
// 		if (stack->next != NULL)
// 			free(stack->num);
// 		inst_lst = inst_lst->next;
// 	}
// }