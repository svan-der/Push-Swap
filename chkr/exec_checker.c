/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:34:26 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/05 23:29:11 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"
#include <stdio.h>

int		check_instruction(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strequ(line, "sa"))
		return (swap_a(stack_a));
	if (ft_strequ(line, "sb"))
		return (swap_b(stack_b));
	if (ft_strequ(line, "ss"))
		return (swap_ss(stack_a, stack_b));
	if (ft_strequ(line, "pa"))
		return (push_a(stack_a, stack_b));
	if (ft_strequ(line, "pb"))
		return (push_b(stack_a, stack_b));
	if (ft_strequ(line, "ra"))
		return (rotate_a(stack_a));
	if (ft_strequ(line, "rb"))
		return (rotate_b(stack_b));
	if (ft_strequ(line, "rr"))
		return (rotate_rr(stack_a, stack_b));
	if (ft_strequ(line, "rra"))
		return (rotate_reva(stack_a));
	if (ft_strequ(line, "rrb"))
		return (rotate_revb(stack_b));
	if (ft_strequ(line, "rrr"))
		return (rotate_rr(stack_a, stack_b));
	else if (ft_strequ(line, ""))
		return (0);
	return (-1);
}

int		get_instruction(t_pw_var *stvar)
{
	char	*line;
	int		ret;
	t_inst	inst;
	int		i;

	i = 0;
	ret = get_next_line(0, &line);
	ft_bzero(&inst, sizeof(t_inst));
	while (ret)
	{
		printf("begin\n");
		ret = check_instruction(&stvar->stack_a, &stvar->stack_b, line);
		printf("This is ret:%d\n", ret);
		if (ret == -1)
			return (print_instructions(stvar->inst_lst, ret));
		if (ret == 0)
			break ;
		put_instruction(&stvar->inst_lst, line);
		ret = get_next_line(0, &line);
		printf("This is ret after gnl:%d\n\n", ret);
	}
	print_instructions(stvar->inst_lst, ret);
	ret = check_sorted(stvar->stack_a, stvar->stack_b);
	printf("This is ret after check_sorted:%d\n\n", ret);
	// print_stack(stvar->stack_a, 1);
	// print_stack_b(stvar->stack_b, 1);
	// print_input_list(stvar->argv);
	// print_inst_list(stvar->inst_lst);
	// print_stack_list(stvar->stack_a);
	return (1);
}
