/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer_opts.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:49:34 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/03 17:57:53 by svan-der      ########   odam.nl         */
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
**/

int	 calc_dist_top_b(t_pw_var *stvar, t_stack *top, t_stack *bottom)
{
	t_stack *current;
	int dist_top;
	int dist_bottom;

	if (stvar->stack_b == NULL)
	{
		if (top->num < bottom->num)
			return (0);
		else
			return (1);
	}
	current = stvar->stack_b;
	// ft_printf("\n\n");
	// ft_printf("actual index order calculate closest to dist top b\n");
	// ft_printf(RED"num in b:%i\n"RESET, current->num);
	// dist_top = ft_abs(num) - ft_abs(top);
	// dist_top = num - top;
	// ft_printf("current->index:%i\ttop_index:%i\n", current->index, top->index);
	dist_top = ft_abs(current->index - top->index);
	// ft_printf("dist top:%i\n", dist_top);
	// ft_printf("current->index:%i\tbottom_index:%i\n", current->index, bottom->index);
	dist_bottom = ft_abs(current->index - bottom->index);
	// ft_printf("dist bottom:%i\n", dist_bottom);
	if (dist_top < dist_bottom)
		return (0);
	else
	{
		return (1);
	}
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
	ft_printf("i:%i\n", i);
	while (temp)
	{
		if (temp->part_id == i)
		{
			temp->dist_top = j;
			ft_printf("dist_top:%i\n", temp->dist_top);
			return (temp);
		}
		temp = temp->next;
		j++;
	}
	return (temp);
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
	ret = calc_dist_top_b(stvar, top, bottom);
	// ft_printf("ret is:%i\n", ret);
	if (ret == 0)
	{
		instr = fastest_rotate(stvar, 'a', top->dist_top);
		// ft_printf("instr is:%s\tnum is:%i\n", instr, top->dist_top);
		if (ft_strnequ(instr, RR, 2))
			do_op(stvar, instr, 'a', stvar->index - top->dist_top);
		else
		{
			do_op(stvar, instr, 'a', top->dist_top);
		}
	}
	else
	{
		instr = fastest_rotate(stvar, 'a', bottom->dist_top);
		if (ft_strnequ(instr, RR, 2))
			do_op(stvar, instr, 'a', stvar->index - bottom->dist_top);
		else
		{
			do_op(stvar, instr, 'a', bottom->dist_top);
		}
		// ft_printf("instr is:%s\tnum is:%i\n", instr, bottom->dist_top);
	}
	do_op(stvar, PB, 'b', 1);
	// ft_printf("after finding part\n");
	// print_stack_list(stvar->stack_b, 'b');
	// print_stack_list(stvar->stack_a, 'a');
}

// **last good one**
// void	find_part(t_pw_var *stvar)
// {
// 	t_stack *bottom;
// 	t_stack *top;
// 	int ret;
// 	char *instr;

// 	ft_printf("in find part\n");
// 	// print_tail(stvar->stack_a->tail);
// 	top = find_top_part(stvar);
// 	// ft_printf("top_part:%i\tdist_top:%i\n", top->num, top->dist_top);
// 	bottom = find_bottom_part(stvar);
// 	// ft_printf("bottom-part:%i\tdist_top:%i\n", bottom->num, bottom->dist_top);
// 	ret = calc_dist_top_b(stvar, top, bottom);
// 	// ft_printf("ret is:%i\n", ret);
// 	// ft_printf("instr is:%s\n", instr);
// 	// ft_printf("stvar->stack_a->dist_top:%i\n",stvar->stack_a->dist_top);
// 	if (ret == 0)
// 	{
// 		instr = fastest_rotate(stvar, 'a', top->dist_top);
// 		// ft_printf("\n\n");
// 		// ft_printf("instr is:%s\tnum is:%i\n", instr, top->dist_top);
// 		do_op(stvar, instr, 'a', top->dist_top);
// 		// print_stack_list(stvar->stack_a, 'a');
// 	}
// 	else
// 	{
// 		instr = fastest_rotate(stvar, 'a', bottom->dist_top);
// 		// ft_printf("\n\n");
// 		// ft_printf("instr is:%s\tnum is:%i\n", instr, bottom->dist_top);
// 		do_op(stvar, instr, 'a', bottom->dist_top);
// 		// print_stack_list(stvar->stack_a, 'a');
// 	}
// 	do_op(stvar, PB, 'b', 1);
// 	// *i -= 1;
// 	// print_stack_list(stvar->stack_a, 'a');
// 	// print_tail(stvar->stack_a->tail);
// }

