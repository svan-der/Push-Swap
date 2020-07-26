/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_solution.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 17:14:33 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/23 23:44:16 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_bottom_part(t_pw_var *stvar, int i)
{
	t_stack *temp;
	int		j;

	temp = stvar->stack_a->tail;
	j = 1;
	// print_tail(stvar->stack_a->tail);
	while (temp)
	{
		if (temp->part_id == i)
		{
			temp->dist_top = stvar->index - j;
			// ft_printf("dist_bottom to top:%i\n", temp->dist_top);
			return (temp);
		}
		temp = temp->prev;
		j++;
	}
	return (temp);
}

t_stack	*find_top_part(t_pw_var *stvar, int i)
{
	t_stack *temp;
	int		j;

	temp = stvar->stack_a;
	j = 0;
	// ft_printf("i:%i\n", i);
	while (temp)
	{
		if (temp->part_id == i)
		{
			temp->dist_top = j;
			// ft_printf("dist_top:%i\n", temp->dist_top);
			return (temp);
		}
		temp = temp->next;
		j++;
	}
	return (temp);
}

char	*presort_simple(t_pw_var *stvar, t_stack *current)
{
	int top;
	int top_next;
	int bottom;
	int	ret;
	int	bottom_prev;
	char	*operation;

	operation = NULL;
	if (stvar->stack_b != NULL && stvar->stack_b->next != NULL)
	{
		// ft_printf(" IN PRESORT SIMPLE w current:%i\n", current->num);
		bottom = stvar->stack_b->tail->num;
		top = stvar->stack_b->num;
		if (stvar->stack_b->next != NULL)
		{
			top_next = stvar->stack_b->next->num;
			// ft_printf(" top_next:%i\n", top_next);
			bottom_prev = stvar->stack_b->tail->prev->num;
			bottom_prev = ft_abs(current->num - bottom_prev);
			top_next = ft_abs(current->num - top_next);
			bottom = ft_abs(current->num - bottom);
		}
		top = ft_abs(current->num - top);
		// ft_printf(GRN"bottom dist:%i, top->next dist:%i\n"RESET, bottom, top_next);
		ret = top;
		operation = NULL;
		// ft_printf(" top:%i\n", top);
		// if (stvar->stack_b->next != NULL)
		// {
		// 	ft_printf(" top_next:%i\n", top_next);
		// 	ft_printf(" bottom_prev:%i\n", bottom_prev);
		// }
		// ft_printf(" bottom:%i\n", bottom);
		if (stvar->stack_b->next != NULL && ret > top_next)
		{
			ret = top_next;
		}
		if (stvar->stack_b->next != NULL && ret > bottom)
		{
			ret = bottom;
		}
		if (stvar->stack_b->next != NULL && ret == top_next)
		{
			// ft_printf("SWAP\n");
			// if (current->num <= stvar->median)
			// 	// return (NULL);
			// ft_printf("median:%i\n", stvar->median);
			operation = RB;
			if (stvar->stack_b->num < stvar->median)
				operation = NULL;
			// else if (ret == top_next)
			// {
			// 	operation = RB;
			// 	if (ret == bottom && stvar->stack_b->tail->num <= stvar->median)
			// 		operation = NULL;
			// }
		}
		else if (ret == bottom)
		{
			// if (current->num >= stvar->median)
			// 	return (NULL);
			// ft_printf("ROT\n");
			// ft_printf("median:%i\n", stvar->median);
			// ft_printf("bottom_prev:%i bottom:%i ret:%i\n", bottom_prev, bottom, ret);
			if (bottom_prev < ret)
				operation = RRB;
		}
		if (operation)
		{
			// ft_printf(" operation:%s\n", operation);
			do_op(stvar, operation, 'b', 1);
			// print_stack_list(stvar->stack_b, 'b');
		}
		// ft_printf(" ret is:%i\n", ret);
	}
	return (operation);
}


// char	*presort_simple(t_pw_var *stvar, t_stack *current)
// {
// 	int top;
// 	int top_next;
// 	int bottom;
// 	int	ret;
// 	int	bottom_prev;
// 	char	*operation;

