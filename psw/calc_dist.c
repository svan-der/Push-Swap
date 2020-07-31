/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_dist.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 12:40:08 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:08:57 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_distance(t_stack *stack, int num, int *sorted)
{
	t_stack *temp;
	int		i;
	int		j;

	temp = stack;
	i = 0;
	j = 0;
	while (temp != NULL && temp->num != num)
	{
		temp = temp->next;
		j++;
	}
	while (sorted[i] != num)
		i++;
	temp->dist = j - i;
	temp->dist_top = j;
	stack = temp;
}

void	find_part(t_pw_var *stvar, int i)
{
	t_stack *bottom;
	t_stack *top;
	int		ret;

	top = find_top_part(stvar, i);
	bottom = find_bottom_part(stvar, i);
	ret = shortest_dist(stvar, top, bottom);
	if (ret == 0)
		sort_top(stvar, top);
	else if (ret != 0)
		sort_bottom(stvar, bottom);
}

int		shortest_dist(t_pw_var *stvar, t_stack *top, t_stack *bottom)
{
	int		dist_top;
	int		dist_bottom;
	int		len;
	int		i;

	if (stvar->stack_b == NULL)
		return (0);
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
	if (dist_top == dist_bottom && top->dist_top > bottom->dist_top)
		return (1);
	if (dist_top < dist_bottom)
		return (0);
	return (1);
}

char	*fastest_rotate(t_pw_var *stvar, char c, int *index)
{
	int i;
	int len;

	len = (c == 'a') ? stvar->index : (stvar->argc - stvar->index);
	i = (len % 2) ? ((len / 2) + 1) : len / 2;
	if (*index < i)
	{
		return (c == 'a' ? RA : RB);
	}
	else
	{
		*index = len - *index;
		return (c == 'a' ? RRA : RRB);
	}
}
