/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:15:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/06/05 17:53:12 by svan-der      ########   odam.nl         */
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

// void	calc_dist_top(t_pw_var *stvar)
// {
	
// }

void	assign_partitions(t_pw_var *stvar)
{
	int num;

	num = (stvar->argc <= 100) ? (stvar->argc / 5) : (stvar->argc / 11); 
	ft_printf("amount of partitions:%i\n", num);
	print_stack_list(stvar->stack_a, 'a');
}

int		 divide_and_presort(t_pw_var *stvar, int *sorted_list)
{
	int i;
	// int ret;
	
	i = 0;
	assign_partitions(stvar);
	(void)sorted_list;
	part_sort(stvar, ft_min_size(stvar->index, stvar->argc));
	// while (stvar->index > 3)
	// {
	// 	part_sort(stvar, ft_min_size(stvar->index, stvar->argc));
	// 	ft_printf("stvar->index:%d\n", stvar->index);
	// 	ft_printf("stvar sorted:%i\n", stvar->sort_index);
	// 	if (stvar->index <= 3)
	// 	{
	// 		sort_three(stvar, stvar->min, stvar->max);
	// 		break ;
	// 	}
		// sorted_list = lst_cpy(&(stvar)->stack_a, *(&sorted_list));
		// // stvar->tail = sorted_list[stvar->index - 1];
		// insertion_sort(sorted_list, stvar->index, &stvar->min, &stvar->max);
		// stvar->median = find_median_array(sorted_list, stvar->index);
		// i++;
	// }
	print_stack_list(stvar->stack_a, 'a');
	return (1);
	// return (conquer_list(stvar, sorted_list));
}

int		divide_list(t_pw_var *stvar)
{
	stvar->median = find_median_array(stvar->sorted, stvar->index);
	// ft_printf("median is:%d\n\n", stvar->median);
	// ft_printf("stvar->sort_index:%i\n", stvar->sort_index);
	// ft_printf("stvar->index:%i\tstvar->argc:%i\n", stvar->index, stvar->argc);
	if (stvar->argc < 6)
		return (sort_five_stack(stvar, 'a', stvar->index - stvar->sort_index));
	// ft_printf("return after sorting:%i\n", ret);
	else if (stvar->argc < 11)
		return (sort_short_stack(stvar, ft_min_size(stvar->index, stvar->argc)));
	else
	{
		return (divide_and_presort(stvar, stvar->sorted));
	}
}
