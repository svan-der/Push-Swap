/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer_opts.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:49:34 by svan-der      #+#    #+#                 */
/*   Updated: 2020/06/09 13:17:47 by svan-der      ########   odam.nl         */
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

int	calc_dist_top_b(t_pw_var *stvar, int top, int bottom)
{
	int num;
	int dist_top;
	int dist_bottom;

	if (stvar->stack_b == NULL)
		return (-1);
	num = stvar->stack_b->num;
	ft_printf("num;%i\n", num);
	dist_top = ft_abs(num) - ft_abs(top);
	dist_bottom = ft_abs(num) - ft_abs(bottom);
	if (dist_top < dist_bottom)
		return (0);
	else
	{
		return (1);
	}
}

void	part_sort(t_pw_var *stvar, int argc)
{
	// int i;
	int j;
	int top;
	int bottom;
	// int res;

	j = (argc == 0) ? 3 : argc;
	ft_printf("here\n");
	print_tail(stvar->stack_a->tail);
	do_op(stvar, PB, 'b', 1);
	print_tail(stvar->stack_a->tail);
	top = stvar->stack_a->num;
	ft_printf("top:%i\n", top);
	print_tail(stvar->stack_a->tail);
	bottom = stvar->stack_a->tail->num;
	ft_printf("%p\n", stvar->stack_a->tail);
	print_tail(stvar->stack_a->tail);
	ft_printf("bottom:%i\n", bottom);
	// res = calc_dist_top_b(stvar, top, bottom);
	// ft_printf("res is:%i\n", res);
	// while (stvar->index != j)
	// {
	// 	top = stvar->stack_a->num;
	// 	bottom = stvar->stack_a->tail->num;
	// 	if (stvar->stack_a-> < stvar->median)
	// 		do_op(stvar, PB, 'b', 1);
	// 	else
	// 	{
	// 		do_op(stvar, RA, 'a', 1);
	// 	}
	// }
	// print_stack(&stvar->stack_a, 1);
}

// **last good one**
// void	part_sort(t_pw_var *stvar, int argc)
// {
// 	char low;
// 	int	*sorted;
// 	int j;
// 	int k;
// 	int ret;

// 	j = 0;
// 	k = 0;
// 	ret = 0;
// 	sorted = stvar->sorted;
// 	if (stvar->stack_a == NULL)
// 		return ;
// 	while (j < argc)
// 	{
// 		j++;
// 		if ((stvar->stack_a->num) < stvar->median)
// 		{
// 			if (stvar->stack_a->num == sorted[k])
// 				dispatch_sort(stvar, PB, 1);
// 			if (stvar->stack_a->next->num == sorted[k])
// 				dispatch_sort(stvar, SA, 1);
// 		}
// 		else
// 		{
// 			if ((stvar->stack_a->num) == stvar->min)
// 				low = 1;
// 			if ((stvar->stack_a->next->num) < stvar->median)
// 				dispatch_sort(stvar, SA, 1);
// 			else
// 			{
// 				// if (stvar->tail < stvar->median)
// 				// 	dispatch_sort(stvar, RRA, 1);
// 				dispatch_sort(stvar, RA, 1);
// 			}
// 		}
// 		if (low && stvar->index == 3)
// 			break ;
// 	}
// 	// print_partition_list(part)
// }

// void	part_sort(t_pw_var *stvar, int argc)
// {
// 	char low;
// 	int j;

// 	j = 0;
// 	if (stvar->stack_a == NULL)
// 		return ;
// 	while (j < argc)
// 	{
// 		j++;
// 		if ((stvar->stack_a->num) < stvar->median)
// 			// dispatch_sort(stvar, PB, 1);
// 		else
// 		{
// 			if ((stvar->stack_a->num) == stvar->min)
// 				low = 1;
// 			if ((stvar->stack_a->next->num) < stvar->median)
// 				dispatch_sort(stvar, SA, 1);
// 			else
// 			{
// 				// if (stvar->tail < stvar->median)
// 				// 	dispatch_sort(stvar, RRA, 1);
// 				dispatch_sort(stvar, RA, 1);
// 			}
// 		}
// 		if (low && stvar->index == 3)
// 			break ;
// 	}
// 	// print_partition_list(part)
// }

