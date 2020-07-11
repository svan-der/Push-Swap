/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_specified.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 17:10:56 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/11 17:23:16 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_short(t_pw_var *stvar, char c, int stack_len)
{
	t_stack *stack;

	if (c == 'a')
		stack = stvar->stack_a;
	else
		stack = stvar->stack_b;
	if ((stvar->argc - stvar->index == 3))
		do_op(stvar, PA, c, 3);
	else if (stack_len == 2)
	{
		sort_two(c, stvar);
		do_op(stvar, PA, c, 2);
	}
	else
		dispatch_sort(stvar, PA, 1);
}

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
	return (1);
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
	return (0);
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
	return (1);
}

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

int		sort_five_stack(t_pw_var *stvar, char c, int argc)
{
	char *instr;
	int ret;
	int j;
	int i;

	ret = 1;
	instr = NULL;
	i = (c == 'a') ? (stvar->argc - argc) : (argc - 1);
	j = argc;
	while (j > 3)
	{
		instr = find_low(stvar, c, &i);
		ret = do_op(stvar, instr, c, 1);
		if (ret == -1)
			return (-1);
		if (instr == PB || instr == PA)
			j--;
	}
	if (c == 'b' && stvar->argc - stvar->index == 3)
	{
		set_min_max(stvar, 'b');
		sort_three_revpart(&stvar->stack_b, stvar, stvar->min, stvar->max);
	}
	if (c == 'a' && stvar->index == 3)
		sort_three(stvar, stvar->min, stvar->max);
	else if (argc == 2)
		(sort_two(c, stvar));
	if (argc > 3 || c == 'b')
	{
		instr = (c == 'a' || stvar->sort_index == stvar->index) ? PA : PB;
		argc = (c == 'a') ? argc - 3 : argc;
		ret = do_op(stvar, instr, c, argc);
	}
	return (ret);
}

int			sort_short_stack(t_pw_var *stvar, int argc)
{
	int ret;
	int j;

	ret = 1;
	j = (argc % 2) ? ((argc + 1) / 2) : argc / 2;
	argc = j;
	while (stvar->index != j)
	{
		if (stvar->stack_a->num < stvar->median)
			ret = do_op(stvar, PB, 'a', 1);
		else
			ret = do_op(stvar, RA, 'a', 1);
	}
	ret = sort_five_stack(stvar, 'a', stvar->index);
	if (ret != 1)
		return (ret);
	set_min_max(stvar, 'b');
	ret = sort_five_stack(stvar, 'b', stvar->argc - stvar->index);
	if (ret != 1)
		return (ret);
	return (ret);
}
