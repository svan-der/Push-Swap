/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_top_bottom_part.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 15:53:37 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/30 15:54:37 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/psw_env.h"

t_stack	*find_bottom_part(t_pw_var *stvar, int i)
{
	t_stack *temp;
	int		j;

	temp = stvar->stack_a->tail;
	j = 1;
	while (temp)
	{
		if (temp->part_id == i)
		{
			temp->dist_top = stvar->index - j;
			return (temp);
		}
		temp = temp->prev;
		j++;
	}
	return (temp);
}

t_stack	*find_top_part(t_pw_var *stvar, int i)
{
	t_stack *temp;
	int		j;

	temp = stvar->stack_a;
	j = 0;
	while (temp)
	{
		if (temp->part_id == i)
		{
			temp->dist_top = j;
			return (temp);
		}
		temp = temp->next;
		j++;
	}
	return (temp);
}
