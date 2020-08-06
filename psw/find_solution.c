/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_solution.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 17:14:33 by svan-der      #+#    #+#                 */
/*   Updated: 2020/08/02 16:10:41 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** checks the dist between top and next, top and next->next, top and btm num
** either stays put, swaps or rotates current number based on smallest dist
*/

void	find_solution(t_pw_var *stvar, t_stack *current)
{
	int top_next;
	int top_next_next;
	int bottom;
	int	ret;

	bottom = stvar->stack_b->tail->num;
	top_next = stvar->stack_b->next->num;
	bottom = ft_abs(current->num - bottom);
	top_next = ft_abs(current->num - top_next);
	ret = ft_min_size(top_next, bottom);
	if (stvar->stack_b->next->next != NULL)
	{
		top_next_next = stvar->stack_b->next->next->num;
		top_next_next = ft_abs(current->num - top_next_next);
		if (ret > top_next_next)
		{
			ret = top_next_next;
			if (current->num < stvar->median)
				return ;
			do_op(stvar, SB, 'b', 1);
		}
	}
	else if (ret == bottom && ret != top_next)
		do_op(stvar, RB, 'b', 1);
}
