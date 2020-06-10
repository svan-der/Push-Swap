/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:15:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/06/10 15:48:43 by svan-der      ########   odam.nl         */
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

int	assign_partitions(t_pw_var *stvar)
{
	int num;

	num = (stvar->argc <= 100) ? (stvar->argc / 5) : (stvar->argc / 11); 
	// ft_printf("amount of partitions:%i\n", num);
	// print_stack_list(stvar->stack_a, 'a');
	return (num);
}

void	sort_short_opts(t_pw_var *stvar)
{
	if (stvar->index == 2)
		sort_two('a', stvar);
	else if (stvar->index == 3)
		sort_three(stvar, stvar->min, stvar->max);
	else if (stvar->index < 6)
		sort_five_stack(stvar, 'a', stvar->index - stvar->sort_index);
}

int		 divide_and_presort(t_pw_var *stvar, int *sorted_list)
{
	int i;
	// int ret;
	
	i = 0;
	i = assign_partitions(stvar);
	ft_printf("median:%i\n", stvar->median);
	print_stack_list(stvar->stack_a, 'a');
	// print_array(stvar->sorted, stvar->argc);
	// print_tail(stvar->stack_a->tail);
	(void)sorted_list;
	while (i)
	{
		i--;
		// ft_printf("going to part_sort\n");
		// ft_printf("res is:%i\n", ft_min_size(stvar->index, stvar->argc));
		part_sort(stvar, ft_min_size(stvar->index, stvar->argc));
		stvar->sorted = lst_cpy(stvar);
		// ft_printf("stvar->index:%i\n", stvar->index);
		insertion_sort(stvar->sorted, stvar->index, &stvar->min, &stvar->max);
		// print_array(stvar->sorted, stvar->argc);
		set_index(&(stvar)->stack_a, stvar->sorted, stvar->index);
		stvar->median = find_median_array(stvar->sorted, stvar->index);
	}
	// i = stvar->argc - stvar->index;
	// sort_short_opts(stvar);
	// // print_stack_list(stvar->stack_a, 'a');
	// // print_stack_list(stvar->stack_b, 'b');
	// // ft_printf("here\n");
	// // ft_printf("last opt is:%i\n", i);
	// dispatch_sort(stvar, PA, i);
	// print_stack_list(stvar->stack_a, 'a');
	// print_stack_list(stvar->stack_b, 'b');
	return (1);
	// return (conquer_list(stvar, sorted_list));
}

int		divide_list(t_pw_var *stvar)
{
	stvar->median = find_median_array(stvar->sorted, stvar->index);
	// print_tail(stvar->stack_a->tail);
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
