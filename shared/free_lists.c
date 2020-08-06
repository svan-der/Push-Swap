/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_lists.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 18:08:43 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:35:50 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"

void		free_inst_list(t_inst **inst_lst)
{
	t_inst *next;
	t_inst *temp;

	temp = *inst_lst;
	while (temp != NULL)
	{
		next = temp->next;
		ft_strdel(&(temp)->operation);
		free(temp);
		temp = next;
	}
	*inst_lst = NULL;
	inst_lst = NULL;
}

static void	free_stack(t_stack **stack)
{
	t_stack *next;
	t_stack *temp;

	temp = *stack;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
	stack = NULL;
}

void		free_stack_list(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a != NULL)
		free_stack(stack_a);
	if (*stack_b != NULL)
		free_stack(stack_b);
}
