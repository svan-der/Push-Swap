/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_solution.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 17:14:33 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/16 00:08:12 by svan-der      ########   odam.nl         */
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

// ** checks the distance between top with next, next->next and bottom number**
// ** depending on smallest distance either stays put, swaps or rotates current number** 
// ** orders list in this way somewhat **
char	*find_solution(t_pw_var *stvar, t_stack *current, char *oper)
{
	int top_next;
	int top_next_next;
	int bottom;
	int	ret;

	if (stvar->stack_b != NULL && stvar->stack_b->next != NULL)
	{
		int i;

		i = 0;
		bottom = stvar->stack_b->tail->num;
		top_next = stvar->stack_b->next->num;
		if (stvar->stack_b->next->next != NULL)
			top_next_next = stvar->stack_b->next->next->num;
		print_stack_b(&stvar->stack_b, 1);
		ft_printf(YEL"top:%i, bottom:%i, top->next:%i\n"RESET, stvar->stack_b->num, bottom, top_next);
		bottom = ft_abs(current->num - bottom);
		top_next = ft_abs(current->num - top_next);
		top_next_next = ft_abs(current->num - top_next_next);
		ft_printf(GRN"bottom dist:%i, top->next dist:%i\n"RESET, bottom, top_next);
		ret = top_next;
		ft_printf("ret is:%i\n", ret);
		ft_printf("top_next:%i\n", top_next);
		if (stvar->stack_b->next->next != NULL)
			ft_printf("top_next_next:%i\n", top_next_next);
		ft_printf("bottom:%i\n", bottom);
		if (stvar->stack_b->next->next != NULL && ret > top_next_next)
		{
			ret = top_next_next;
			ft_printf("ret is:%i\n", ret);
		}
		if (ret > bottom)
		{
			ret = bottom;
			ft_printf("ret is:%i\n", ret);
		}
		ft_printf("ret is:%i\n", ret);
		if (ret == bottom && ret != stvar->stack_b->num && ret != top_next)
		{
			if (oper == RR)
				i = stvar->index - current->dist_top;
			// if (i == 1)
			// 	return (RRR);
			ft_printf("ROT\n");
			do_op(stvar, RB, 'b', 1);
			return (RR);
		}
		else if (stvar->stack_b->next->next != NULL && ret == top_next_next && ret != top_next)
		{
			print_stack_b(&stvar->stack_b, 1);
			ft_printf("SWAP\n");
			if (oper)
				ft_printf("oper:%s\n", oper);
			if (oper == SA)
				return (RRR);
			do_op(stvar, SB, 'b', 1);
		}
	}
	return (NULL);
}

void	sort_based_on_top(t_pw_var *stvar, t_stack *top)
{
	char 	*instr;
	int		rest;
	int		i;

	instr = fastest_rotate(stvar, 'a', top->dist_top);
	// ft_printf("instr is:%s\tnum is:%i\n", instr, top->dist_top);
	if (ft_strnequ(instr, RR, 2))
		i = stvar->index - top->dist_top;
	else
	{
		// i = stvar->index - top->dist_top;
		i = top->dist_top;
	}
	rest = presort_stack_b(stvar, top, instr, i);
	if (rest > 0)
	{
		ft_printf(YEL"do_op rest INSTR:%s NUM:%i\n"RESET, instr, rest);
		do_op(stvar, instr, 'a', rest);
	}
}

void	sort_based_on_bottom(t_pw_var *stvar, t_stack *bottom)
{
	char	*instr;
	int		rest;
	int		i;

	rest = 0;
	instr = fastest_rotate(stvar, 'a', bottom->dist_top);
	if (ft_strnequ(instr, RR, 2))
		i = stvar->index - bottom->dist_top;
	else
		i = bottom->dist_top;
	rest = presort_stack_b(stvar, bottom, instr, i);
	if (rest > 0)
	{
		ft_printf(YEL"do_op rest INSTR:%s NUM:%i\n"RESET, instr, rest);
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
	ft_printf(CYN"  top_num:%i part_id:%i dist_top:%i\n"RESET, top->num, top->part_id, top->dist_top);
	bottom = find_bottom_part(stvar, i);
	ft_printf(CYN"  bottom-num:%i part_id:%i dist_top:%i\n"RESET, bottom->num, bottom->part_id, bottom->dist_top);
	ret = calc_shortest_dist_top(stvar, top, bottom);
	ft_printf(CYN"ret is:%i\n"RESET, ret);
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
		ft_printf("SORT BASED ON TOP:%i\n", top->num);
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
	ft_printf("finished\n");
	// if (i == 1)
	// 	j = presort_stack_b(stvar, top, NULL, 0);
}

void	f_double_solution(t_pw_var *stvar, char *instr, int i)
{
	ft_printf("instr:%s i:%i\n", instr, i);
	if (ft_strnequ(instr, RR, 2))
	{
		ft_printf("FOUND RRR\n");
		print_stack_list(stvar->stack_a, 'a');
		print_stack_list(stvar->stack_b, 'b');
		ft_printf(CYN"INSTR:RRR num:%i\n"RESET, i);
		do_op(stvar, RRR, 'a', i);
		print_stack_list(stvar->stack_b, 'b');
		print_stack_list(stvar->stack_a, 'a');
	}
	else if (instr[0] == 'r')
	{
		ft_printf("FOUND RR\n");
		ft_printf(CYN"INSTR:RR num:%i\n"RESET, i);
		do_op(stvar, RR, 'a', i);
	}
}

int		check_dble(t_pw_var *stvar, char *oper_a, char *oper_b, int tot)
{
	int ret;

	ret = 0;
	// ft_printf(GRN"oper_a:%s oper_b:%s tot:%i\n"RESET, oper_a, oper_b, tot);
	if ((ft_strequ(oper_a, RRA) && ft_strequ(oper_b, RRB)) || (ft_strequ(oper_a, RA)
		&& ft_strequ(oper_b, RB)))
		ret = tot;
	// ft_printf("ret is:%i\n", ret);
	if (ret > 0)
		f_double_solution(stvar, oper_b, ret);
	return (ret);
}
