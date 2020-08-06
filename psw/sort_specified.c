/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_specified.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 17:10:56 by svan-der      #+#    #+#                 */
/*   Updated: 2020/08/01 17:47:37 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	sort_three_rpart(t_stack **temp, t_pw_var *stvar, int min, int max)
{
	t_stack *stack;

	stack = *temp;
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

int			sort_three(t_pw_var *stvar, int min, int max)
{
	t_stack *stack;

	stack = stvar->stack_a;
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

void		sort_two(char c, t_pw_var *stvar)
{
	t_stack *temp;

	if (c == 'a')
	{
		temp = stvar->stack_a;
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

static void	sort_rest(t_pw_var *stvar, char c, int argc)
{
	char	*instr;

	if (c == 'b' && stvar->argc - stvar->index == 3)
	{
		set_min_max(stvar, 'b');
		sort_three_rpart(&stvar->stack_b, stvar, stvar->min, stvar->max);
	}
	if (c == 'a' && stvar->index == 3)
	{
		set_min_max(stvar, 'a');
		sort_three(stvar, stvar->min, stvar->max);
	}
	else if (argc == 2)
		(sort_two(c, stvar));
	if (argc > 3 || c == 'b')
	{
		instr = (c == 'a' || stvar->sort_index == stvar->index) ? PA : PB;
		argc = (c == 'a') ? argc - 3 : stvar->argc - stvar->index;
		do_op(stvar, instr, c, argc);
	}
}

void		sort_five_stack(t_pw_var *stvar, char c, int argc)
{
	char	*instr;
	int		j;
	int		i;

	instr = NULL;
	i = (c == 'a') ? (stvar->argc - argc) : (argc - 1);
	j = argc;
	while (j > 3)
	{
		instr = find_low(stvar, c, &i);
		do_op(stvar, instr, c, 1);
		if (ft_strnequ(instr, PB, 2) || ft_strnequ(instr, PA, 2))
			j--;
	}
	sort_rest(stvar, c, argc);
}
