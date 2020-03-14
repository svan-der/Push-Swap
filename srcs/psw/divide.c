/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:15:57 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/14 17:57:28 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		divide_and_presort(t_format *stvar, int *sorted_list)
{
	int i;

	i = 0;
	while (stvar->index > 3)
	{
		part_sort(stvar, ft_min_size(stvar->index, stvar->argc));
		if (stvar->index <= 3)
		{
			sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
			break ;
		}
		sorted_list = lst_cpy(stvar->stack_a, *(&sorted_list));
		stvar->tail = sorted_list[stvar->index - 1];
		insertion_sort(sorted_list, stvar->index, &stvar->min, &stvar->max);
		stvar->median = find_median_array(sorted_list, stvar->index);
		i++;
	}
	return (conquer_list(stvar, sorted_list));
}

// void		ft_memdel(void **ap)
// {
// 	if (*ap)
// 	{
// 		free(*ap);
// 		*ap = NULL;
// 	}
// }

void	divide_list(t_format *stvar)
{
	int i;
	int *sorted_list;

	i = 0;
	sorted_list = (int *)malloc(sizeof(int));
	sorted_list = lst_cpy(stvar->stack_a, sorted_list);
	stvar->tail = sorted_list[stvar->argc - 1];
	insertion_sort(sorted_list, stvar->argc, &stvar->min, &stvar->max);
	stvar->median = find_median_array(sorted_list, stvar->index);
	divide_and_presort(stvar, sorted_list);
}
