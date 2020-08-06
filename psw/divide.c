/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:15:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/08/01 17:45:30 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		set_part_id(t_stack *stack, int index, int *i, int *j)
{
	stack->part_id = index;
	*i += 1;
	*j += 1;
}

static void		set_partitions(t_pw_var *stvar, int parts, int len, int index)
{
	t_stack *temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = stvar->stack_a;
	while (parts)
	{
		if (j == len)
		{
			j = 0;
			parts -= 1;
			index += 1;
			if (parts == 1)
				len = (stvar->argc - i);
		}
		if (temp->num == stvar->sorted[i])
			set_part_id(temp, index, &i, &j);
		temp = temp->next;
		if (temp == NULL)
			temp = stvar->stack_a;
	}
}

static int		assign_partitions(t_pw_var *stvar, int *part_num)
{
	int partitions;
	int num;

	partitions = 1;
	num = stvar->argc;
	if (num < 100)
	{
		while (num > 10)
		{
			num = (num / 2);
			partitions++;
		}
	}
	if (num >= 100 && num < 500)
		partitions = 5;
	else if (num == 500)
		partitions = 11;
	*part_num = ((stvar->argc % partitions)) ? 1 : 0;
	*part_num += (stvar->argc / partitions);
	set_partitions(stvar, partitions, *part_num, 1);
	return (partitions);
}

void			divide_and_presort(t_pw_var *stvar)
{
	int part_index;
	int	part_num;
	int	i;
	int	j;

	i = 1;
	part_index = assign_partitions(stvar, &part_num);
	j = (part_num - 1) / 2;
	while (part_index != 0)
	{
		stvar->median = (stvar->sorted[j]);
		part_index--;
		if (part_index == 0)
			part_num = stvar->index;
		part_sort(stvar, part_num, i);
		i++;
		j += (part_num);
	}
	push_back_part(stvar, stvar->argc);
}

void			divide_list(t_pw_var *stvar, int argc, int index)
{
	if (argc < 11)
		sort_short_stack(stvar, ft_min_size(index, argc));
	else
		divide_and_presort(stvar);
}
