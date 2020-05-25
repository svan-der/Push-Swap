/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:34:26 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/25 10:22:57 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

int		execute_instruction(t_stack **stack_a, t_stack **stack_b, t_pw_var *stvar)
{
	// static t_operate sort_os[] = \
	// {swap_a, rotate_a, rotate_reva, swap_b, swap_b, rotate_revb};
	// static t_operates sort_ds[] = \
	// {swap_ss, rotate_rr, rotate_rrr, push_a, push_b};
	int				 ret;
	t_inst			*temp;
	t_operates		options;

	(void)stack_b;
	temp = stvar->inst_lst;
	ft_printf("temp->option is:%d\n", temp->option);
	while (temp != NULL && *stack_a != NULL)
	{
		if (temp->option < 7)
			ret = options.arr_os[temp->option];
		if (temp->option > 6 && temp->option < 12)
			ret = options.arr_ds[temp->option];
		temp = temp->next;
		ft_printf("ret is:%d\n", ret);
		print_stack(stack_a, 1);
		ft_printf("option is:%d\n", temp->option);
	}
	return (ret);
}


// int		execute_instruction(t_stack **stack_a, t_stack **stack_b, t_pw_var *stvar)
// {
	// static int(*const f_stack_a[])(t_stack **) =
	// {nul, swap_a, rotate_a, rotate_reva};
	// static int(*const f_stack_b[])(t_stack **) =
	// {swap_b, rotate_b, rotate_revb};
	// static int(*const f_stacks[])(t_stack **, t_stack **) =
	// {swap_ss, rotate_rr, rotate_rrr, push_a, push_b};

	// static t_operate sort_os[] = {swap_a, rotate_a, rotate_reva,\
	// 							swap_b, swap_b, rotate_revb};
	// static t_operate sort_ds[] = {swap_ss, rotate_rr, rotate_rrr,\
	// 							push_a, push_b};
	// t_operate sort_ds[4];

	// int 	ret;
	// t_inst	*temp;

	// (void)stack_b;
	// temp = stvar->inst_lst;
	// // print_inst_list(stvar->inst_lst);
	// ft_printf("temp->option is:%d\n", temp->option);
	// while (temp != NULL && *stack_a != NULL)
	// {
	// 	// ft_printf("pointer is:%p\n", temp);
	// 	// ft_printf("option is:%d\n", temp->option);
	// 	// ft_printf("stack is:%p\n", stack_a);
	// 	// ft_printf("stack is:%p\n", *stack_a);
	// 	// // ft_printf("stack_a num is:%d\n", (*stack_a)->num);
	// 	if (temp->option < 3)
	// 		ret = f_stack_a[temp->option](stack_a);
	// 	if (temp->option > 2 && temp->option < 6)
	// 		ret = f_stack_b[temp->option](stack_b);
	// 	else
	// 		ret = f_stacks[temp->option](stack_a, stack_b);
	// 	ft_printf("ret is:%d\n", ret);
	// 	print_stack(stack_a, 1);
	// 	ft_printf("option is:%d\n", temp->option);
	// 	temp = temp->next;
	// }
	// return (ret);
	// if (ft_strequ(line, "sa"))
	// 	return (swap_a(stack_a));
	// if (ft_strequ(line, "sb"))
	// 	return (swap_b(stack_b));
	// if (ft_strequ(line, "ss"))
	// 	return (swap_ss(stack_a, stack_b));
	// if (ft_strequ(line, "pa"))
	// 	return (push_a(stack_a, stack_b));
	// if (ft_strequ(line, "pb"))
	// 	return (push_b(stack_a, stack_b));
	// if (ft_strequ(line, "ra"))
	// 	return (rotate_a(stack_a));
	// if (ft_strequ(line, "rb"))
	// 	return (rotate_b(stack_b));
	// if (ft_strequ(line, "rr"))
	// 	return (rotate_rr(stack_a, stack_b));
	// if (ft_strequ(line, "rra"))
	// 	return (rotate_reva(stack_a));
	// if (ft_strequ(line, "rrb"))
	// 	return (rotate_revb(stack_b));
	// if (ft_strequ(line, "rrr"))
	// 	return (rotate_rr(stack_a, stack_b));
// }

int		check_instruction(t_sort *option, char *line)
{
	// ft_printf("option is:%p\n", *option);
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
		return (0);
	return (-1);
}

int		get_instruction(t_pw_var *stvar)
{
	char	*line;
	int		ret;
	int		valid;
	t_inst	**inst;
	t_sort	index;

	ret = 1;
	line = NULL;
	stvar->inst_lst = NULL;
	// inst = stvar->inst_lst;
	// stvar->inst_lst = (t_inst *)ft_memalloc(sizeof(t_inst));
	// inst = NULL;
	// index = NULL;
	inst = &stvar->inst_lst;
	ft_printf("ptr is: %p\n", inst);
	// ft_printf("ptr is: %p\n", *inst);
	// stvar->option = ft_memalloc(sizeof(t_sort));
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		ft_printf("ret is:%d\n", ret);
		// ft_printf("instr is:%s\n\n", stvar->inst_lst->option);
		valid = check_instruction(&index, line);
		ft_printf("valid is:%d\n", valid);
		if (ret == 0 || valid < 1)
			break ;
		ft_printf("option is:%d\n", index);
		ret = put_instruction(inst, index, line);
		// put_instruction(&(*stvar).inst_lst, line);
		// ft_printf("option is:%d\n", (*inst)->option);
		// ft_printf("instr is:%s\n", inst->operation);
		// valid = check_instruction(line, &(*stvar).inst_lst->option);
		// ft_putstr_fd("OK coming\n", 1);
		free(line);
		index = 0;
		line = NULL;
		if (ret == -1)
			return (-1);
	}
	if (ret >= 0)
		ret = execute_instruction(&stvar->stack_a, &stvar->stack_b, stvar);
	print_inst_list(stvar->inst_lst);
	// ft_printf("ret is:%d\n", ret);
	// print_stack_list(stvar->stack_a, 'a');
	// print_instructions(stvar->inst_lst, ret);
	// ret = check_sorted(&stvar->stack_a, &stvar->stack_b);
	return (ret);
}
