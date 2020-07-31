// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        ::::::::            */
// // /*   nw_conq_opt.c                                      :+:    :+:            */
// // /*                                                     +:+                    */
// // /*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
// // /*                                                   +#+                      */
// // /*   Created: 2020/03/03 17:49:34 by svan-der      #+#    #+#                 */
// // /*   Updated: 2020/07/30 10:24:16 by svan-der      ########   odam.nl         */
// // /*                                                                            */
// // /* ************************************************************************** */

// // #include "../includes/push_swap.h"
// // #include "../includes/psw_env.h"


// char	*find_solution(t_pw_var *stvar, t_stack *current)
// {
// 	int 	top_next;
// 	int 	top_next_next;
// 	int 	bottom;
// 	int		ret;
// 	char	*operation;

// 	operation = NULL;
// 	if (stvar->stack_b != NULL && stvar->stack_b->next != NULL)
// 	{
// 		bottom = stvar->stack_b->tail->num;
// 		top_next = stvar->stack_b->next->num;
// 		if (stvar->stack_b->next->next != NULL)
// 		{
// 			top_next_next = stvar->stack_b->next->next->num;
// 			top_next_next = ft_abs(current->num - top_next_next);
// 		}
// 		bottom = ft_abs(current->num - bottom);
// 		top_next = ft_abs(current->num - top_next);
// 		// ft_printf(GRN"bottom dist:%i, top->next dist:%i\n"RESET, bottom, top_next);
// 		ret = top_next;
// 		// print_stack_list(stvar->stack_b, 'b');
// 		// ft_printf("current:%i\n", current->num);
// 		// ft_printf("dist:%i top_next:%i\n", top_next, stvar->stack_b->next->num);
// 		// if (stvar->stack_b->next->next != NULL)
// 		// 	ft_printf("dist:%i top_next_next:%i\n", top_next_next, stvar->stack_b->next->next->num);
// 		// ft_printf("dist:%i bottom:%i\n", bottom, stvar->stack_b->tail->num);
// 		if (stvar->stack_b->next->next != NULL && ret > top_next_next)
// 		{
// 			ret = top_next_next;
// 			// ft_printf("ret is:%i\n", ret);
// 		}
// 		if (ret > bottom)
// 		{
// 			ret = bottom;
// 			// ft_printf("ret is:%i\n", ret);
// 		}
// 		if (stvar->stack_b->next->next != NULL && ret == top_next_next)
// 		{
// 			// if (current->num <= stvar->median)
// 			// {
// 			// 	// diff met simple     -->    operation = SB;
// 			// 	operation = NULL;
// 			// 	// operation = NULL;
// 			// }
// 			if (ret == top_next_next)
// 			{
// 				// if (stvar->stack_b->num < stvar->stack_b->next->num)
// 				// if (stvar->stack_b->num < stvar->stack_b->next->num && stvar->stack_b->tail->num > stvar->stack_b->num)
// 				operation = SB;
// 				// if (stvar->stack_b->num > stvar->stack_b->next->num && stvar->stack_b->num > stvar->stack_b->tail->num && stvar->stack_b->next->next->num < stvar->stack_b->num)
// 				// 	operation = RB;
// 				if (current->num <= stvar->median)
// 					operation = NULL;
// 			}
// 		}
// 		else if (ret == bottom && ret != top_next)
// 			operation = RB;
// 		if (operation != NULL)
// 			do_op(stvar, operation, 'b', 1);
// 	}
// 	return (operation);
// }

// // void	insertion_sort(int *list, int argc, int *min, int *max)
// // {
// // 	int i;
// // 	int j;
// // 	int temp;

// // 	i = 1;
// // 	while (i < argc)
// // 	{
// // 		temp = list[i];
// // 		j = i - 1;
// // 		while (j >= 0 && list[j] > temp)
// // 		{
// // 			list[j + 1] = list[j];
// // 			j--;
// // 		}
// // 		list[j + 1] = temp;
// // 		i++;
// // 	}
// // }

// // /*
// // ** Calculates and returns shortest dist to top in current stack
// // */

