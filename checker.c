/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:24:20 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/14 11:17:02 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	print_instructions(t_inst *inst_lst)
{
	t_inst *tail;

	while (inst_lst != NULL)
	{
		tail = inst_lst;
		printf("operation: |%s|\n", inst_lst->operation);
		// free(inst_lst->operation);
		inst_lst = inst_lst->next;
	}
	printf("OK\n");
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

int		check_instruction(char *line)
{
	if (ft_strequ(line, "sa"))
		return (1);
	if (ft_strequ(line, "sb"))
		return (1);
	if (ft_strequ(line, "ss"))
		return (1);
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
		ret = check_instruction(line);
		if (ret == -1)
		{
			printf("KO");
			return (0);
		}
		if (ret == 0)
			break ;
		put_instruction(&stvar->inst_lst, line);
		ret = get_next_line(0, &line);
	}
	print_instructions(stvar->inst_lst);
	return (1);
}
