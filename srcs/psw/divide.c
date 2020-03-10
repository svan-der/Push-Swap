/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:15:57 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/10 14:33:48 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addpart(t_part **part_var, t_part *new)
{
	if (*part_var != NULL)
	{
		(new)->next = *part_var;
		(*part_var)->prev = new;
		*part_var = new;
	}
	else
	{
		*part_var = new;
		(*part_var)->prev = NULL;
	}
}

t_part	*create_part(int argc)
{
	t_part *part;

	part = (t_part *)malloc(sizeof(t_part));
	if (part == NULL)
		return (NULL);
	part->len = 0;
	part->max = 0;
	part->min = 0;
	part->next = NULL;
	part->prev = NULL;
	part->parts = malloc(sizeof(int) * argc);
	if (part->parts == NULL)
		return (NULL);
	return (part);
}

int		part_addnew(t_part **part_var, int argc)
{
	t_part *new;

	new = create_part(argc);
	if (!new)
		return (error_handler(1));
	if (*part_var == NULL)
	{
		*part_var = new;
		(*part_var)->prev = NULL;
	}
	if (*part_var != NULL)
		ft_addpart(part_var, new);
	return (1);
}

int		divide_and_presort(t_format *stvar, t_part *part_var, int *sorted_list)
{
	int i;
	int ret;

	i = 0;
	if (part_var == NULL)
		part_var = (t_part *)malloc(sizeof(t_part));
	while (stvar->index > 3)
	{
		ret = part_addnew(&part_var, stvar->argc);
		if (ret == 0)
			return (error_handler(2));
		part_sort(stvar, part_var, ft_min_size(stvar->index, stvar->argc));
		set_min_max(part_var);
		if (stvar->index <= 3)
		{
			sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
			break ;
		}
		sorted_list = lst_cpy(stvar->stack_a, sorted_list);
		insertion_sort(sorted_list, stvar->index, &stvar->min, &stvar->max);
		stvar->median = find_median_array(sorted_list, stvar->index);
		i++;
	}
	return (conquer_list(stvar, part_var));
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
	int *sorted_list;

	i = 0;
	sorted_list = (int *)malloc(sizeof(int));
	sorted_list = lst_cpy(stvar->stack_a, sorted_list);
	insertion_sort(sorted_list, stvar->argc, &stvar->min, &stvar->max);
	stvar->median = find_median_array(sorted_list, stvar->index);
	divide_and_presort(stvar, part_var, sorted_list);
}