// // int		shortest_dist(t_pw_var *stvar, t_stack *top, t_stack *bottom)
// // {
// // 	t_stack *current;
// // 	int		dist_top;
// // 	int		dist_bottom;
// // 	int		len;
// // 	int		i;

// // 	if (stvar->stack_b == NULL)
// // 		return (0);
// // 	current = stvar->stack_b;
// // 	len = stvar->index;
// // 	i = (len % 2) ? ((len / 2) + 1) : len / 2;
// // 	if (bottom->dist_top > i)
// // 		dist_bottom = stvar->index - bottom->dist_top;
// // 	else
// // 		dist_bottom = bottom->dist_top;
// // 	if (top->dist_top > i)
// // 		dist_top = stvar->index - top->dist_top;
// // 	else
// // 		dist_top = top->dist_top;
// // 	if (dist_top == dist_bottom && top->dist_top > bottom->dist_top)
// // 		return (1);
// // 	if (dist_top < dist_bottom)
// // 		return (0);
// // 	return (1);
// // }

// // char	*presort_stack_b(t_pw_var *stvar, t_stack *current, int *i)
// // {
// // 	t_stack *temp;
// // 	char	*oper_b;

// // 	temp = stvar->stack_b;
// // 	oper_b = NULL;
// // 	*i = 0;
// // 	if (temp && temp->next)
// // 	{
// // 		set_min_max(stvar, 'b');
// // 		// ft_printf(CYN"min:%i max:%i current:%i i:%i\n"RESET, stvar->min, stvar->max, current->num, *i);
// // 		if (current->num < stvar->min)
// // 			find_min(temp, stvar->min, i);
// // 		else if (current->num > stvar->min && current->num < stvar->max)
// // 			oper_b = find_pos(stvar, current, temp, i);
// // 		else if (current->num > stvar->max)
// // 			find_max(current, stvar->max, i);
// // 	}
// // 	if (*i == ((stvar->argc - stvar->index) - 1))
// // 	{
// // 		// ft_printf("equal to length\n");
// // 		return (NULL);
// // 	}
// // 	if (oper_b == NULL && *i != 0)
// // 		oper_b = fastest_rotate(stvar, 'b', i);
// // 	// if (oper_b)
// // 	// 	ft_printf("i is:%i oper_b:%s\n", *i, oper_b);
// // 	// if (*i == 1 && oper_b == NULL)
// // 	// 	return (SB);
// // 	return (oper_b);
// // }

// // // *last good one*
// // void	sort_top(t_pw_var *stvar, t_stack *top)
// // {
// // 	char *instr;

// // 	instr = fastest_rotate(stvar, 'a', &top->dist_top);
// // 	// ft_printf("rotate\n");
// // 	if (top->dist_top > 0)
// // 		do_op(stvar, instr, 'a', top->dist_top);
// // 	// print_stack_list(stvar->stack_a, 'a');
// // 	do_op(stvar, PB, 'b', 1);
// // 	// print_stack_list(stvar->stack_b, 'b');
// // 	// instr = find_solution(stvar, stvar->stack_b, NULL);
// // 	// if (instr != NULL)
// // 	// 	do_op(stvar, instr, 'b', 1);
// // }

// // // void	sort_top(t_pw_var *stvar, t_stack *top)
// // // {
// // // 	char 	*instr;
// // // 	char 	*instr_b;
// // // 	int		j;

