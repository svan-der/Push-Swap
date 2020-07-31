/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer_opts.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:49:34 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 13:49:12 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/psw_env.h"

void	sort_top(t_pw_var *stvar, t_stack *top)
{
	char	*instr;
	char	*instr_b;
	int		j;

	j = 0;
	instr = fastest_rotate(stvar, 'a', &top->dist_top);
	if (top->dist_top > 0)
		do_op(stvar, instr, 'a', top->dist_top);
	// if (stvar->inst_lst && instr)
	// 	check_dble(stvar, instr);
	// instr_b = presort_stack_b(stvar, top, &j);
	// if (instr_b != NULL)
	// {
	// 	do_op(stvar, instr_b, 'b', j);
	// 	check_dble(stvar, instr_b);
	// }
	do_op(stvar, PB, 'b', 1);
	find_solution(stvar, stvar->stack_b, NULL);
}

void	sort_top_bottom(t_pw_var *stvar, int i, t_stack *top, t_stack *bottom)
{
	char	*instr;
	int		j;
	int		ret;

	if (i != 0)
		sort_bottom(stvar, bottom);
	else
		sort_top(stvar, top);
}

void	sort_bottom(t_pw_var *stvar, t_stack *bottom)
{
	char	*instr;
	char	*instr_b;
	int		j;
	int		i;
	int		ret;

	instr = fastest_rotate(stvar, 'a', &bottom->dist_top);
	i = bottom->dist_top;
	if (i != 0)
		do_op(stvar, instr, 'a', i);
	// if (stvar->inst_lst && instr)
	// 	check_dble(stvar, instr);
	// instr_b = presort_stack_b(stvar, bottom, &j);
	// if (instr_b != NULL)
	// {
	// 	do_op(stvar, instr_b, 'b', j);
	// 	check_dble(stvar, instr_b);
	// }
	do_op(stvar, PB, 'b', 1);
	find_solution(stvar, stvar->stack_b, NULL);
}

void	check_top_b(t_pw_var *stvar)
{
	int		i;
	t_stack *temp;
	char	*str;

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