// 	operation = NULL;
// 	if (stvar->stack_b != NULL && stvar->stack_b->next != NULL)
// 	{
// 		// ft_printf(" IN PRESORT SIMPLE w current:%i\n", current->num);
// 		bottom = stvar->stack_b->tail->num;
// 		top = stvar->stack_b->num;
// 		if (stvar->stack_b->next != NULL)
// 		{
// 			top_next = stvar->stack_b->next->num;
// 			// ft_printf(" top_next:%i\n", top_next);
// 			bottom_prev = stvar->stack_b->tail->prev->num;
// 			bottom_prev = ft_abs(current->num - bottom_prev);
// 			top_next = ft_abs(current->num - top_next);
// 			bottom = ft_abs(current->num - bottom);
// 		}
// 		top = ft_abs(current->num - top);
// 		// ft_printf(GRN"bottom dist:%i, top->next dist:%i\n"RESET, bottom, top_next);
// 		ret = top;
// 		operation = NULL;
// 		// ft_printf(" top:%i\n", top);
// 		// if (stvar->stack_b->next != NULL)
// 		// {
// 		// 	ft_printf(" top_next:%i\n", top_next);
// 		// 	ft_printf(" bottom_prev:%i\n", bottom_prev);
// 		// }
// 		// ft_printf(" bottom:%i\n", bottom);
// 		if (stvar->stack_b->next != NULL && ret > top_next)
// 		{
// 			ret = top_next;
// 		}
// 		if (stvar->stack_b->next != NULL && ret > bottom)
// 		{
// 			ret = bottom;
// 		}
// 		if (stvar->stack_b->next != NULL && ret == top_next)
// 		{
// 			// ft_printf("SWAP\n");
// 			// if (current->num <= stvar->median)
// 			// 	// return (NULL);
// 			// ft_printf("median:%i\n", stvar->median);
// 			if (stvar->stack_b->num <= stvar->median)
// 				operation = SB;
// 			else if (ret == top_next)
// 			{
// 				operation = RB;
// 				if (ret == bottom && stvar->stack_b->tail->num <= stvar->median)
// 					operation = NULL;
// 			}
// 		}
// 		else if (ret == bottom)
// 		{
// 			// if (current->num >= stvar->median)
// 			// 	return (NULL);
// 			// ft_printf("ROT\n");
// 			// ft_printf("median:%i\n", stvar->median);
// 			// ft_printf("bottom_prev:%i bottom:%i ret:%i\n", bottom_prev, bottom, ret);
// 			if (bottom_prev < ret)
// 				operation = RRB;
// 		}
// 		if (operation)
// 		{
// 			// ft_printf(" operation:%s\n", operation);
// 			do_op(stvar, operation, 'b', 1);
// 			// print_stack_list(stvar->stack_b, 'b');
// 		}
// 		// ft_printf(" ret is:%i\n", ret);
// 	}
// 	return (operation);
// }

char	*find_solution(t_pw_var *stvar, t_stack *current, char *oper)
{
	int top_next;
	int top_next_next;
	int bottom;
	int	ret;
	char	*operation;

	operation = NULL;
	if (stvar->stack_b != NULL && stvar->stack_b->next != NULL)
	{
		bottom = stvar->stack_b->tail->num;
		top_next = stvar->stack_b->next->num;
		if (stvar->stack_b->next->next != NULL)
		{
			top_next_next = stvar->stack_b->next->next->num;
			top_next_next = ft_abs(current->num - top_next_next);
		}
		bottom = ft_abs(current->num - bottom);
		top_next = ft_abs(current->num - top_next);
		// ft_printf(GRN"bottom dist:%i, top->next dist:%i\n"RESET, bottom, top_next);
		ret = top_next;
		// print_stack_list(stvar->stack_b, 'b');
		// ft_printf("current:%i\n", current->num);
		// ft_printf("dist:%i top_next:%i\n", top_next, stvar->stack_b->next->num);
		// if (stvar->stack_b->next->next != NULL)
		// 	ft_printf("dist:%i top_next_next:%i\n", top_next_next, stvar->stack_b->next->next->num);
		// ft_printf("dist:%i bottom:%i\n", bottom, stvar->stack_b->tail->num);
		if (stvar->stack_b->next->next != NULL && ret > top_next_next)
		{
			ret = top_next_next;
			// ft_printf("ret is:%i\n", ret);
		}
		if (ret > bottom)
		{
			ret = bottom;
			// ft_printf("ret is:%i\n", ret);
		}
		if (stvar->stack_b->next->next != NULL && ret == top_next_next)
		{
			// if (current->num <= stvar->median)
			// {
			// 	// diff met simple     -->    operation = SB;
			// 	operation = NULL;
			// 	// operation = NULL;
			// }
			if (ret == top_next_next)
			{
				// if (stvar->stack_b->num < stvar->stack_b->next->num)
				// if (stvar->stack_b->num < stvar->stack_b->next->num && stvar->stack_b->tail->num > stvar->stack_b->num)
				operation = SB;
				// if (stvar->stack_b->num > stvar->stack_b->next->num && stvar->stack_b->num > stvar->stack_b->tail->num && stvar->stack_b->next->next->num < stvar->stack_b->num)
				// 	operation = RB;
				if (current->num <= stvar->median)
					operation = NULL;
			}
		}
		else if (ret == bottom && ret != top_next)
			operation = RB;
		if (operation != NULL)
			do_op(stvar, operation, 'b', 1);
	}
	return (operation);
}