// // // 	instr = NULL;
// // // 	if (top->dist_top > 0)
// // // 	{
// // // 		// if (top->dist_top == 1)
// // // 		// 	instr = SA;
// // // 		// else
// // // 		// 	instr = fastest_rotate(stvar, 'a', &top->dist_top);
// // // 		instr = fastest_rotate(stvar, 'a', &top->dist_top);
// // // 		do_op(stvar, instr, 'a', top->dist_top);
// // // 		// ft_printf(YEL"instr_a:%s\n"RESET, instr, top->dist_top);
// // // 		// print_inst_list(stvar->inst_lst);
// // // 		if (stvar->inst_lst)
// // // 			check_dble(stvar, instr);
// // // 	}
// // // 	// print_stack_list(stvar->stack_b, 'b');
// // // 	instr_b = presort_stack_b(stvar, top, &j);
// // // 	// if (instr_b)
// // // 		// ft_printf("found instr_b:%s\n", instr_b);
// // // 	if (instr_b != NULL && top->dist_top > 0)
// // // 	{
// // // 		// ft_printf(RED"instr:%s j:%i\n"RESET, instr_b, j);
// // // 		do_op(stvar, instr_b, 'b', j);
// // // 		if (stvar->inst_lst)
// // // 			check_dble(stvar, instr_b);
// // // 	}
// // // 	do_op(stvar, PB, 'b', 1);
// // // 	instr_b = find_solution(stvar, top, instr);
// // // 	if (stvar->inst_lst && instr_b)
// // // 		check_dble(stvar, instr_b);
// // // 	// ft_printf("+++++++++finished sort top+++++++++++++\n\n");
// // // }

// // void	sort_top_bottom(t_pw_var *stvar, int i, t_stack *top, t_stack *bottom)
// // {
// // 	if (i != 0)
// // 	{
// // 		// ft_printf("bottom dist_top:%i\n", bottom->dist_top);
// // 		sort_bottom(stvar, bottom);
// // 	}
// // 	else
// // 	{
// // 		sort_top(stvar, top);
// // 		// find_solution(stvar, top, NULL);
// // 	}
// // 	// find_solution(stvar, stvar->stack_b, NULL);
// // 	// ft_printf("finished\n");
// // }

// // void	sort_bottom(t_pw_var *stvar, t_stack *bottom)
// // {
// // 	char	*instr;
// // 	char	*instr_b;
// // 	int		j;

// // 	instr = NULL;
// // 	// ft_printf(RED"instr is:%s dist_top:%i\n"RESET, instr, bottom->dist_top);
// // 	if (bottom->dist_top)
// // 	{
// // 		instr = fastest_rotate(stvar, 'a', &bottom->dist_top);
// // 		if (bottom->dist_top != 0)
// // 			do_op(stvar, instr, 'a', bottom->dist_top);
// // 		// ft_printf(YEL"instr_a:%s dist:%i\n"RESET, instr, bottom->dist_top);
// // 		// print_inst_list(stvar->inst_lst);
// // 		if (stvar->inst_lst && instr)
// // 			check_dble(stvar, instr);
// // 		// if (instr_b != NULL)
// // 		// {
// // 		// // ft_printf(RED"instr:%s j:%i\n"RESET, instr_b, j);
// // 		// 	do_op(stvar, instr_b, 'b', j);
// // 		// 	if (stvar->inst_lst)
// // 		// 		check_dble(stvar, instr_b);
// // 		// }
// // 		// print_stack_list(stvar->stack_a, 'a');
// // 		do_op(stvar, PB, 'b', 1);
// // 		// print_stack_list(stvar->stack_b, 'b');
// // 	}
// // 	// instr_b = presort_stack_b(stvar, bottom, &j);
// // 	// instr_b = presort_simple(stvar, bottom);
// // 	// if (instr_b)
// // 		// ft_printf("found instr_b:%s\n", instr_b);
// // 	if (instr_b != NULL)
// // 	{
// // 		// ft_printf(RED"instr:%s j:%i\n"RESET, instr_b, j);
// // 		do_op(stvar, instr_b, 'b', j);
// // 		if (stvar->inst_lst && instr_b)
// // 			check_dble(stvar, instr_b);
// // 	}
// // 	// do_op(stvar, PB, 'b', 1);
// // 	instr_b = find_solution(stvar, bottom);
// // 	if (stvar->inst_lst && instr_b)
// // 		check_dble(stvar, instr_b);
// // 	// ft_printf("+++++++++finished sort bottom+++++++++++++\n\n");
// // }


// // // old sort_bottom

