/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 17:07:02 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:06:12 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		find_max(t_stack *current, int max, int *j)
{
	while (current && current->num != max)
	{
		*j += 1;
		current = current->next;
	}
}

t_stack		*find_high(t_pw_var *stvar, char c, int *index)
{
	t_stack	*current;
	int		dist_top;

	current = (c == 'a') ? stvar->stack_a : stvar->stack_b;
	dist_top = 0;
	while (current)
	{
		if (current->index == *index)
			return (current);
		dist_top++;
		current = current->next;
	}
	return (NULL);
}

char		*find_low(t_pw_var *stvar, char c, int *index)
{
	t_stack	*current;
	int		dist_top;

	current = (c == 'a') ? stvar->stack_a : stvar->stack_b;
	dist_top = 0;
	while (current)
	{
		if (current->index == *index)
			break ;
		dist_top++;
		current = current->next;
	}
	if (dist_top == 0)
	{
		*index = ((c == 'a')) ? *index + 1 : *index - 1;
		return ((c == 'a') ? PB : PA);
	}
	else
	{
		if (dist_top == 1)
			return (c == 'a' ? SA : SB);
		return (fastest_rotate(stvar, c, &dist_top));
	}
}
