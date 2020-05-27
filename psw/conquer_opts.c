/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer_opts.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:49:34 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/27 17:42:41 by svan-der      ########   odam.nl         */
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

// void	check_prio(int *sorted, t_stack **stack)
// {
// 	int i;

// 	i = 0;
// 	while (stack_a->num)
// }

void	part_sort(t_pw_var *stvar, int argc)
{
	char low;
	int	*sorted;
	int j;
	int k;
	int ret;

	j = 0;
	k = 0;
	ret = 0;
	sorted = stvar->sorted;
	if (stvar->stack_a == NULL)
		return ;
	while (j < argc)
	{
		j++;
		if ((stvar->stack_a->num) < stvar->median)
		{
			if (stvar->stack_a->num == sorted[k])
				dispatch_sort(stvar, PB, 1);
			if (stvar->stack_a->next->num == sorted[k])
				dispatch_sort(stvar, SA, 1);
		}
		else
		{
			if ((stvar->stack_a->num) == stvar->min)
				low = 1;
			if ((stvar->stack_a->next->num) < stvar->median)
				dispatch_sort(stvar, SA, 1);
			else
			{
				// if (stvar->tail < stvar->median)
				// 	dispatch_sort(stvar, RRA, 1);
				dispatch_sort(stvar, RA, 1);
			}
		}
		if (low && stvar->index == 3)
			break ;
	}
	// print_partition_list(part)
}




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

