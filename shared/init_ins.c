/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_ins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:50:30 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/18 09:44:27 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"

int		print_instructions(t_inst *inst_lst, int ret)
{
	t_inst *temp;
	t_inst *next;

	temp = inst_lst;
	while (temp != NULL)
	{
		next = temp->next;
		if (ret != -1)
			ft_printf("%s\n", temp->operation);
		temp = next;
	}
	return (1);
}

t_inst	*create_instruction(char *line)
{
	t_inst *inst;

	inst = (t_inst *)ft_memalloc(sizeof(t_inst));
	if (!inst)
		return (NULL);
	inst->operation = ft_strnew(sizeof(line));
	inst->content_size = ft_strlen(line);
	ft_memcpy(inst->operation, line, inst->content_size);
	inst->next = NULL;
	return (inst);
}

int		put_instruction(t_inst **inst_lst, char *line)
{
	t_inst *new_node;
	t_inst *temp;

	new_node = create_instruction(line);
	if (new_node == NULL)
		return (-1);
	if (*inst_lst == NULL)
	{
		*inst_lst = new_node;
		new_node->prev = NULL;
		return (1);
	}
	temp = *inst_lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	return (1);
}
