/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:15:57 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/05 17:23:26 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*set_parts(t_part **part_var, int i, int argc)
{
	t_part *new;

	new = (t_part *)ft_memalloc(sizeof(t_part));
	if (i == 0)
	{
		(*part_var)->next = NULL;
	}
	else
	{
		(*part_var)->next = NULL;
		(*part_var)->prev = new;
		new->next = (*part_var);
		(*part_var) = new;
	}
	(*part_var)->parts = ft_calloc(argc / (i + 1 * 2), sizeof(int));
	return ((*part_var)->parts);
}

void	divide_and_presort(t_format *stvar, t_part *part_var)
{
	int i;
	int b_len;
	int *temp1;

	i = 0;
	while (stvar->index > 3)
	{
		part_var->parts = set_parts(&part_var, i, stvar->argc);
		part_sort(stvar, part_var, ft_min_size(stvar->index, stvar->argc));
		set_min_max(part_var);
		b_len += part_var->len;
		if (stvar->index <= 3)
		{
			sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
			break ;
		}
		temp1 = lst_cpy(stvar->stack_a, stvar->index);
		insertion_sort(temp1, stvar->index, &stvar->min, &stvar->max);
		stvar->median = find_median_array(temp1, stvar->index, stvar->sort_index, part_var->len);
		ft_memdel(&temp1);
		i++;
	}
	conquer_list(stvar, part_var);
}

void		ft_memdel(void **ap)
{
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	divide_list(t_format *stvar, t_part *part_var)
{
	int i;
	int *temp1;

	i = 0;
	temp1 = lst_cpy(stvar->stack_a, stvar->argc);
	insertion_sort(temp1, stvar->argc, &stvar->min, &stvar->max);
	stvar->median = find_median_array(temp1, stvar->index, stvar->sort_index, part_var->len);
	ft_memdel(&temp1);
	divide_and_presort(stvar, part_var);
}