// ** checks the distance between top with next, next->next and bottom number**
// ** depending on smallest distance either stays put, swaps or rotates current number** 
// ** orders list in this way somewhat **
// char	*find_solution(t_pw_var *stvar, t_stack *current, char *oper)
// {
// 	int top_next;
// 	int top_next_next;
// 	int bottom;
// 	int	ret;

// 	if (stvar->stack_b != NULL && stvar->stack_b->next != NULL)
// 	{
// 		int i;

// 		i = 0;
// 		bottom = stvar->stack_b->tail->num;
// 		top_next = stvar->stack_b->next->num;
// 		if (stvar->stack_b->next->next != NULL)
// 			top_next_next = stvar->stack_b->next->next->num;
// 		bottom = ft_abs(current->num - bottom);
// 		top_next = ft_abs(current->num - top_next);
// 		top_next_next = ft_abs(current->num - top_next_next);
// 		// ft_printf(GRN"bottom dist:%i, top->next dist:%i\n"RESET, bottom, top_next);
// 		ret = top_next;
// 		// ft_printf("top_next:%i\n", top_next);
// 		// if (stvar->stack_b->next->next != NULL)
// 		// 	ft_printf("top_next_next:%i\n", top_next_next);
// 		// ft_printf("bottom:%i\n", bottom);
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
// 			// print_stack_b(&stvar->stack_b, 1);
// 			// ft_printf("SWAP\n");
// 			if (current->num <= stvar->median)
// 				return (NULL);
// 			if (oper == SA)
// 				return (RRR);
// 			do_op(stvar, SB, 'b', 1);
// 			return (SB);
// 		}
// 		// && ret != top_next
// 		// ft_printf("ret is:%i\n", ret);
// 		else if (ret == bottom && ret != top_next)
// 		{
// 			if (oper == RR)
// 				i = stvar->index - current->dist_top;
// 			// if (current->num >= stvar->median)
// 			// 	return (NULL);
// 			// ft_printf("ROT\n");
// 			do_op(stvar, RB, 'b', 1);
// 			// print_stack_list(stvar->stack_b, 'b');
// 			return (RB);
// 		}
// 	}
// 	return (NULL);
// }

void	sort_based_on_top(t_pw_var *stvar, t_stack *top)
{
	char	*instr;
	int		rest;
	int		i;

	instr = fastest_rotate(stvar, 'a', &top->dist_top);
	// ft_printf("instr is:%s\tnum is:%i\n", instr, top->dist_top);
	if (ft_strnequ(instr, RR, 2))
		i = stvar->index - top->dist_top;
	else
	{
		// i = stvar->index - top->dist_top;
		i = top->dist_top;
	}
	// rest = presort_stack_b(stvar, top, instr, i);
	if (rest > 0)
	{
		// ft_printf(YEL"do_op rest INSTR:%s NUM:%i\n"RESET, instr, rest);
		do_op(stvar, instr, 'a', rest);
	}
}

void	sort_based_on_bottom(t_pw_var *stvar, t_stack *bottom)
{
	char	*instr;
	int		rest;
	int		i;

	rest = 0;
	instr = fastest_rotate(stvar, 'a', &bottom->dist_top);
	// if (ft_strnequ(instr, RR, 2))
	// 	i = stvar->index - bottom->dist_top;
	// else
	i = bottom->dist_top;
	// rest = presort_stack_b(stvar, bottom, instr, i);
	if (rest > 0)
	{
		// ft_printf(YEL"do_op rest INSTR:%s NUM:%i\n"RESET, instr, rest);
		do_op(stvar, instr, 'a', rest);
	}
}

