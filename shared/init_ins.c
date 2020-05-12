/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_ins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:50:30 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/06 10:20:43 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"
#include <stdio.h>

int		print_instructions(t_inst *inst_lst, int ret)
{
	while (inst_lst != NULL)
	{
		if (ret != -1)
			printf("operation: |%s|\n\n", inst_lst->operation);
		// if (inst_lst->next != NULL)
		// 	free(inst_lst->operation);
		inst_lst = inst_lst->next;
	}
	if (ret != -1)
		printf("OK\n");
	else
		printf("Error\n");
	printf("ret is: %d\n", ret);
	return (1);
}


// t_inst	*cpy_nwreate_instruction(char *line)
// {
// 	t_inst *inst;
// 	// t_inst *tails;

// 	inst = (t_inst *)malloc(sizeof(t_inst));
// 	if (!inst)
// 		return (0);
// 	inst->operation = line;
// 	inst->content_size = ft_strlen(line);
// 	inst->next = NULL;
// 	inst->tail = inst;
// 	// if (!tails)
// 	// {
// 	// 	inst->tail == inst;
// 	// 	return (inst);
// 	// }
// 	// else
// 	// 	while (tails->next != NULL)
// 	// 		tails = tails->next;
// 	// tails->next = inst;
// 	return (inst);
// }

t_inst	*create_instruction(char *line)
{
	t_inst *inst;

	inst = (t_inst *)malloc(sizeof(t_inst));
	if (!inst)
		return (0);
	inst->operation = line;
	inst->content_size = ft_strlen(line);
	inst->next = NULL;
	// inst->tail = NULL;
	return (inst);
}

// void	cpy_nw_put_instruction(t_inst **inst_lst, char *line)
// {
// 	t_inst *inst;
// 	// t_inst *tail;

// 	// tail = *inst_lst;
// 	inst = create_instruction(line);
// 	if (*inst_lst == NULL)
// 	{
// 		inst->prev = NULL;
// 		*inst_lst = inst;
// 		return ;
// 	}
// 	else
// 		while (inst->tail->next != NULL)
// 			inst->tail = inst->tail->next;
// 	inst->tail->next = inst;
// 	inst->prev = inst->tail;
// 	// else
// 	// 	while (tail->next != NULL)
// 	// 		tail = tail->next;
// 	// tail->next = inst;
// 	// inst->prev = tail;
// 	return ;
// }


void	put_instruction(t_inst **inst_lst, char *line)
{
	t_inst *inst;
	t_inst *tail;

	tail = *inst_lst;
	inst = create_instruction(line);
	inst->tail = tail;
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
