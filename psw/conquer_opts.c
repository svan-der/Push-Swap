/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer_opts.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:49:34 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/11 09:24:17 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/psw_env.h"

void insertion_sort(int *list, int argc, int *min, int *max)
{
	int i;
	int j;
	int temp;

	i = 1;
	while (i < argc)
	{
		temp = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > temp)
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = temp;
		i++;
	}
	if (argc >= 3)
	{
		*min = list[argc - 3];
		*max = list[argc - 1];
	}
	if (argc == 2)
	{
		*min = list[argc - 2];
		*max = list[argc - 1];
	}
	// print_array(list, argc);
}

/**
*** calculates if either the top or bottom is nearest to the top number in stack b
*** apart from checken absolute values also need to check the distance
**/

int	 calc_dist_top_b(t_pw_var *stvar, t_stack *top, t_stack *bottom)
{
	t_stack *current;
	int dist_top;
	int dist_bottom;
	int len;
	int i;

	if (stvar->stack_b == NULL)
		return (0);
	// print_stack_list(stvar->stack_b, 'b');
	// print_stack_list(stvar->stack_a, 'a');
	current = stvar->stack_b;
	// ft_printf("actual index order calculate closest to dist top b\n");
	len = stvar->index;
	i = (len % 2) ? ((len / 2) + 1) : len / 2;
	if (bottom->dist_top > i)
		dist_bottom = stvar->index - bottom->dist_top;
	else
		dist_bottom = bottom->dist_top;
	if (top->dist_top > i)
		dist_top = stvar->index - top->dist_top;
	else
		dist_top = top->dist_top;
	// ft_printf("num %i index:%i dist_top:%i top:%i\n", bottom->num, bottom->index, bottom->dist_top, bottom->dist);
	// ft_printf("dist bottom:%i\n", dist_bottom);

	// ft_printf("num:%i top->dist in stack_b:%i absolute dist_top:%i\n", top->num, top->dist, dist_top);
	// ft_printf("dist top:%i\n", dist_top);
	if (dist_top == dist_bottom)
	{
		// print_stack_list(stvar->stack_a, 'a');
		// ft_printf(YEL"num:%i top->dist_top:%i bottom->dist_top:%i\n"RESET, top->num, top->dist_top, bottom->dist_top);
		if (top->dist_top < bottom->dist_top)
			return (0);
		return (1);
	}
	if (dist_top < dist_bottom)
		return (0);
	return (1);
}

