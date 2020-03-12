/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:15:57 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/12 18:02:55 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_addpart(t_part **part_var, t_part *new)
// {
// 	if (*part_var != NULL)
// 	{
// 		(new)->next = *part_var;
// 		(*part_var)->prev = new;
// 		*part_var = new;
// 	}
// 	else
// 	{
// 		*part_var = new;
// 		(*part_var)->prev = NULL;
// 	}
// }

// t_part	*create_part(int argc, int *list)
// {
// 	t_part *part;

// 	(void)list;
// 	// (void)argc;
// 	part = (t_part *)malloc(sizeof(t_part));
// 	// if (part == NULL)
// 	// 	return (NULL);
// 	// ft_bzero(&part, sizeof(t_part));
// 	part->len = argc;
// 	// part->max = 0;
// 	// part->min = 0;
// 	// part->next = NULL;
// 	// part->prev = NULL;
// 	// part->parts = list;
// 	// part->parts = (int *)ft_memdup(list, argc);
// 	// if (part->parts == NULL)
// 	// 	return (NULL);
// 	return (part);
// }

// int		part_addnew(t_part **part_var, int *list, int argc)
// {
// 	t_part *new;

// 	new = create_part(argc, list);
// 	if (!new)
// 		return (error_handler(1));
// 	if (*part_var == NULL)
// 	{
// 		*part_var = new;
// 		(*part_var)->prev = NULL;
// 		return (1);
// 	}
// 	if (*part_var != NULL)
// 		ft_addpart(part_var, new);
// 	return (1);
// }

int		divide_and_presort(t_format *stvar, t_part *part_var, int *sorted_list)
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
		insertion_sort(sorted_list, stvar->index, &stvar->min, &stvar->max);
		stvar->median = find_median_array(sorted_list, stvar->index);
		i++;
	}
	return (conquer_list(stvar, part_var, sorted_list));
}

// void		ft_memdel(void **ap)
// {
// 	if (*ap)
// 	{
// 		free(*ap);
// 		*ap = NULL;
// 	}
// }

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
