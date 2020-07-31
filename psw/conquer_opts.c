/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer_opts.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:49:34 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 20:10:42 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_top(t_pw_var *stvar, t_stack *top)
{
	char	*instr;

	instr = fastest_rotate(stvar, 'a', &top->dist_top);
	if (top->dist_top > 0)
		do_op(stvar, instr, 'a', top->dist_top);
	do_op(stvar, PB, 'b', 1);
	if (stvar->stack_b != NULL && stvar->stack_b->next != NULL)
		find_solution(stvar, top);
}

void	sort_bottom(t_pw_var *stvar, t_stack *bottom)
{
	char	*instr;
	int		i;

	instr = fastest_rotate(stvar, 'a', &bottom->dist_top);
	i = bottom->dist_top;
	if (i != 0)
		do_op(stvar, instr, 'a', i);
	do_op(stvar, PB, 'b', 1);
	if (stvar->stack_b != NULL && stvar->stack_b->next != NULL)
		find_solution(stvar, bottom);
}

void	check_top_b(t_pw_var *stvar)
{
	int		i;
	char	*str;

	i = 0;
	if (stvar->stack_b && stvar->stack_b->next)
	{
		set_min_max(stvar, 'b');
		if (stvar->stack_b->num == stvar->max)
			return ;
		else
		{
			find_max(stvar->stack_b, stvar->max, &i);
			str = fastest_rotate(stvar, 'b', &i);
			do_op(stvar, str, 'b', i);
		}
	}
}

void	sort_short_opts(t_pw_var *stvar)
{
	if (stvar->index == 2)
		sort_two('a', stvar);
	else if (stvar->index == 3)
		sort_three(stvar, stvar->min, stvar->max);
	else if (stvar->index < 6)
		sort_five_stack(stvar, 'a', stvar->index - stvar->sort_index);
}