// // // 		instr_b = presort_stack_b(stvar, bottom, &j);
// // // 		if (instr_b != NULL)
// // // 		{
// // // 			ft_printf(RED"instr:%s j:%i\n"RESET, instr_b, j);
// // // 			do_op(stvar, instr_b, 'b', j);
// // // 			if (stvar->inst_lst)
// // // 				check_dble(stvar, instr_b);
// // // 		}
// // // 		// if (instr_b != NULL)
// // // 		// 	ret = check_dble(stvar, instr, instr_b, ft_min(i, j));
// // // 		// print_stack_list(stvar->stack_a, 'a');
// // // 		find_solution(stvar, bottom, NULL);
// // // 	}
// // // 	else
// // // 	{
// // // 		i = bottom->dist_top;
// // // 		if (i != 0)
// // // 			do_op(stvar, instr, 'a', i);
// // // 		// instr_b = presort_simple(stvar, bottom);
// // // 		// check_dble(stvar, instr, instr_b, 1);
// // // 		// print_stack_list(stvar->stack_a, 'a');
// // // 		do_op(stvar, PB, 'b', 1);
// // // 		// instr_b = presort_stack_b(stvar, bottom, &j);
// // // 		// if (instr_b != NULL)
// // // 		// {
// // // 		// 	ret = check_dble(stvar, instr, instr_b, ft_min(i, j));
// // // 		// 	if (ret == -1 && instr_b != NULL)
// // // 		// 		do_op(stvar, instr_b, 'b', i);
// // // 		// }
		
// // // 		// ret = check_dble(stvar, instr, instr_b, ft_min(i, j));
// // // 		// do_op(stvar, instr, 'a', bottom->dist_top);
// // // 		// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, bottom->dist);
// // // 		find_solution(stvar, bottom, instr);
// // // 		// i = bottom->dist_top;
// // // 		// instr = check_double(stvar, instr, bottom->dist_top, bottom);
// // // 		// do_op(stvar, instr, 'a', bottom->dist_top);
// // // 	}
// // // 	// print_stack_list(stvar->stack_a, 'a');
// // // 	// print_stack_list(stvar->stack_b, 'b');
// // // 	find_solution(stvar, stvar->stack_b, NULL);
// // // 	ft_printf("+++++++++finished sort bottom+++++++++++\n\n");
// // // 	// check_dble(stvar, instr, instr_b, 1);
// // // }

// // void	check_top_b(t_pw_var *stvar)
// // {
// // 	int i;
// // 	char *str;

// // 	if (stvar->stack_b && stvar->stack_b->next)
// // 	{
// // 		i = 0;
// // 		set_min_max(stvar, 'b');
// // 		// ft_printf("max is:%i\n in B:%i\n", stvar->max, stvar->stack_b->num);
// // 		if (stvar->stack_b->num == stvar->max)
// // 			return ;
// // 		// else
// // 		{
// // 			find_max(stvar->stack_b, stvar->max, &i);
// // 			str = fastest_rotate(stvar, 'b', &i);
// // 			// ft_printf("str is:%s i:%i\n", str, i);
// // 			do_op(stvar, str, 'b', i);
// // 			if (stvar->inst_lst && str)
// // 				check_dble(stvar, str);
// // 			// ft_printf("+++++++++++++++++finished check top b+++++++++++\n\n");
// // 			// print_stack_list(stvar->stack_b, 'b');
// // 		}
// // 	}
// // }

// // void	part_sort(t_pw_var *stvar, int argc, int i)
// // {
// // 	int j;
// // 	t_stack *top;
// // 	t_stack *bottom;
// // 	int res;

