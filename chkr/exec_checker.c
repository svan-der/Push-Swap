/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:34:26 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/27 10:16:54 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

void	initialize_operations(t_operates function_array[10])
{
	function_array[0] = swap_a;
	function_array[1] = rotate_a;
	function_array[2] = rotate_reva;
	function_array[3] = swap_b;
	function_array[4] = rotate_b;
	function_array[5] = rotate_revb;
	function_array[6] = swap_ss;
	function_array[7] = rotate_rr;
	function_array[8] = rotate_rrr;
	function_array[9] = push_a;
	function_array[10] = push_b;
}

int		execute_instruction(t_pw_var *stvar)
{
	int				ret;
	t_inst			*temp;
	t_operates		func_arr[10];

	temp = stvar->inst_lst;
	ret = 1;
	// ft_printf("temp->option is:%d\n", temp->option);
	initialize_operations(func_arr);
	while (temp != NULL)
	{
		func_arr[temp->option](stvar);
		temp = temp->next;
		// ft_printf("ret is:%d\n", ret);
		// print_stack(&stvar->stack_a, 1);
		// print_stack_list(stvar->stack_a, 'a');
		// if (temp != NULL)
		// 	ft_printf("option is:%d\n", temp->option);
		// ft_printf("ptr temp is:%p\n", temp);
	}
	return (ret);
}

int		check_instruction(t_sort *option, char *line, int *valid)
{
	if (ft_strequ(line, SA))
		return (*option = sa);
	if (ft_strequ(line, RA))
		return ((*option = ra));
	if (ft_strequ(line, RRA))
		return ((*option = rra));
	if (ft_strequ(line, SB))
		return ((*option = sb));
	if (ft_strequ(line, SS))
		return (*option = ss);
	if (ft_strequ(line, PA))
		return ((*option = pa));
	if (ft_strequ(line, PB))
		return ((*option = pb));
	if (ft_strequ(line, RB))
		return ((*option = rb));
	if (ft_strequ(line, RR))
		return ((*option = rr));
	if (ft_strequ(line, RRB))
		return ((*option = rrb));
	if (ft_strequ(line, RRR))
		return ((*option = rrr));
	else if (ft_strequ(line, ""))
		return (*valid = 0);
	return (*valid = -1);
}

int		get_instruction(t_pw_var *stvar)
{
	char	*line;
	int		ret;
	int		valid;
	t_sort	index;

	ret = 1;
	line = NULL;
	stvar->inst_lst = NULL;
	// inst = stvar->inst_lst;
	// stvar->inst_lst = (t_inst *)ft_memalloc(sizeof(t_inst));
	// index = NULL;
	valid = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		// ft_printf("ret is:%d\n", ret);
		check_instruction(&index, line, &valid);
		// ft_printf("instr is:%s\n\n", stvar->inst_lst->option);
		// ft_printf("valid is:%d\n", valid);
		if (ret == 0 || valid == 0)
			break ;
		if (ret == -1 || valid == -1)
			return (ft_min(valid, ret));
		// if (index)
		// 	ft_printf("option is:%d\n", index);
		ret = put_instruction(&stvar->inst_lst, index, line);
		// ft_printf("option is:%d\n", (*inst)->option);
		// ft_printf("instr is:%s\n", inst->operation);
		// if (stvar->inst_lst->option)
		// 	ft_printf("instr is:%s\n", stvar->inst_lst->operation);
		free(line);
		index = 0;
		// valid = 0;
		line = NULL;
		if (ret == -1)
			return (-1);
	}
	if (ret >= 0 && valid >= 0)
		ret = execute_instruction(stvar);
	// ft_printf("return is:%d\n", ret);
	// ft_printf("ptr inst is:%p\n", inst);
	// ft_printf("ptr inst is:%p\n", *inst);
	// ft_printf("ptr inst is:%p\n", stvar->inst_lst);
	// ft_printf("ptr inst is:%p\n", &stvar->inst_lst);
	// // print_inst_list(stvar->inst_lst);
	// print_inst_list(*inst);
	// print_stack_list(stvar->stack_a, 'a');
	// print_instructions(stvar->inst_lst, ret);
	// ret = check_sorted(&stvar->stack_a, &stvar->stack_b);
	return (ret);
}