int		do_op(t_pw_var *stvar, char *str, int num)
{
	int i;
	int ret;

	i = 0;
	ft_printf("num is:%i\n", num);
	while (i < num)
	{
		ft_printf("i is:%d\n", i);
		ret = dispatch_sort(stvar, str, 1);
		print_stack(&stvar->stack_a, 1);
		print_stack_b(&stvar->stack_b, 1);
		ft_printf("return is:%i\n", ret);
		if (ret == -1)
			return (-1);
		update_stack(stvar, &stvar->stack_a);
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

// int		sort_three_revpart(t_stack **temp, t_pw_var *stvar, int min, int max)
// {
// 	t_stack *stack;

// 	stack = *temp;
// 	if ((stack->num) == min && (stack->next->num) != max)
// 		return (dispatch_sort(stvar, RRB, 1) && dispatch_sort(stvar, SB, 1));
// 	if ((stack->num) == min && (stack->next->num) == max)
// 		return (dispatch_sort(stvar, RB, 1));
// 	if ((stack->num) == max && (stack->next->num) == min)
// 		return (dispatch_sort(stvar, RRB, 1) && dispatch_sort(stvar, SB, 1));
// 	if ((stack->num) == max && (stack->next->num) != min)
// 		return (dispatch_sort(stvar, NULL, 0));
// 	if ((stack->next->num) == max)
// 		return (dispatch_sort(stvar, SB, 1));
// 	if ((stack->next->num) == min)
// 		return (dispatch_sort(stvar, RRB, 1));
// 	// ft_printf("three are now sorted!!!\n\n");
// 	return (0);
// }

int		sort_three_revpart(t_stack **temp, t_pw_var *stvar, int min, int max)
{
	t_stack *stack;
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	stack = *temp;
	a = stack;
	b = stack->next;
	c = stack->next->next;
	// ft_printf("a->num is:%d\n", a->num);
	// ft_printf("b->num is:%d\n", b->num);
	// ft_printf("c->num is:%d\n", c->num);
	if ((a->num > b->num) && (b->num > c->num))
	{
		dispatch_sort(stvar, RA, 1);
		dispatch_sort(stvar, SA, 1);
	}
	else if ((a->num < b->num) && (b->num > c->num) && (c->num < a->num))
		dispatch_sort(stvar, RRA, 1);
	else if ((a->num < b->num) && (b->num > c->num) && (c->num > a->num))
	{
		dispatch_sort(stvar, SA, 1);
		dispatch_sort(stvar, RA, 1);
	}
	else if ((a->num > b->num) && (b->num < c->num) && (c->num > a->num))
	{
		ft_printf("goes in SA\n");
		dispatch_sort(stvar, SA, 1);
	}
	else if ((a->num > b->num) && (b->num < c->num) && (c->num < a->num))
		dispatch_sort(stvar, RA, 1);
	return (0);
}

void	sort_two(t_stack **stack_a, t_stack **stack_b, t_pw_var *stvar)
{
	(void)stack_a;
	if (((*stack_b)->num) < ((*stack_b)->next->num))
		dispatch_sort(stvar, SB, 1);
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
		sort_three_revpart(&stack, stvar, stvar->min, stvar->max);
		do_op(stvar, PA, 3);
	}
	else if (stack_len == 2)
	{
		sort_two(&stvar->stack_a, &stvar->stack_b, stvar);
		do_op(stvar, PA, 2);
	}
	else
		dispatch_sort(stvar, PA, 1);
}

void	fastest_sort(t_pw_var *stvar, t_stack **stack_a)
{
	int revrot_opt;
	int rot_opt;
	int argc;

	argc = stvar->index;
}

void	update_stack(t_pw_var *stvar, t_stack **stack_a)
{
	t_stack *temp;

	temp = *stack_a;
	while (temp != NULL)
	{
		find_distance(&temp, temp->num, stvar->sorted);
		temp = temp->next;
	}
	// ft_printf("adding tail\n");
	add_tail(stack_a);
	// print_tail(stvar->stack_a->tail);
	// print_stack_list(stvar->stack_a, 'a');
}

void	find_distance(t_stack **stack_a, int num, int *sorted)
{
	t_stack *temp;
	int dist;
	int i;
	int j;

	temp = *stack_a;
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
	(*stack_a)->dist = dist;
	// ft_printf("dist is:%d\n", (*stack_a)->dist);
}

char	*find_low(t_stack *stack, int *op)
{
	t_stack *top_next;
	t_stack *bottom;
	t_stack *bottom_prev;
	int		num;

	top_next = stack->next;
	bottom = stack->tail;
	bottom_prev = stack->tail->prev;
	num = stack->num;
	*op = 1;
	if (num > top_next->num)
		num = top_next->num;
	if (num > bottom->prev->num)
		num = bottom->prev->num;
	if (num > bottom->num)
		num = bottom->num;
	// ft_printf("num is:%d\n", num);
	if (num == top_next->num)
		return (SA);
	if (num == bottom_prev->num)
	{
		*op = 2;
		return (RRA);
	}
	if (num == bottom->num)
		return (RRA);
	return (PB);
}

int		sort_five_stack(t_pw_var *stvar, int argc)
{
	int	opts;
	char *instr;
	int ret;
	int j;

	ret = 1;
	j = 0;
	while (j != 2)
	{
		// ft_printf("num is:%d\n", stvar->stack_a->num);
		// print_stack(&stvar->stack_a, 1);
		instr = find_low(stvar->stack_a, &opts);
		ft_printf("instr is:%s\t total:%d\n", instr, opts);
		ret = do_op(stvar, instr, opts);
		if (ret == -1)
			return (-1);
		if (instr == PB)
		{
			j++;
			// ft_printf("j is:%d\n", j);
		}
		// update_stack(stvar, &(stvar)->stack_a);
		ft_printf("updated\n");
	}
	ft_printf("go sort three\n");
	sort_three(&(stvar)->stack_a, stvar, stvar->min, stvar->max);
	ret = do_op(stvar, PA, 2);
	// ft_printf("stvar->list:%d\n", stvar->total_ins);
	return (ret);
}

int		sort_three(t_stack **temp, t_pw_var *stvar, int min, int max)
{
	t_stack *stack;

	stack = *temp;
	// ft_printf("stack->num is:%d\n\n", (stack->num));
	if ((stack->num) == min && (stack->next->num) != max)
		return (do_op(stvar, NULL, 0));
	if ((stack->num) == min && (stack->next->num) == max)
		return (do_op(stvar, RRA, 1) && do_op(stvar, SA, 1));
	if ((stack->num) == max && (stack->next->num) == min)
		return (do_op(stvar, RA, 1));
	if ((stack->num) == max && (stack->next->num) != min)
		return (do_op(stvar, SA, 1) && do_op(stvar, RRA, 1));
	if ((stack->next->num) == max)
		return (do_op(stvar, RRA, 1));
	if ((stack->next->num) == min)
		return (do_op(stvar, SA, 1));
	// ft_printf("three are now sorted!!!\n\n");
	return (1);
}