void	find_part(t_pw_var *stvar, int i)
{
	t_stack *bottom;
	t_stack *top;
	char	*instr;
	int ret;
	int j;

	j = 0;
	// ft_printf("in find part\n");
	top = find_top_part(stvar, i);
	// ft_printf(CYN"  top_num:%i part_id:%i dist_top:%i\n"RESET, top->num, top->part_id, top->dist_top);
	bottom = find_bottom_part(stvar, i);
	// ft_printf(CYN"  bottom-num:%i part_id:%i dist_top:%i\n"RESET, bottom->num, bottom->part_id, bottom->dist_top);
	ret = calc_shortest_dist_top(stvar, top, bottom);
	// ft_printf(CYN"dist_top < dist_bottom if ret == 0:%i\n"RESET, ret);
	if (ret == 0)
	{
		sort_top(stvar, top);
		// instr = fastest_rotate(stvar, 'a', top->dist_top);
		// print_stack_list(stvar->stack_a, 'a');
		// ft_printf("rotate\n");
		// do_op(stvar, instr, 'a', top->dist_top);
		// print_stack_list(stvar->stack_a, 'a');
		// ft_printf("push\n");
		// do_op(stvar, PB, 'b', 1);
		// print_stack_list(stvar->stack_a, 'a');
		// ft_printf("SORT BASED ON TOP:%i\n", top->num);
		// sort_based_on_top(stvar, top);
	}
	else if (ret != 0)
	{
		sort_bottom(stvar, bottom);
		// instr = fastest_rotate(stvar, 'a', bottom->dist_top);
		// print_stack_list(stvar->stack_a, 'a');
		// ft_printf("instr:%s i:%i\n", instr, bottom->dist_top);
		// ft_printf("rotate\n");
		// do_op(stvar, instr, 'b', bottom->dist_top);
		// print_stack_list(stvar->stack_a, 'a');
		// ft_printf("push\n");
		// do_op(stvar, PB, 'a', 1);
		// print_stack_b(&stvar->stack_b, 1);
		// print_stack_list(stvar->stack_a, 'a');
		// ft_printf("SORT BASED ON BOTTOM:%i\n", bottom->num);
		// sort_based_on_bottom(stvar, bottom);
	}
	// find_solution(stvar, stvar->stack_b, NULL);
	// ft_printf("finished\n");
	// if (i == 1)
	// 	j = presort_stack_b(stvar, top, NULL, 0);
}

// void	f_double_solution(t_pw_var *stvar, char *instr, int i)
// {
// 	// ft_printf("instr:%s i:%i\n", instr, i);
// 	if (ft_strnequ(instr, RR, 2))
// 	{
// 		// ft_printf("FOUND RRR\n");
// 		// print_stack_list(stvar->stack_a, 'a');
// 		// print_stack_list(stvar->stack_b, 'b');
// 		// ft_printf(CYN"INSTR:RRR num:%i\n"RESET, i);
// 		do_op(stvar, RRR, 'a', i);
// 		// print_stack_list(stvar->stack_b, 'b');
// 		// print_stack_list(stvar->stack_a, 'a');
// 	}
// 	else if (instr[0] == 'r')
// 	{
// 		// ft_printf("FOUND RR\n");
// 		// ft_printf(CYN"INSTR:RR num:%i\n"RESET, i);
// 		do_op(stvar, RR, 'a', i);
// 	}
// }

void	ft_double_oper_lst(t_inst **tail, char *oper, int tot, int j)
{
	t_inst *temp;
	char	*oper_b;
	char	*oper_a;

	temp = *tail;
	if (ft_strequ(oper, RRR))
	{
		oper_a = RRA;
		oper_b = RRB;
	}
	else if (ft_strequ(oper, RR))
	{
		oper_a = RA;
		oper_b = RB;
	}
	else if (ft_strequ(oper, SS))
	{
		oper_a = SA;
		oper_b = SB;
	}
	tot = 1;
	// ft_printf("temp->operation:%s oper_a:%s oper_b:%s oper:%s tot:%i j:%i\n", temp->operation, oper_a, oper_b, oper, tot, j);
	while (tot && temp)
	{
		// ft_printf("i:%i\n", i);
		// if (ft_strequ(temp->operation, oper_b))
		// {
		// 	// ft_printf("equal to oper_b\n");
		// 	// ft_printf("temp->operation:%s oper_b:%s j:%i\n", temp->operation, oper_b, j);
		// 	if (j > 0)
		// 		j--;
		// 	else while (!ft_strequ(temp->operation, oper_a))
		// 	{
		// 		temp = temp->prev;
		// 		// ft_printf("temp->operation:%s oper_a:%s\n", temp->operation, oper_a);
		// 	}
		// }
		// else
		// {
		// 	// ft_printf("equal to oper_a\n");
		// 	// ft_printf("temp->operation:%s oper_a:%s j:%i\n", temp->operation, oper_a, j);
		// 	if (j > 0)
		// 	{
		// 		while (!ft_strequ(temp->operation, oper_b))
		// 			temp = temp->prev;
		// 		// ft_printf("temp->operation:%s oper_a:%s\n", temp->operation, oper_a);
		// 		j--;
		// 	}
		// }
		// ft_printf("temp->operation:%s\n", temp->operation);
		ft_strcpy(temp->operation, oper);
		tot--;
		temp = temp->prev;
	}
}

