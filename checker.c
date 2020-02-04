/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:24:20 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/04 16:12:59 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int		check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	printf("inside check sorted\n\n");
	print_stack(stack_a, 1);
	print_stack_b(stack_b, 1);
	if (stack_b != NULL)
	{
		printf("KO\n");
		return (-1);
	}
	while (stack_a != NULL && stack_a->next != NULL)
	{
		printf("this is num: %i\n", stack_a->num);
		printf("this is num next: %i\n", stack_a->next->num);
		if (stack_a->num > stack_a->next->num)
		{
			printf("KO\n");
			return (-1);
		}
		stack_a = stack_a->next;
	}
	printf("OK\n");
	return (1);
}

// int		print_instructions(t_inst *inst_lst, int ret)
// {
// 	t_inst *tail;

// 	while (inst_lst != NULL)
// 	{
// 		tail = inst_lst;
// 		if (ret != -1)
// 			printf("operation: |%s|\n", inst_lst->operation);
// 		if (inst_lst->next != NULL)
// 			free(inst_lst->operation);
// 		inst_lst = inst_lst->next;
// 	}
// 	if (ret != -1)
// 		printf("OK\n");
// 	else
// 		printf("Error\n");
// 	printf("ret is: %d\n", ret);
// 	return (1);
// }

// t_inst	*create_instruction(char *line)
// {
// 	t_inst *inst;

// 	inst = (t_inst *)malloc(sizeof(t_inst));
// 	if (!inst)
// 		return (0);
// 	inst->operation = line;
// 	inst->content_size = ft_strlen(line);
// 	inst->next = NULL;
// 	return (inst);
// }

// void	put_instruction(t_inst **inst_lst, char *line)
// {
// 	t_inst *inst;
// 	t_inst *tail;

// 	tail = *inst_lst;
// 	inst = create_instruction(line);
// 	if (*inst_lst == NULL)
// 	{
// 		inst->prev = NULL;
// 		*inst_lst = inst;
// 		return ;
// 	}
// 	else
// 		while (tail->next != NULL)
// 			tail = tail->next;
// 	tail->next = inst;
// 	inst->prev = tail;
// 	return ;
// }

// int		check_instruction(t_stack **stack_a, t_stack **stack_b, char *line)
// {
// 	if (ft_strequ(line, "sa"))
// 		return (swap_a(stack_a));
// 	if (ft_strequ(line, "sb"))
// 		return (swap_b(stack_b));
// 	if (ft_strequ(line, "ss"))
// 	{
// 		printf("In ss function\n");
// 		return (swap_ss(stack_a, stack_b));
// 	}
// 	if (ft_strequ(line, "pa"))
// 		return (push_a(stack_a, stack_b));
// 	if (ft_strequ(line, "pb"))
// 	{
// 		print_stack_b(*stack_b, 1);
// 		print_stack(*stack_a, 1);
// 		printf("\n\n");
// 		return (push_b(stack_a, stack_b));
// 	}
// 	if (ft_strequ(line, "ra"))
// 	{
// 		printf("in rotate a\n");
// 		return (rotate_a(stack_a));
// 	}
// 	if (ft_strequ(line, "rb"))
// 		return (rotate_b(stack_b));
// 	if (ft_strequ(line, "rr"))
// 		return (rotate_rr(stack_a, stack_b));
// 	if (ft_strequ(line, "rra"))
// 		return (rotate_reva(stack_a));
// 	if (ft_strequ(line, "rrb"))
// 		return (rotate_revb(stack_b));
// 	if (ft_strequ(line, "rrr"))
// 		return (rotate_rr(stack_a, stack_b));
// 	else if (ft_strequ(line, ""))
// 		return (0);
// 	return (-1);
// }

// int		get_instruction(t_format *stvar)
// {
// 	char	*line;
// 	int		ret;
// 	t_inst	inst;
// 	int		i;

// 	i = 0;
// 	ret = get_next_line(0, &line);
// 	ft_bzero(&inst, sizeof(t_inst));
// 	while (ret)
// 	{
// 		printf("begin\n");
// 		ret = check_instruction(&stvar->stack_a, &stvar->stack_b, line);
// 		printf("This is ret:%d\n", ret);
// 		if (ret == -1)
// 			return (print_instructions(stvar->inst_lst, ret));
// 		if (ret == 0)
// 			break ;
// 		put_instruction(&stvar->inst_lst, line);
// 		ret = get_next_line(0, &line);
// 		printf("This is ret after gnl:%d\n\n", ret);
// 	}
// 	print_instructions(stvar->inst_lst, ret);
// 	print_stack(stvar->stack_a, 1);
// 	print_stack_b(stvar->stack_b, 1);
// 	ret = check_sorted(stvar->stack_a, stvar->stack_b);
// 	printf("This is ret after check_sorted:%d\n", ret);
// 	return (1);
// }