void	part_sort(t_pw_var *stvar, int argc, int i)
{
	char *instr;
	int j;
	t_stack *top;
	t_stack *bottom;
	int res;

	// j = 1;
	// (void)argc;
	j = argc;
	// ft_printf("here\n");
	// ft_printf("argc:%i index:%i\n", j, i);
	while (j)
	{
		// ft_printf("\n\n");
		// ft_printf("j is:%i\n", j);
		res = 0;
		// ft_printf("index is:%i\n", stvar->index);
		// print_stack_list(stvar->stack_a, 'a');
		top = stvar->stack_a;
		ft_printf(GRN"|top:%i part_id:%i top->index:%i|\n"RESET, top->num, top->part_id, top->index);
		bottom = stvar->stack_a->tail;
		// print_tail(stvar->stack_a->tail);
		ft_printf(YEL"|bottom:%i part_id:%i bottom->index:%i|\n"RESET, bottom->num, bottom->part_id, bottom->index);
		if (top->part_id == i || bottom->part_id == i)
		{
			if (top->part_id == i && bottom->part_id == i)
			{
				ft_printf(CYN"option 1\n"RESET);
				res = calc_dist_top_b(stvar, top, bottom);
				ft_printf("res is:%i\n", res);
				if (res != 0)
				{
					instr = fastest_rotate(stvar, 'a', bottom->index);
					if (ft_strnequ(instr, RR, 2))
					{
						// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, bottom->dist);
						do_op(stvar, instr, 'a', stvar->index - bottom->dist_top);
					}
					else
					{
						// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, bottom->dist);
						do_op(stvar, instr, 'a', bottom->dist_top);
					}
				}
				ft_printf("instr is:%s\n", instr);
				do_op(stvar, (instr = PB), 'b', 1);
				// if (j == 1 && stvar->index == stvar->argc / 2)
				// 	exit(1);
			}
			else
			{
				// ft_printf("\n\n");
				// ft_printf("option 2\n");
				if (bottom->part_id == i)
				{
					instr = fastest_rotate(stvar, 'a', bottom->index);
					if (ft_strnequ(instr, RR, 2))
					{
						// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, bottom->dist);
						do_op(stvar, instr, 'a', stvar->index - bottom->dist_top);
					}
					else
					{
						// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, bottom->dist);
						do_op(stvar, instr, 'a', bottom->dist_top);
					}
						// bottom->index);
				}
				ft_printf("instr is:%s\n", instr);
				do_op(stvar, (instr = PB), 'b', 1);
				// print_stack_list(stvar->stack_b, 'b');
			}
		}
		else
		{
			// ft_printf("\n\n");
			ft_printf("option 3\n");
			// ft_printf("find part\t j:%i\n", j);
			find_part(stvar, i);
			// if (j > 1)
			// 	find_part(stvar);
			instr = PB;
		}
		if (ft_strequ(instr, PB))
			j--;
	}
}

int		do_op(t_pw_var *stvar, char *str, char c, int num)
{
	int i;
	int ret;

	i = 0;
	// ft_printf("num is:%i\n", num);
	// ft_printf("instr is:%s\n", str);
	while (i < num)
	{
		// ft_printf("i is:%i\n", i);
		// if (str == PA)
		// 	print_stack_b(&stvar->stack_b, 1);
		// ft_printf("i is:%d\n", i);
		ret = dispatch_sort(stvar, str, 1);
		// print_tail(stvar->stack_a->tail);
		// print_stack(&stvar->stack_a, 1);
		// print_stack_list(stvar->stack_a, 'a');
		// print_stack_list(stvar->stack_b, 'b');
		if (str == PB)
			ft_printf("return is:%i\n", ret);
		if (ret == -1)
			return (-1);
		update_stack(stvar, c);
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
	i = (len % 2) ? ((len + 1) / 2) : len / 2;
	ft_printf("len:%i\t i:%i\n", len, i);
	ft_printf("char:%c\tindex:%i\n", c, index);
	if (index <= i)
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
			ft_printf("dist_top:%i\n", temp->dist_top);
			return ;
		}
		temp = temp->next;
		j++;
	}
}

void	find_distance(t_stack *stack, int num, int *sorted)
{
	t_stack *temp;
	// int dist;
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
	// temp->dist_top = j;
	// ft_printf(YEL"temp->dist_top:%i\n"RESET, temp->dist_top);
	while (sorted[i] != num)
		i++;
	temp->dist = j - i;
	temp->dist_top = j;
	// ft_printf(CYN"|num:%i\tdist:%i\n|"RESET, temp->num, dist);
	// ft_printf("j:%i\t\ti:%i\tdist:%i\tindex:%i\n", j, i, dist, temp->index, temp->num);
	// (stack)->dist = dist;
	stack = temp;
	// (*stack_a)->dist = dist;
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
	// if (c == 'b')
	// ft_printf("num is:%i\n", current->num);
	ft_printf("dist_top is:%d\n", dist_top);
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
	// print_stack(&stvar->stack_a, 1);
	// print_stack_b(&stvar->stack_b, 1);
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