t_stack	*find_bottom_part(t_pw_var *stvar, int i)
{
	t_stack *temp;
	int		j;

	temp = stvar->stack_a->tail;
	// ft_printf("find bottom\n");
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

char	*find_solution(t_pw_var *stvar, t_stack *current, char *oper)
{
	int top;
	int top_next;
	int bottom;
	int	ret;

	if (stvar->stack_b != NULL && stvar->stack_b->next != NULL)
	{
		int i;

		i = 0;
		top = stvar->stack_b->num;
		bottom = stvar->stack_b->tail->num;
		top_next = stvar->stack_b->next->num;
		// print_stack_list(stvar->stack_b, 'b');
		// ft_printf("current->num:%i\n", current->num);
		// ft_printf(YEL"top:%i, bottom:%i, top->next:%i\n"RESET, top, bottom, top_next);
		top = ft_abs(current->num - top);
		bottom = ft_abs(current->num - bottom);
		top_next = ft_abs(current->num - top_next);
		// ft_printf(GRN"top dist:%i, bottom dist:%i, top->next dist:%i\n"RESET, top, bottom, top_next);
		ret = top;
		if (ret > top_next)
			ret = top_next;
		if (ret > bottom)
			ret = bottom;
		// ft_printf("ret is:%i\n", ret);
		if (ret == top_next && ret != top)
		{
			// ft_printf("SWAP\n");
			if (oper == SA)
				return (RRR);
			do_op(stvar, SB, 'b', 1);
		}
		else if (ret == bottom && ret != top)
		{
			if (oper == RR)
				i = stvar->index - current->dist_top;
			if (i == 1)
				return (RRR);
			// ft_printf("REVERSE ROT\n");
			do_op(stvar, RRB, 'b', 1);
			return (RR);
		}
	}
}

void	find_part(t_pw_var *stvar, int i)
{
	t_stack *bottom;
	t_stack *top;
	int ret;
	char *instr;

	// ft_printf("in find part\n");
	top = find_top_part(stvar, i);
	// ft_printf(CYN"  top_num:%i part_id:%i dist_top:%i\n"RESET, top->num, top->part_id, top->dist_top);
	bottom = find_bottom_part(stvar, i);
	// ft_printf(CYN"  bottom-num:%i part_id:%i dist_top:%i\n"RESET, bottom->num, bottom->part_id, bottom->dist_top);
	if (stvar->stack_b != NULL)
	ret = calc_dist_top_b(stvar, top, bottom);
	// if (top->num < bottom->num && stvar->stack_b == NULL)
	// if (top->num < bottom->num)
	// 	ret = 1;
	// else
	// 	ret = 0;
	// }
	// ret = 0;
	// ft_printf(CYN"ret is:%i\n"RESET, ret);
	if (ret == 0)
	{
		instr = fastest_rotate(stvar, 'a', top->dist_top);
		// ft_printf("instr is:%s\tnum is:%i\n", instr, top->dist_top);
		if (ft_strnequ(instr, RR, 2))
		{
			// find_solution(stvar, top, RR);
			//instr = check_double(stvar, instr, stvar->index - top->dist_top, top);
			// ft_printf("instr is:%s\tnum is:%i\n", instr, top->dist_top);
			presort_stack_b(stvar, top, instr, stvar->index - top->dist_top);
			// do_op(stvar, instr, 'a', stvar->index - top->dist_top);
		}
		else
		{
			// find_solution(stvar, top, instr);
			presort_stack_b(stvar, top, instr, top->dist_top);
			//instr = check_double(stvar, instr, top->dist_top, top);
			// do_op(stvar, instr, 'a', top->dist_top);
		}
	}
	else if (ret != 0)
	{
		instr = fastest_rotate(stvar, 'a', bottom->dist_top);
		if (ft_strnequ(instr, RR, 2))
		{
			// find_solution(stvar, bottom, instr);
			presort_stack_b(stvar, bottom, instr, stvar->index - bottom->dist_top);
			//instr = check_double(stvar, instr, stvar->index - bottom->dist_top, bottom);
			// do_op(stvar, instr, 'a', stvar->index - bottom->dist_top);
		}
		else
		{
			// find_solution(stvar, bottom, instr);
			presort_stack_b(stvar, bottom, instr, bottom->dist_top);
			//instr = check_double(stvar, instr, bottom->dist_top, bottom);
			// do_op(stvar, instr, 'a', bottom->dist_top);
		}
		// ft_printf("instr is:%s\tnum is:%i\n", instr, bottom->dist_top);
	}
	if (ret == 1)
	{
	// 	// find_solution(stvar, top, NULL);
		presort_stack_b(stvar, top, NULL, 0);
	}
	do_op(stvar, PB, 'b', 1);
	// ft_printf("after finding part\n");
	// print_stack_list(stvar->stack_b, 'b');
	// print_stack_list(stvar->stack_a, 'a');
}

t_stack *return_bottom_position(t_pw_var *stvar, t_stack *temp, char *instr, int i)
{
	t_stack *bottom;
	int		j;

	j = 1;
	bottom = stvar->stack_b->tail;
	if (temp->num && stvar->stack_b->next)
	{
		while (bottom && j < i)
		{
			bottom = bottom->prev;
			if (bottom == NULL)
				bottom = stvar->stack_b->tail;
			j++;
		}
	}
	return (bottom);
}

t_stack *return_top_position(t_pw_var *stvar, t_stack *temp, char *instr, int i)
{
	t_stack *top;
	int		j;

	j = 1;
	top = stvar->stack_b;
	while (j < i && temp)
	{
		temp = temp->next;
		j++;
		if (temp == NULL)
			temp = stvar->stack_b;
	}
	if (temp->num && stvar->stack_b->next)
	{
		if (temp->next)
			top = temp->next;
		else
			top = stvar->stack_b;
	}
	return (top);
}

char	*check_double(t_pw_var *stvar, char *instr, int i, t_stack *current)
{
	t_stack *temp;
	t_stack *bottom;
	t_stack	*top;

	temp = stvar->stack_b;
	if (instr == RA)
	{
		if (temp && temp->next)
		{
			// ft_printf(YEL"IN CHECK DOUBLE %s %i\n", instr, i);
			top = return_top_position(stvar, temp, instr, i);
			// ft_printf("top:%i top next:%i\n", temp->num, top->num);
			if (temp->num < top->num)
				instr = RR;
		}
	}
	else if (instr == RRA)
	{
		if (temp && temp->tail)
		{
			bottom = return_bottom_position(stvar, temp, instr, i);
			// ft_printf("top:%i top next:%i\n", temp->num, bottom->num);
			if (bottom->num > temp->num)
				instr = RRR;
		}
	}
	// ft_printf("INSTR:%s\n"RESET, instr);
	return (instr);
}

int		check_dble(char *oper_a, int i, char *oper_b, int j)
{
	int ret;

	ret = 0;
	if (oper_b == RB && oper_a == RA)
		ret = ft_min(i, j);
	if (oper_b == RRB && oper_a == RRA)
		ret = ft_min(i, j);
	return (ret);
}

void	f_solution(t_pw_var *stvar, char *instr, int i, int rest)
{
	char c;

	if (ft_strnequ(instr, RR, 2))
	{
		if (i > 0)
			do_op(stvar, RRR, 'a', i);
		if (rest > 0)
		{
			instr = (ft_strnequ(instr, RRA, 3)) ? RRA : RRB;
			c = (instr == RRA) ? 'a' : 'b';
			if (rest > 0)
				do_op(stvar, instr, c, rest);
		}
	}
	else if (ft_strnequ(instr, "R", 1))
	{
		if (i > 0)
			do_op(stvar, RR, 'a', i);
		if (rest > 0)
		{
			instr = (ft_strnequ(instr, RA, 2)) ? RA : RB;
			c = (instr == RA) ? 'a' : 'b';
			if (rest > 0)
				do_op(stvar, instr, c, rest);
		}
	}
}

void	presort_stack_b(t_pw_var *stvar, t_stack *current, char *oper_a, int i)
{
	t_stack *temp;
	char	*instr;
	int		j;
	int		ret;
	char	c;

	j = 0;
	temp = stvar->stack_b;
	instr = RB;
	if (temp && temp->next)
	{
		set_min_max(stvar, 'b');
		//  ft_printf("min:%i max:%i current:%i\n", stvar->min, stvar->max, current->num);
		if (current->num < stvar->min)
		{
			// ft_printf("SMALLER THAN MIN\n");
			while (temp && temp->num != stvar->min)
			{
				j++;
				temp = temp->next;
			}
		}
		else if (current->num > stvar->max)
		{
			// ft_printf("BIGGER THAN MAX\n");
			while (temp && temp->num != stvar->max)
			{
				j++;
				temp = temp->next;
			}
		}
		else if (current->num > stvar->min && current->num < stvar->max)
		{
			while (temp && temp->next)
			{
				if (temp->num > current->num && temp->next->num < current->num)
				{
					instr = fastest_rotate(stvar, 'b', ((stvar->argc - stvar->index) - j));
					// ft_printf(YEL"INSL:%s J:%i\n"RESET, instr, j);
					break ;
				}
				j++;
				temp = temp->next;
			}
		}
		if (j > 0)
		{
			instr = fastest_rotate(stvar, 'b', j);
			ret = check_dble(oper_a, i, instr, j);
		}
		// print_stack_list(stvar->stack_b, 'b');
		ft_printf(YEL"RET:%i OPER_A:%s INS:%s I:%i J:%i\n"RESET, ret, oper_a, instr, i, j);
		instr = (j > 0 && j > i) ? instr : oper_a;
		f_solution(stvar, instr, ret, (ft_min(i, j)));
		// if (j > 0)
		// 	do_op(stvar, instr, 'b', j);
	}
}

void	sort_top_bottom(t_pw_var *stvar, int i, t_stack *top, t_stack *bottom)
{
	char *instr;

	if (i != 0)
	{
		// ft_printf("bottom dist_top:%i\n", bottom->dist_top);
		instr = fastest_rotate(stvar, 'a', bottom->dist_top);
		if (ft_strnequ(instr, RR, 2))
		{
			// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, stvar->index - bottom->dist_top);
			// find_solution(stvar, bottom, RR);
			presort_stack_b(stvar, bottom, instr, stvar->index - bottom->dist_top);
			// instr = check_double(stvar, instr, stvar->index - bottom->dist_top, bottom);
			// do_op(stvar, instr, 'a', stvar->index - bottom->dist_top);
		}
		else
		{
			// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, bottom->dist);
			// find_solution(stvar, bottom, instr);
			presort_stack_b(stvar, bottom, instr, bottom->dist_top);
			// instr = check_double(stvar, instr, bottom->dist_top, bottom);
			// do_op(stvar, instr, 'a', bottom->dist_top);
		}
		if (i == 1)
		{
			// find_solution(stvar, top, NULL);
			presort_stack_b(stvar, top, NULL, 0);
		}
		// presort_stack_b(stvar, top, NULL, 0);
		ft_printf("instr is:%s\n", instr);
	}
}

void	sort_bottom(t_pw_var *stvar, t_stack *bottom)
{
	char *instr;

	instr = fastest_rotate(stvar, 'a', bottom->dist_top);
	// ft_printf(RED"instr is:%s\n"RESET, instr);
	if (ft_strnequ(instr, RR, 2))
	{
		// ft_printf("i is:%i\n", stvar->index - bottom->dist_top);
		// find_solution(stvar, bottom, RR);
		presort_stack_b(stvar, bottom, instr, stvar->index - bottom->dist_top);
		// instr = check_double(stvar, instr, stvar->index - bottom->dist_top, bottom);
		// do_op(stvar, instr, 'a', stvar->index - bottom->dist_top);
	}
	else
	{
		// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, bottom->dist);
		// find_solution(stvar, bottom, instr);
		presort_stack_b(stvar, bottom, instr, bottom->dist_top);
		// instr = check_double(stvar, instr, bottom->dist_top, bottom);
		// do_op(stvar, instr, 'a', bottom->dist_top);
	}
	ft_printf("instr is:%s\n", instr);
}

void	part_sort(t_pw_var *stvar, int argc, int i)
{
	char *instr;
	int j;
	t_stack *top;
	t_stack *bottom;
	int res;

	j = argc;
	while (j)
	{
		res = 0;
		top = stvar->stack_a;
		// ft_printf(GRN"|i:%i top:%i part_id:%i top->index:%i|\n"RESET, i, top->num, top->part_id, top->index);
		bottom = stvar->stack_a->tail;
		// ft_printf(YEL"|i:%i bottom:%i part_id:%i bottom->index:%i|\n"RESET, i, bottom->num, bottom->part_id, bottom->index);
		if (top->part_id == i || bottom->part_id == i)
		{
			if (top->part_id == i && bottom->part_id == i)
			{
				ft_printf(CYN"OPTION 1\n"RESET);
				if (j != 1)
					res = calc_dist_top_b(stvar, top, bottom);
				sort_top_bottom(stvar, res, top, bottom);
				// print_stack_list(stvar->stack_b, 'b');
			}
			else if (bottom->part_id == i)
			{
				ft_printf(YEL"OPTION 2\n"RESET);
				sort_bottom(stvar, bottom);
			}
			do_op(stvar, (instr = PB), 'b', 1);
			print_stack_list(stvar->stack_b, 'b');
		}
		else if (top->part_id != i && bottom->part_id != i)
		{
			ft_printf(RED"OPTION 3\n"RESET);
			find_part(stvar, i);
			instr = PB;
			print_stack_list(stvar->stack_b, 'b');
		}
		// ft_printf("instr:%s\n", instr);
		if (ft_strequ(instr, PB))
			j--;
		print_stack_list(stvar->stack_a, 'a');
		// print_stack_list(stvar->stack_b, 'b');
	}
}

int		do_op(t_pw_var *stvar, char *str, char c, int num)
{
	int i;
	int ret;

	i = 0;
	// ft_printf("\e[1;37m num op:%i\n", num);
	// ft_printf("instr is:%s\n", str);
	while (i < num)
	{
		// if (str == PA)
		// 	print_stack_b(&stvar->stack_b, 1);
		// ft_printf("i is:%d\n", i);
		ret = dispatch_sort(stvar, str, 1);
		// print_tail(stvar->stack_a->tail);
		// print_stack(&stvar->stack_a, 1);
		// print_stack_list(stvar->stack_a, 'a');
		// print_stack_list(stvar->stack_b, 'b');
		// if (str == PB)
			// ft_printf("return is:%i\n", ret);
		if (ret == -1)
			return (-1);
		update_stack(stvar, 'a');
		update_stack(stvar, 'b');
		set_index(&stvar->stack_a, stvar->sorted, stvar->index);
		set_index(&stvar->stack_b, stvar->sorted, stvar->argc - stvar->index);
		i++;
	}
	return (ret);
}

int		sort_three_revpart(t_stack **temp, t_pw_var *stvar, int min, int max)
{
	t_stack *stack;

	stack = *temp;
	// ft_printf("stack->num:%i\tnext:%i\n", stack->num, stack->next->num);
	if ((stack->num) == min && (stack->next->num) != max)
		return (do_op(stvar, RB, 'b', 1) && do_op(stvar, SB, 'b', 1));
	if ((stack->num) == min && (stack->next->num) == max)
		return (do_op(stvar, RB, 'b', 1));
	if ((stack->num) == max && (stack->next->num) == min)
		return (do_op(stvar, RRB, 'b', 1) && do_op(stvar, SB, 'b', 1));
	if ((stack->num) == max && (stack->next->num) != min)
		return (do_op(stvar, NULL, 'b', 0));
	if ((stack->next->num) == max)
		return (do_op(stvar, SB, 'b', 1));
	if ((stack->next->num) == min)
		return (do_op(stvar, RRB, 'b', 1));
	// ft_printf("three are now sorted!!!\n\n");
	return (0);
}

// int		sort_three_revpart(t_stack **temp, t_pw_var *stvar, int min, int max)
// {
// 	t_stack *stack;
// 	int	a;
// 	int	b;
// 	int	c;

// 	stack = *temp;
// 	a = stack->num;
// 	b = stack->next->num;
// 	c = stack->next->next->num;
// 	ft_printf("a->num is:%d\n", a);
// 	ft_printf("b->num is:%d\n", b);
// 	ft_printf("c->num is:%d\n", c);
// 	if ((a > b) && (b > c))
// 	{
// 		dispatch_sort(stvar, RA, 1);
// 		dispatch_sort(stvar, SA, 1);
// 	}
// 	else if ((a < b->num) && (b->num > c) && (c < a->num))
// 		dispatch_sort(stvar, RRA, 1);
// 	else if ((a->num < b->num) && (b->num > c->num) && (c->num > a->num))
// 	{
// 		dispatch_sort(stvar, SA, 1);
// 		dispatch_sort(stvar, RA, 1);
// 	}
// 	else if ((a->num > b->num) && (b->num < c->num) && (c->num > a->num))
// 	{
// 		ft_printf("goes in SA\n");
// 		dispatch_sort(stvar, SA, 1);
// 	}
// 	else if ((a->num > b->num) && (b->num < c->num) && (c->num < a->num))
// 		dispatch_sort(stvar, RA, 1);
// 	return (0);
// }

void	sort_two(char c, t_pw_var *stvar)
{
	t_stack *temp;
	if (c == 'a')
	{
		temp = stvar->stack_a;
		// ft_printf("num is:%i\n", temp->num);
		if (temp->num > temp->next->num)
			do_op(stvar, SA, c, 1);
	}
	if (c == 'b')
	{
		temp = stvar->stack_b;
		if (temp->num > temp->next->num)
			do_op(stvar, SB, c, 1);
	}
}

void	sort_short(t_pw_var *stvar, char c, int stack_len)
{
	t_stack *stack;

	if (c == 'a')
		stack = stvar->stack_a;
	else
		stack = stvar->stack_b;
	if ((stvar->argc - stvar->index == 3))
	{
		// sort_three_revpart(&stack, stvar, stvar->min, stvar->max);
		do_op(stvar, PA, c, 3);
	}
	else if (stack_len == 2)
	{
		sort_two(c, stvar);
		do_op(stvar, PA, c, 2);
	}
	else
		dispatch_sort(stvar, PA, 1);
}

char	*fastest_rotate(t_pw_var *stvar, char c, int index)
{
	int i;
	int len;

	len = (c == 'a') ? stvar->index : (stvar->argc - stvar->index);
	// i = (len % 2) ? ((len + 1) / 2) : len / 2;
	i = (len % 2) ? ((len / 2) + 1) : len / 2;
	// ft_printf("len:%i\t i:%i\n", len, i);
	// ft_printf("char:%c\tindex:%i\n", c, index);
	// if (index <= i)
	if (index < i)
		return (c == 'a' ? RA : RB);
	else
		return (c == 'a' ? RRA : RRB);
}

void	update_stack(t_pw_var *stvar, char c)
{
	t_stack *temp;

	// ft_printf("c is:%c\n", c);
	if (c == 'a')
		temp = stvar->stack_a;
	if (c == 'b')
		temp = stvar->stack_b;
	// ft_printf("temp:%p\n", temp);
	// ft_printf("temp:%p\tnum:%i\n", temp, temp->num);
	// print_stack_list(stvar->stack_b, 'b');
	if (c == 'a')
	{
		while (temp != NULL && temp->next != NULL)
		{
			// ft_printf("temp:%p\tnum:%i\n", temp, temp->num);
			// print_stack_list(stvar->stack_a, 'a');
			// print_array(stvar->sorted, stvar->index);
			find_distance(temp, temp->num, stvar->sorted);
			temp = temp->next;
		}
	}
	add_tail(&stvar->stack_a);
	add_tail(&stvar->stack_b);
	// print_tail(stvar->stack_a->tail);
	// if (stvar->stack_b)
	// 	print_tail(stvar->stack_b->tail);
}

// void	find_distance_part(t_stack **stack_a, int num)
// {
// 	t_stack *temp;
// 	int dist;
// 	int i;
// 	int j;

// 	temp = *stack_a;
// 	i = 0;
// 	j = 0;
// 	while (temp != NULL && temp->num != num)
// 	{
// 		temp = temp->next;
// 		j++;
// 	}
// 	while (sorted[i] != num)
// 		i++;
// 	dist = j - i;
// 	ft_printf("j:%i\t\ti:%i\tdist:%i\n", j, i, dist);
// 	(*stack_a)->dist = dist;
// 	ft_printf("num:%i\tdist is:%d\n", (*stack_a)->num, (*stack_a)->dist);
// }

void	find_dist_top(t_stack *stack, int num)
{
	t_stack *temp;
	int		j;

	temp = stack;
	j = 0;
	while (temp)
	{
		if (temp->num == num)
		{
			temp->dist_top = j;
			// ft_printf("dist_top:%i\n", temp->dist_top);
			return ;
		}
		temp = temp->next;
		j++;
	}
}

void	find_distance(t_stack *stack, int num, int *sorted)
{
	t_stack *temp;
	int i;
	int j;

	temp = stack;
	i = 0;
	j = 0;
	while (temp != NULL && temp->num != num)
	{
		temp = temp->next;
		j++;
	}
	// ft_printf(YEL"temp->dist_top:%i\n"RESET, temp->dist_top);
	while (sorted[i] != num)
		i++;
	temp->dist = j - i;
	temp->dist_top = j;
	// ft_printf(CYN"|num:%i\tdist:%i\n|"RESET, temp->num, dist);
	// ft_printf("j:%i\t\ti:%i\tdist:%i\tindex:%i\n", j, i, dist, temp->index, temp->num);
	stack = temp;
	// ft_printf("num:%i\tdist is:%d\n", (stack_a)->num, (stack_a)->dist);
}

char	*find_low(t_pw_var *stvar, char c, int *index)
{
	t_stack	*current;
	int		dist_top;

	current = (c == 'a') ? stvar->stack_a : stvar->stack_b;
	// print_stack_list(current, c);
	// ft_printf("index find low:%i\n", *index);
	dist_top = 0;
	while (current)
	{
		if (current->index == *index)
			break ;
		dist_top++;
		current = current->next;
	}
	// ft_printf("dist_top is:%d\n", dist_top);
	if (dist_top == 0)
	{
		*index = ((c == 'a')) ? *index + 1 : *index - 1;
		return ((c == 'a') ? PB : PA);
	}
	else
	{
		if (dist_top == 1)
			return (c == 'a' ? SA : SB);
		return (fastest_rotate(stvar, c, dist_top));
	}
}

int			sort_short_stack(t_pw_var *stvar, int argc)
{
	int ret;
	int j;

	ret = 1;
	j = (argc % 2) ? ((argc + 1) / 2) : argc / 2;
	argc = j;
	// print_stack_list(stvar->stack_a, 'a');
	while (stvar->index != j)
	{
		if (stvar->stack_a->num < stvar->median)
			ret = do_op(stvar, PB, 'a', 1);
		else
			ret = do_op(stvar, RA, 'a', 1);
	}
	// print_stack_list(stvar->stack_b, 'b');
	// ft_printf("argc:%i\tindex:%i\tsort_index:%i\n", stvar->argc, stvar->index, stvar->sort_index);
	ret = sort_five_stack(stvar, 'a', stvar->index);
	if (ret != 1)
		return (ret);
	// print_stack_b(&stvar->stack_b, 1);
	// print_stack(&stvar->stack_a, 1);
	set_min_max(stvar, 'b');
	// ft_printf("stvar->index B:%i\tsort_index:%i\n", stvar->index, stvar->sort_index);
	// print_stack_b(&stvar->stack_b, 1);
	ret = sort_five_stack(stvar, 'b', stvar->argc - stvar->index);
	// print_stack_list(stvar->stack_a, 'a');
	// print_stack_list(stvar->stack_b, 'b');
	// if (stvar->index == 3)
	// {
	// 	sort_three_revpart(&stvar->stack_b, stvar, stvar->min, stvar->max);
	// 	// ft_printf("stvar->index B:%i\tsort_index:%i\n", stvar->index, stvar->sort_index);
	// }
	if (ret != 1)
		return (ret);
	return (ret);
}

// **Good version**

int		sort_five_stack(t_pw_var *stvar, char c, int argc)
{
	char *instr;
	int ret;
	int j;
	int i;

	ret = 1;
	instr = NULL;
	// ft_printf("stvar->argc:%i\targc:%i\n", stvar->argc, argc);
	// ft_printf("stvar->index:%i\n", stvar->index);
	i = (c == 'a' ) ? (stvar->argc - argc) : (argc - 1);
	// ft_printf("i is:%i\n", i);
	// ft_printf("len:%i\n", (stvar->argc - stvar->index));
	// ft_printf("stvar sort index:%i\n", stvar->sort_index);
	// ft_printf("stvar->index:%i\n", stvar->index);
	j = argc;
	// ft_printf("j is:%d\n", j);
	// print_stack_list(stvar->stack_b, 'b');
	// print_stack_list(stvar->stack_a, 'a');
	while (j > 3)
	{
		// ft_printf("num is:%d\n", stvar->stack_a->num);
		instr = find_low(stvar, c, &i);
		// ft_printf("instr is:%s\n", instr);
		ret = do_op(stvar, instr, c, 1);
		// print_stack_list(stvar->stack_a, c);
		if (ret == -1)
			return (-1);
		if (instr == PB || instr == PA)
			j--;
	}
	if (c == 'b' && stvar->argc - stvar->index == 3)
	{
		set_min_max(stvar, 'b');
		// ft_printf("min:%i\tmax:%i\n", stvar->min, stvar->max);
		sort_three_revpart(&stvar->stack_b, stvar, stvar->min, stvar->max);
	}
	if (c == 'a' && stvar->index == 3)
		sort_three(stvar, stvar->min, stvar->max);
	else if (argc == 2)
		(sort_two(c, stvar));
	if (argc > 3 || c == 'b')
	{
		// ft_printf("stvar->index:%i\tsort_index:%i\n", stvar->index, stvar->sort_index);
		instr = (c == 'a' || stvar->sort_index == stvar->index) ? PA : PB;
		// ft_printf("instr:%s\n", instr);
		argc = (c == 'a') ? argc - 3 : argc;
		// ft_printf("argc:%i\n", argc);
		ret = do_op(stvar, instr, c, argc);
		// print_stack_b(&stvar->stack_b, 1);
	}
	// print_stack_list(stvar->stack_a, 'a');
	return (ret);
}

// int		sort_five_stack(t_pw_var *stvar, int argc)
// {
// 	int	opts;
// 	char *instr;
// 	int ret;
// 	int j;
// 	int	i;

// 	opts = 1;
// 	ret = 1;
// 	j = 0;
// 	i = 0;
// 	while (j != 2)
// 	{
// 		// ft_printf("num is:%d\n", stvar->stack_a->num);
// 		// print_stack(&stvar->stack_a, 1);
// 		opts = 1;
// 		// print_stack_list(stvar->stack_a, 'a');
// 		instr = find_low(stvar, 'a', &opts, &i);
// 		// ft_printf("instr is:%s\t total:%d\n", instr, opts);
// 		ret = do_op(stvar, instr, opts);
// 		// print_stack(&stvar->stack_a, 1);
// 		if (ret == -1)
// 			return (-1);
// 		if (instr == PB)
// 		{
// 			j++;
// 			// ft_printf("j is:%d\n", j);
// 		}
// 		update_stack(stvar, &(stvar)->stack_a);
// 		// ft_printf("updated\n");
// 	}
// 	// ft_printf("go sort three\n");
// 	sort_three(&(stvar)->stack_a, stvar, stvar->min, stvar->max);
// 	// print_stack(&stvar->stack_a, 1);
// 	// print_stack_b(&stvar->stack_b, 1);
// 	// sort_two('b', stvar);
// 	ret = do_op(stvar, PA, 2);
// 	update_stack(stvar, &(stvar)->stack_a);
// 	// print_stack(&stvar->stack_a, 1);
// 	// ft_printf("stvar->list:%d\n", stvar->total_ins);
// 	return (ret);
// }

int		sort_threeb(t_pw_var *stvar, int min, int max)
{
	t_stack *stack;

	stack = stvar->stack_b;
	// ft_printf("stack->num is:%d\n\n", (stack->num));
	if ((stack->num) == min && (stack->next->num) != max)
		return (do_op(stvar, NULL, 'b', 0));
	if ((stack->num) == min && (stack->next->num) == max)
		return (do_op(stvar, RRB, 'b', 1) && do_op(stvar, SB, 'b', 1));
	if ((stack->num) == max && (stack->next->num) == min)
		return (do_op(stvar, RB, 'b', 1));
	if ((stack->num) == max && (stack->next->num) != min)
		return (do_op(stvar, SB, 'b', 1) && do_op(stvar, RRB, 'b', 1));
	if ((stack->next->num) == max)
		return (do_op(stvar, RRB, 'b', 1));
	if ((stack->next->num) == min)
		return (do_op(stvar, SB, 'b', 1));
	// ft_printf("three are now sorted!!!\n\n");
	return (1);
}

int		sort_three(t_pw_var *stvar, int min, int max)
{
	t_stack *stack;

	stack = stvar->stack_a;
	// ft_printf("num:%d\tmin:%i\tmax:%i\n\n", (stack->num), min, max);
	if ((stack->num) == min && (stack->next->num) != max)
		return (do_op(stvar, NULL, 'a', 0));
	if ((stack->num) == min && (stack->next->num) == max)
		return (do_op(stvar, RRA, 'a', 1) && do_op(stvar, SA, 'a', 1));
	if ((stack->num) == max && (stack->next->num) == min)
		return (do_op(stvar, RA, 'a', 1));
	if ((stack->num) == max && (stack->next->num) != min)
		return (do_op(stvar, SA, 'a', 1) && do_op(stvar, RRA, 'a', 1));
	if ((stack->next->num) == max)
		return (do_op(stvar, RRA, 'a', 1));
	if ((stack->next->num) == min)
		return (do_op(stvar, SA, 'a', 1));
	// ft_printf("three are now sorted!!!\n\n");
	return (1);
}
/* ************************************************************************** */