// // 	j = argc;
// // 	while (j)
// // 	{
// // 		// ft_printf("\n\n");
// // 		// ft_printf("j is:%i\n", j);
// // 		res = 0;
// // 		top = stvar->stack_a;
// // 		// ft_printf(GRN"|i:%i top:%i    part_id:%i top->index:%i    dist_top:%i|\n"RESET, i, top->num, top->part_id, top->index, top->dist_top);
// // 		bottom = stvar->stack_a->tail;
// // 		// ft_printf(YEL"|i:%i bottom:%i part_id:%i bottom->index:%i dist_top:%i|\n"RESET, i, bottom->num, bottom->part_id, bottom->index, bottom->dist_top);
// // 		if (top->part_id == i || bottom->part_id == i)
// // 		{
// // 			if (top->part_id == i && bottom->part_id == i)
// // 			{
// // 				// ft_printf("\n");
// // 				// ft_printf(CYN"=========== OPTION 1 sort_top_bottom ===========\n\n"RESET);
// // 				if (j != 1)
// // 					res = shortest_dist(stvar, top, bottom);
// // 				sort_top_bottom(stvar, res, top, bottom);
// // 			}
// // 			else if (top->part_id == i)
// // 			{
// // 				// ft_printf(BLU"=================== OPTION 2 sort_top ==============\n\n"RESET);
// // 				sort_top(stvar, top);
// // 			}
// // 			else if (bottom->part_id == i)
// // 			{
// // 				// ft_printf("\n");
// // 				// ft_printf(YEL"=================== OPTION 3 sort_bottom ==============\n\n"RESET);
// // 				sort_bottom(stvar, bottom);
// // 			}
// // 			// print_stack_list(stvar->stack_b, 'b');
// // 		}
// // 		else if (top->part_id != i && bottom->part_id != i)
// // 		{
// // 			// ft_printf("\n");
// // 			// ft_printf(RED"================== OPTION 4 find_part =================\n\n"RESET);
// // 			find_part(stvar, i);
// // 		}
// // 		check_top_b(stvar);
// // 		// print_tail_inst(stvar->inst_lst->tail);
// // 		// print_inst_list(stvar->inst_lst);
// // 		// print_inst_list(stvar->inst_lst);
// // 		j -= 1;
// // 	}
// // 	// ft_printf("END j is:%i\n", j);
// // 	// print_stack_list(stvar->stack_b, 'b');
// // 	// print_stack_list(stvar->stack_a, 'a');
// // 	// ft_printf("\n\n");
// // }

// // int		do_op(t_pw_var *stvar, char *str, char c, int num)
// // {
// // 	int i;
// // 	int ret;

// // 	i = 0;
// // 	while (i < num)
// // 	{
// // 		ret = dispatch_sort(stvar, str, 1);
// // 		if (ret == -1)
// // 			return (-1);
// // 		update_stack(stvar, c);
// // 		set_index(&stvar->stack_a, stvar->sorted, stvar->index);
// // 		set_index(&stvar->stack_b, stvar->sorted, stvar->argc - stvar->index);
// // 		i++;
// // 	}
// // 	return (ret);
// // }

// // char	*fastest_rotate(t_pw_var *stvar, char c, int *index)
// // {
// // 	int i;
// // 	int len;

// // 	len = (c == 'a') ? stvar->index : (stvar->argc - stvar->index);
// // 	i = (len % 2) ? ((len / 2) + 1) : len / 2;
// // 	// ft_printf("len:%i\t i:%i\n", len, i);
// // 	// ft_printf("char:%c\tindex:%i\t i:%i\n", c, index, i);
// // 	// ft_printf("char:%c\tstvar->argc:%i\tstvar->index:%i\tindex:%i\t i:%i\n", c, stvar->argc, stvar->index, *index, i);
// // 	if (*index < i)
// // 	{
// // 		return (c == 'a' ? RA : RB);
// // 	}
// // 	else
// // 	{
// // 		*index = len - *index;
// // 		// ft_printf("i:%i len:%i\n", *index, len);
// // 		return (c == 'a' ? RRA : RRB);
// // 	}
// // }

// // void	update_stack(t_pw_var *stvar, char c)
// // {
// // 	t_stack *temp;

// // 	if (c == 'a')
// // 		temp = stvar->stack_a;
// // 	if (c == 'b')
// // 		temp = stvar->stack_b;
// // 	if (c == 'a')
// // 	{
// // 		while (temp != NULL && temp->next != NULL)
// // 		{
// // 			find_distance(temp, temp->num, stvar->sorted);
// // 			temp = temp->next;
// // 		}
// // 	}
// // 	add_tail(&stvar->stack_a);
// // 	add_tail(&stvar->stack_b);
// // }
