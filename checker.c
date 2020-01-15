/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:24:20 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/15 15:49:39 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
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
	printf("ret is: %d", ret);
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

int		check_instruction(t_format *stvar, char *line)
{
	if (ft_strequ(line, "sa"))
	{
		printf("here\n");
		return (swap_a(stvar->stack_a));
	}
	if (ft_strequ(line, "sb"))
		return (swap_b(stvar->stack_b));
	if (ft_strequ(line, "ss"))
		return (swap_ss(stvar->stack_a, stvar->stack_b));
	if (ft_strequ(line, "pa"))
		return (1);
	if (ft_strequ(line, "pb"))
		return (1);
	if (ft_strequ(line, "ra"))
		return (1);
	if (ft_strequ(line, "rb"))
		return (1);
	if (ft_strequ(line, "rr"))
		return (1);
	if (ft_strequ(line, "rra"))
		return (1);
	if (ft_strequ(line, "rrb"))
		return (1);
	if (ft_strequ(line, "rrr"))
		return (1);
	else if (ft_strequ(line, ""))
		return (0);
	return (-1);
}

int		get_instruction(t_format *stvar, char **argv)
{
	char	*line;
	int		ret;
	t_inst	inst;
	int		i;

	i = 0;
	(void)argv;
	ret = get_next_line(0, &line);
	ft_bzero(&inst, sizeof(t_inst));
	while (ret)
	{
		printf("begin\n");
		ret = check_instruction(stvar, line);
		if (ret == -1)
			return (print_instructions(stvar->inst_lst, ret));
		if (ret == 0)
			break ;
		put_instruction(&stvar->inst_lst, line);
		ret = get_next_line(0, &line);
	}
	print_instructions(stvar->inst_lst, ret);
	return (1);
}
