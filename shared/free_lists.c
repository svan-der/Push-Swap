/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_lists.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 18:08:43 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 13:32:47 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"

t_inst	*inst_tail_del(t_inst **inst_lst, char *oper_b, char *oper_a, int tot)
{
	t_inst *temp;
	t_inst *prev;
	int		i;
	int		j;

	temp = *inst_lst;
	prev = (*inst_lst)->prev;
	j = temp->opt_dble_b;
	i = temp->opt_dble_a;
	while (tot > 0 && temp)
	{
		prev = temp->prev;
		if (ft_strequ(temp->operation, oper_b))
		{
			if (j > 0)
				j -= 1;
			else while (!ft_strequ(temp->operation, oper_b))
				temp = temp->prev;
		}
		if (ft_strequ(temp->operation, oper_a))
		{
			if (i > 0)
				i -= 1;
			else while (!ft_strequ(temp->operation, oper_a))
				temp = temp->prev;
		}
		ft_strdel(&(temp)->operation);
		free(temp);
		temp = prev;
		tot -= 1;
	}
	if (prev)
		*inst_lst = prev;
	(*inst_lst)->next = NULL;
	return ((*inst_lst));
}

void	free_inst_list(t_inst **inst_lst)
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

void	free_stack_list(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a != NULL)
		free_stack(stack_a);
	if (*stack_b != NULL)
		free_stack(stack_b);
}
