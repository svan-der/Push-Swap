/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:35:59 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/06 15:29:46 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_format *stvar, t_part *part_var, int argc, int sum)
{
	t_stack *temp;
	int num;
	int	max;
	int min;
	int j;
	int i;

	i = 0;
	temp = stvar->stack_b;
	if (temp == NULL)
		return ;
	j = 0;
	while (j < argc)
	{
		j++;
		num = temp->num;
		if (num > stvar->median && num)
		{
			ft_putstr("pa\n");
			push_a(&stvar->stack_a, &temp);
			if (stvar->stack_a->next == NULL)
				stvar->stack_a->prev == NULL;
			stvar->sort_index += 1;
			stvar->index += 1;
			sum -= 1;
		}
		else
		{
			part_var->parts[i] = temp->num;
			i++;
			// if (temp->next->num < temp->num)
			// 	swap_a(&temp);
			// else
			// 	rotate_reva(&temp);
			rotate_b(&temp);
		}
		if (sum == 0)
			break ;
		stvar->total_ins += 1;
	}
	stvar->stack_b = temp;
	part_var->len = i + 1;
}

void	conquer_list(t_format *stvar, t_part *part_var)
{
	int *temp1;
	int size;

	while (stvar->index != stvar->argc && stvar->sort_index < stvar->argc)
	{
		if (part_var->next == NULL && part_var->len > 3)
		{
			insertion_sort(part_var->parts, part_var->len, &part_var->min, &part_var->max);
			stvar->median = find_median_array(part_var->parts, part_var->len);
			push_back(stvar, part_var, ft_min_size(part_var->len, 6), (part_var->len / 2));
			set_min_max(part_var);
		}
		else if (stvar->index == stvar->sort_index && part_var->len <= 3)
		{
			sort_short(stvar, &part_var);
			part_var = part_var->next;
		}
		else
		{
			size = (part_var->len / 2);
			insertion_sort(part_var->parts, part_var->len, &part_var->min, &part_var->max);
			stvar->median = find_median_array(part_var->parts, part_var->len);
			push_back(stvar, part_var, part_var->len, ft_min_size((part_var->len / 2), 3));
			set_min_max(part_var);
		}
	}
}
