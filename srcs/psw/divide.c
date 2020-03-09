/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:15:57 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/09 17:25:02 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addpart(t_part **part_var, t_part *new, int i)
{
	if (i != 0)
	{
		(new)->next = *part_var;
		(*part_var)->prev = new;
		*part_var = new;
	}
	else
		*part_var = new;
}

int		set_parts(t_part **part_var, int i, int argc)
{
	t_part *new;

	new = ft_memalloc(sizeof(t_part));
	if (!new)
		return (0);
	new->parts = (int *)malloc(sizeof(int));
	ft_addpart(part_var, new, i);
	return (1);
}

void	divide_and_presort(t_format *stvar, t_part *part_var)
{
	int i;
	int ret;
	int *temp1;

	i = 0;
	while (stvar->index > 3)
	{
		ret = set_parts(&part_var, i, stvar->argc);
		if (ret == 0)
			return ;
		part_sort(stvar, part_var, ft_min_size(stvar->index, stvar->argc));
		set_min_max(part_var);
		if (stvar->index <= 3)
		{
			sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
			break ;
		}
		temp1 = lst_cpy(stvar->stack_a, stvar->index);
		insertion_sort(temp1, stvar->index, &stvar->min, &stvar->max);
		stvar->median = find_median_array(temp1, stvar->index);
		if (temp1 != NULL)
			free(temp1);
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
	stvar->median = find_median_array(temp1, stvar->index);
	if (temp1 != NULL)
		free(temp1);
	divide_and_presort(stvar, part_var);
}
