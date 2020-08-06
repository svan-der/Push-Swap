/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_ins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:50:30 by svan-der      #+#    #+#                 */
/*   Updated: 2020/08/05 13:13:10 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"

t_inst	*create_instruction(int index, char *line)
{
	t_inst *inst;

	inst = (t_inst *)ft_memalloc(sizeof(t_inst));
	if (!inst)
		return (NULL);
	inst->operation = ft_strnew(sizeof(line));
	inst->content_size = ft_strlen(line);
	ft_memcpy(inst->operation, line, inst->content_size);
	inst->option = index;
	inst->next = NULL;
	inst->tail = NULL;
	return (inst);
}

void	ft_instaddend(t_inst **inst_lst, t_inst *new)
{
	t_inst *temp;

	temp = *inst_lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	temp->next->prev = temp;
}

int		put_instruction(t_inst **inst_lst, int index, char *line)
{
	t_inst *new_node;

	new_node = create_instruction(index, line);
	if (new_node == NULL)
		return (-1);
	if (*inst_lst == NULL)
	{
		*inst_lst = new_node;
		new_node->prev = NULL;
		new_node->tail = new_node;
		new_node->tail->next = NULL;
		return (1);
	}
	ft_instaddend(inst_lst, new_node);
	add_inst_tail(inst_lst);
	return (1);
}

void	add_inst_tail(t_inst **inst_lst)
{
	t_inst *tail;

	tail = *inst_lst;
	while (tail && tail->next != NULL)
		tail = tail->next;
	if (tail)
	{
		if (tail && tail->prev)
			tail->prev = tail->prev;
		else
			tail->prev = NULL;
		(*inst_lst)->tail = tail;
	}
}
