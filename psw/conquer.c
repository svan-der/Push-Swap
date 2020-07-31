/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:35:59 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:05:55 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sort_short_stack(t_pw_var *stvar, int argc)
{
	int ret;
	int j;

	ret = 1;
	j = (argc % 2) ? ((argc + 1) / 2) : argc / 2;
	argc = j;
	while (stvar->index != j)
	{
		if (stvar->stack_a->num < stvar->median)
			ret = do_op(stvar, PB, 'b', 1);
		else
			ret = do_op(stvar, RA, 'a', 1);
		if (ret == -1)
			error_handling(stvar, NULL, -1);
	}
	ret = sort_five_stack(stvar, 'a', stvar->index);
	if (ret == -1)
		error_handling(stvar, NULL, -1);
	set_min_max(stvar, 'b');
	ret = sort_five_stack(stvar, 'b', stvar->argc - stvar->index);
	if (ret != 1)
		error_handling(stvar, NULL, -1);
	return (ret);
}

void	push_back_part(t_pw_var *stvar, int argc)
{
	int		total;
	char	*instr;
	t_stack	*current;

	total = stvar->argc - 1;
	while (argc)
	{
		current = find_high(stvar, 'b', &total);
		if (current->dist_top == 1)
		{
			instr = SB;
			if (current->prev && current->next)
				instr = (current->prev->num < current->next->num) ? RB : SB;
			do_op(stvar, instr, 'b', 1);
		}
		else if (current->dist_top > 1)
		{
			instr = fastest_rotate(stvar, 'b', &current->dist_top);
			do_op(stvar, instr, 'a', current->dist_top);
		}
		do_op(stvar, PA, 'b', 1);
		argc--;
		total--;
	}
}

void	part_sort(t_pw_var *stvar, int argc, int i)
{
	t_stack *top;
	t_stack *bottom;
	int		j;

	j = argc;
	while (j)
	{
		top = stvar->stack_a;
		bottom = stvar->stack_a->tail;
		if (top->part_id == i && bottom->part_id != i)
			sort_top(stvar, top);
		else if (bottom->part_id == i && top->part_id != i)
			sort_bottom(stvar, bottom);
		else
			find_part(stvar, i);
		check_top_b(stvar);
		j -= 1;
	}
}

void	insertion_sort(int *list, int argc)
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
}
