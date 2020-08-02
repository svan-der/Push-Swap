/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 14:08:00 by svan-der      #+#    #+#                 */
/*   Updated: 2020/08/01 17:48:32 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_median_array(int *list, int index)
{
	int		i;
	double	j;
	int		median;

	j = (double)index / 2;
	i = j;
	median = list[i];
	return (median);
}

void	set_min_max(t_pw_var *stvar, char c)
{
	int		min;
	int		max;
	t_stack *temp;

	if (c == 'a')
		temp = stvar->stack_a;
	if (c == 'b')
		temp = stvar->stack_b;
	min = temp->num;
	max = temp->num;
	while (temp != NULL && temp->next != NULL)
	{
		if (min > temp->next->num)
			min = temp->next->num;
		if (max < temp->next->num)
			max = temp->next->num;
		temp = temp->next;
	}
	stvar->min = min;
	stvar->max = max;
}

/*
** function sets for unsorted list the sorted index per number
*/

void	set_index(t_stack **stack_a, int *sorted, int argc)
{
	int		i;
	int		j;
	t_stack *temp;

	i = 0;
	j = 0;
	temp = *stack_a;
	while (argc)
	{
		if (temp->num == sorted[i])
		{
			temp->dist = j - i;
			temp->dist_top = j;
			temp->index = i;
			if (temp->next != NULL)
				temp = temp->next;
			else
				break ;
			i = 0;
			j += 1;
			argc -= 1;
		}
		else
			i++;
	}
}

int		do_op(t_pw_var *stvar, char *str, char c, int num)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < num)
	{
		ret = dispatch_sort(stvar, str, 1);
		if (ret == -1)
			error_handling(stvar, NULL, -1);
		update_stack(stvar, c);
		set_index(&stvar->stack_a, stvar->sorted, stvar->index);
		set_index(&stvar->stack_b, stvar->sorted, stvar->argc - stvar->index);
		i++;
	}
	return (1);
}

void	update_stack(t_pw_var *stvar, char c)
{
	t_stack *temp;

	if (c == 'a')
		temp = stvar->stack_a;
	if (c == 'b')
		temp = stvar->stack_b;
	if (c == 'a')
	{
		while (temp != NULL && temp->next != NULL)
		{
			find_distance(temp, temp->num, stvar->sorted);
			temp = temp->next;
		}
	}
	add_tail(&stvar->stack_a);
	add_tail(&stvar->stack_b);
}
