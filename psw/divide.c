/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:15:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/29 18:22:49 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"
#include "../includes/push_swap.h"

// /*
// ** functions divides the list in partitions
// */

// int		divide_and_presort(t_pw_var *stvar, int *sorted_list)
// {
// 	int i;

// 	i = 0;
// 	while (stvar->index > 3)
// 	{
// 		part_sort(stvar, ft_min_size(stvar->index, stvar->argc));
// 		ft_printf("stvar->index:%d\n", stvar->index);
// 		if (stvar->index <= 3)
// 		{
// 			sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
// 			break ;
// 		}
// 		sorted_list = lst_cpy(&(stvar)->stack_a, *(&sorted_list));
// 		// stvar->tail = sorted_list[stvar->index - 1];
// 		insertion_sort(sorted_list, stvar->index, &stvar->min, &stvar->max);
// 		stvar->median = find_median_array(sorted_list, stvar->index);
// 		i++;
// 	}
// 	// return (1);
// 	return (conquer_list(stvar, sorted_list));
// }

// void		ft_memdel(void **ap)
// {
// 	if (*ap)
// 	{
// 		free(*ap);
// 		*ap = NULL;
// 	}
// }

// int		divide_and_presort(t_pw_var *stvar, int *sorted_list)
// {
// 	int i;
// 	int ret;

// 	i = 0;
// 	while (stvar->index > 3)
// 	{
// 		part_sort(stvar, ft_min_size(stvar->index, stvar->argc));
// 		ft_printf("stvar->index:%d\n", stvar->index);
// 		ft_printf("stvar sorted:%i\n", stvar->sort_index);
// 		if (stvar->argc - stvar->sort_index < 6)
// 		{
// 			ret = sort_five_stack(stvar, stvar->argc - stvar->sort_index);
// 			if (stvar->argc - stvar->sort_index != 0)
// 			ret = sort_five_stack(stvar, stvar->argc - stvar->sort_index);
// 		}
// 		// if (stvar->index <= 3)
// 		// {
// 		// 	sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
// 		// 	break ;
// 		// }
// 		// sorted_list = lst_cpy(&(stvar)->stack_a, *(&sorted_list));
// 		// // stvar->tail = sorted_list[stvar->index - 1];
// 		// insertion_sort(sorted_list, stvar->index, &stvar->min, &stvar->max);
// 		// stvar->median = find_median_array(sorted_list, stvar->index);
// 		// i++;
// 	}
// 	return (1);
// 	// return (conquer_list(stvar, sorted_list));
// }

int		divide_list(t_pw_var *stvar)
{
	int ret;

	stvar->median = find_median_array(stvar->sorted, stvar->index);
	// ft_printf("median is:%d\n\n", stvar->median);
	if (stvar->argc < 6)
		return (sort_five_stack(stvar, 'a', stvar->index - stvar->sort_index));
	// ft_printf("return after sorting:%i\n", ret);
	else if (stvar->argc < 11)
		ret = sort_short_stack(stvar, ft_min_size(stvar->index, stvar->argc));
	// else
	// {
	// 	divide_and_presort(stvar, stvar->sorted);
	// }
	return (ret);
}
