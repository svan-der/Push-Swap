/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_ins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:50:30 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/14 16:49:57 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"
#include <stdio.h>

int		print_instructions(t_inst *inst_lst, int ret)
{
	t_inst *temp;
	t_inst *next;

	ft_printf("inside print instructions\n\n");
	temp = inst_lst;
	while (temp != NULL)
	{
		next = temp->next;
		if (ret != -1)
			printf("operation: |%s|\n\n", temp->operation);
		// free(temp->operation);
		// free(temp);
		temp = next;
	}
	if (ret == -1)
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

	inst = (t_inst *)ft_memalloc(sizeof(t_inst));
	// printf("size of inst node in bytes : %ld\n", sizeof(inst));
	if (!inst)
		return (NULL);
	inst->operation = ft_strnew(sizeof(line));
	// inst->operation = ft_strnew(sizeof(line));
	// inst->operation = line;
	// inst->operation = ft
	// inst->operation = ft_memdup(line, sizeof(line) + 1);
	inst->content_size = ft_strlen(line);
	ft_memcpy(inst->operation, line, inst->content_size);
	inst->next = NULL;
	// inst->tail = NULL;
	// printf("this is instr:%s\n", inst->operation);
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

int		put_instruction(t_inst **inst_lst, char *line)
{
	t_inst *new_node;
	t_inst *temp;

	new_node = create_instruction(line);
	// ft_printf("new_node addr:%p\n", new_node);
	// ft_printf("head inst-lst is:%p\n", *inst_lst);
	if (new_node == NULL)
		return (-1);
	if (*inst_lst == NULL)
	{
		*inst_lst = new_node;
		new_node->prev = NULL;
		// ft_printf("*inst_lst addr:%p\n", (*inst_lst));
		// printf("this is inst_lst oper:%s\n", (*inst_lst)->operation);
		return (1);
	}
	temp = *inst_lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	// ft_printf("temp is:%p\n", temp);
	// ft_printf("head inst-lst is:%p\n", *inst_lst);
	return (1);
}