int		do_op(t_pw_var *stvar, char *str, char c, int num)
{
	int i;
	int ret;

	i = 0;
	// ft_printf("num is:%i\n", num);
	while (i < num)
	{
		// ft_printf("i is:%i\n", i);
		// if (str == PA)
		// 	print_stack_b(&stvar->stack_b, 1);
		// ft_printf("i is:%d\n", i);
		ret = dispatch_sort(stvar, str, 1);
		// print_stack(&stvar->stack_a, 1);
		// print_stack_list(stvar->stack_a, 'a');
		// ft_printf("return is:%i\n", ret);
		if (ret == -1)
			return (-1);
		update_stack(stvar, c);
		i++;
	}
	return (ret);
}

// void sort_three_part(t_stack **temp, t_pw_var *stvar, int min, int max)
// {
// 	t_stack *stack;

// 	stack = *temp;
// 	if ((*stack->num) == min)
// 	{
		
// 	}
// 	else if ((*stack->num) == max)
// 	{
// 		if ((*stack->next->num) != min)
// 			do_op(stvar, PB, 3);
// 		else
// 		{
// 			dispatch_sort(stvar, PB, 1);
// 			dispatch_sort(stvar, SB, 1);
// 			do_op(stvar, PB, 2);
// 		}
// 	}
// 	else
// 	{
// 		if ((*stack->next->num) == min)
// 		{
// 			dispatch_sort(stvar, SB, 1);
// 			do_op(stvar, RB, 2);
// 			dispatch_sort(stvar, PB, 1);
// 			dispatch_sort(stvar, RRB, 1);
// 			dispatch_sort(stvar, PB, 1);
// 			dispatch_sort(stvar, RRB, 1);
// 			dispatch_sort(stvar, PB, 1);
// 		}
// 		else
// 		{
// 			dispatch_sort(stvar, SB, 1);
// 			dispatch_sort(stvar, PB, 3);
// 		}
// 	}
// }

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
	i = (len / 2);
	// i = (stvar->argc / 2);
	// ft_printf("stvar->index:%i\tlen:%i\n", stvar->index, len);
	// ft_printf("index:%i\tmid:%i\n", index, i);
	if (index <= i)
		return (c == 'a' ? RA : RB);
	else
		return (c == 'a' ? RRA: RRB);
}

void	update_stack(t_pw_var *stvar, char c)
{
	t_stack *temp;

	if (c == 'a')
		temp = stvar->stack_a;
	if (c == 'b')
		temp = stvar->stack_b;
	// ft_printf("temp:%p\n", temp);
	// ft_printf("temp:%p\tnum:%i\n", temp, temp->num);
	while (temp != NULL && temp->next != NULL)
	{
		// ft_printf("temp:%p\tnum:%i\n", temp, temp->num);
		// print_stack_list(stvar->stack_a, 'a');
		find_distance(temp, temp->num, stvar->sorted);
		temp = temp->next;
	}
	if (c == 'a' && temp)
	{
		// ft_printf("add tail in a\n");
		add_tail(&stvar->stack_a);
	}
	else if (c == 'b' && temp)
		add_tail(&stvar->stack_b);
	// print_tail(stvar->stack_a->tail);
	// print_stack_list(stvar->stack_a, 'a');
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

void	find_distance(t_stack *stack_a, int num, int *sorted)
{
	t_stack *temp;
	int dist;
	int i;
	int j;

	temp = stack_a;
	i = 0;
	j = 0;
	while (temp != NULL && temp->num != num)
	{
		temp = temp->next;
		j++;
	}
	while (sorted[i] != num)
		i++;
	dist = j - i;
	// ft_printf("j:%i\t\ti:%i\tdist:%i\tindex:%i\n", j, i, dist, temp->index);
	(stack_a)->dist = dist;
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
	// 	ft_printf("dist_top is:%d\n", dist_top);
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
