/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_ins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:50:30 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/02 18:21:34 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"
#include <stdio.h>

int		print_instructions(t_inst *inst_lst, int ret)
{
	t_inst *tail;

	while (inst_lst != NULL)
	{
		tail = inst_lst;
		if (ret != -1)
			printf("operation: |%s|\n", inst_lst->operation);
		if (inst_lst->next != NULL)
			free(inst_lst->operation);
		inst_lst = inst_lst->next;
	}
	if (ret != -1)
		printf("OK\n");
	else
		printf("Error\n");
	printf("ret is: %d\n", ret);
	return (1);
}

t_inst	*create_instruction(char *line)
{
	t_inst *inst;

	inst = (t_inst *)malloc(sizeof(t_inst));
	if (!inst)
		return (0);
	inst->operation = line;
	inst->content_size = ft_strlen(line);
	inst->next = NULL;
	return (inst);
}

void	put_instruction(t_inst **inst_lst, char *line)
{
	t_inst *inst;
	t_inst *tail;

	tail = *inst_lst;
	inst = create_instruction(line);
	if (*inst_lst == NULL)
	{
		inst->prev = NULL;
		*inst_lst = inst;
		return ;
	}
	else
		while (tail->next != NULL)
			tail = tail->next;
	tail->next = inst;
	inst->prev = tail;
	return ;
}