void	f_double_solution(t_pw_var *stvar, char *instr, int i)
{
	t_inst 	*tail;
	t_inst	*prev;
	char	*operation;
	int		j;

	tail = stvar->inst_lst->tail;
	j = i;
	operation = NULL;
	// ft_printf("instr:%s i:%i\n", instr, i);
	if (ft_strnequ(instr, RR, 2))
	{
		// ft_printf(YEL"FOUND RRR i:%i\n"RESET, i);
		operation = RRR;
	}
	else if (instr[0] == 'r')
	{
		// ft_printf(BLU"FOUND RR\n"RESET, i);
		operation = RR;
	}
	// else if (instr[0] == 's')
	// {
	// 	// ft_printf(MAG"FOUND SS\n"RESET, i);
	// 	operation = SS;
	// 	// ft_double_oper_lst(&stvar->inst_lst->tail, SS, i, j);
	// }
	if (operation != NULL)
	{
		// print_inst_list(stvar->inst_lst);
		// print_tail_inst(stvar->inst_lst->tail);
		tail = inst_tail_delone(&(stvar)->inst_lst->tail, instr, i, &j);
		// ft_printf("j is:%i\n", j);
		// print_inst_list(stvar->inst_lst);
		ft_double_oper_lst(&stvar->inst_lst->tail, operation, i, j);
		// print_inst_list(stvar->inst_lst);
	}
}

// void	check_list(t_pw_var *stvar, char *oper_b, int i)
// {
// 	t_inst *temp;
// 	int		i;

// 	temp = stvar->inst_lst;
// 	if (ft_strnequ(oper_b, RR, 2))
// 	{
// 		ft_printf("FOUND RRR i:%i\n", i);
// 		while (temp->prev != NULL && ft_strnequ(temp->prev->operation, RRA, 3))
// 		{
// 			i++;
// 			temp = temp->prev;
// 		}

// 		// print_stack_list(stvar->stack_a, 'a');
// 		// print_stack_list(stvar->stack_b, 'b');
// 		// ft_printf(CYN"INSTR:RRR num:%i\n"RESET, i);
// 		// do_op(stvar, RRR, 'a', i);
// 		// print_stack_list(stvar->stack_b, 'b');
// 		// print_stack_list(stvar->stack_a, 'a');
// 	}
// 	else if (oper_b[0] == 'r')
// 	{

// 	}
// 	else if (ft_strnequ(oper_b, SB, 2)
// 	{

// 	}

int		check_dble(t_pw_var *stvar, char *oper_a, char *oper_b, int tot)
{
	int ret;

	ret = 0;
	// ft_printf("INSIDE CHECK_DBLE\n");
	// if (oper_a && oper_b)
	// 	ft_printf(GRN"oper_a:%s oper_b:%s tot:%i\n"RESET, oper_a, oper_b, tot);
	if ((ft_strequ(oper_a, RRA) && ft_strequ(oper_b, RRB)) || (ft_strequ(oper_a, RA)
		&& ft_strequ(oper_b, RB)) || (ft_strequ(oper_a, SA) && ft_strequ(oper_b, SB)))
		ret = tot;
	else
		ret = -1;
		// check_list(stvar, oper_b, i);
	// ft_printf("ret is:%i\n", ret);
	if (ret > 0)
		f_double_solution(stvar, oper_b, ret);
	return (ret);
}



// int		check_dble(t_pw_var *stvar, char *oper_a, char *oper_b, int tot)
// {
// 	int ret;

// 	ret = 0;
// 	if (oper_a && oper_b)
// 		// ft_printf(GRN"oper_a:%s oper_b:%s tot:%i\n"RESET, oper_a, oper_b, tot);
// 	if ((ft_strequ(oper_a, RRA) && ft_strequ(oper_b, RRB)) || (ft_strequ(oper_a, RA)
// 		&& ft_strequ(oper_b, RB)))
// 		ret = tot;
// 	else
// 		ret = -1;
// 	// ft_printf("ret is:%i\n", ret);
// 	if (ret > 0)
// 		f_double_solution(stvar, oper_b, ret);
// 	return (ret);
// }
