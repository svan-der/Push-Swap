/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_lists.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 18:08:43 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/21 03:22:36 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"

t_inst	*inst_tail_delone(t_inst **inst_lst, char *instr, int i, int *j)
{
	t_inst *temp;
	t_inst *prev;

	// ft_printf("inside inst tail delone\n\n");
	temp = *inst_lst;
	prev = (*inst_lst)->prev;
	// ft_printf("prev:%s %p\n", prev->operation, prev);
	// print_tail_inst(prev);
	while (i && temp)
	{
		prev = temp->prev;
		// if (prev)
		// 	ft_printf("ptr:%p prev->tail->operation:%s\n", prev, (prev)->operation);
		// ft_printf("ptr:%p tail->operation:%s\n", temp, (temp)->operation);
		if (ft_strequ(temp->operation, instr))
		{
			// ft_printf("temp->operation:%s instr:%s\n", temp->operation, instr);
			*j -= 1;
			// ft_printf("J IS:%i\n", *j);
		}
		ft_strdel(&(temp)->operation);
		free(temp);
		temp = prev;
		i--;
	}
	if (prev)
		*inst_lst = prev;
	(*inst_lst)->next = NULL;
	return (*inst_lst);
}

void	free_inst_list(t_inst **inst_lst)
{
	t_inst *next;
	t_inst *temp;

	// printf("inside free inst list\n\n");
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

	// ft_printf("inside free_stack_list\n");
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

void	free_stack_list(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a != NULL)
		free_stack(stack_a);
	if (*stack_b != NULL)
		free_stack(stack_b);
}
