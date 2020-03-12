/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:52:42 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/12 13:14:53 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void print_array(int *list, int argc)
// {
// 	int i;

// 	i = 0;
// 	while (i < argc)
// 	{
// 		printf("this is number:%i\n", list[i]);
// 		i++;
// 	}
// }

// void	set_min_maxarray(t_format *stvar, int *list, int len)
// {
// 	int i;
// 	int num;

// 	i = 0;
// 	num = list[i];
// 	stvar->min = list[i];
// 	stvar->max = list[i];
// 	while (i < len)
// 	{
// 		if (stvar->min > list[i])
// 			stvar->min = list[i];
// 		if (stvar->max < list[i])
// 			stvar->max = list[i];
// 		i++;
// 	}
// }

// void	set_min_max(t_part *part_var)
// {
// 	int i;
// 	int	len;

// 	i = 0;
// 	len = (int)part_var->len;
// 	part_var->min = 0;
// 	part_var->max = 0;
// 	while (i < len)
// 	{
// 		if (part_var->min > part_var->parts[i] || !part_var->min)
// 			part_var->min = part_var->parts[i];
// 		if (part_var->max < part_var->parts[i] || !part_var->max)
// 			part_var->max = part_var->parts[i];
// 		i++;
// 	}
// }

// int find_median_array(int *list, int index)
// {
// 	int i;
// 	double j;
// 	int median;

// 	j = (double)index / 2;
// 	i = j;
// 	median = list[i];
// 	print_array(list, index);
// 	return (median);
// }

// int *lst_cpy(t_stack *stack, int *new_list)
// {
// 	t_stack *current;
// 	int i;
// 	int j;

// 	current = stack;
// 	i = 0;
// 	j = 0;
// 	while (current != NULL)
// 	{
// 		new_list[i] = (*current->num);
// 		current = current->next;
// 		i++;
// 	}
// 	return (new_list);
// }

// void *ft_calloc(size_t count, size_t size)
// {
// 	void *res;

// 	res = (char *)malloc(size * count);
// 	if (!res)
// 		return (NULL);
// 	ft_bzero(res, count * size);
// 	return (res);
// }

// int run_pw(t_format *stvar)
// {
// 	t_part *part_var;

// 	part_var = NULL;
// 	// ft_bzero(&part_var, sizeof(t_part));
// 	if (stvar->argc > 3)
// 	{
// 		divide_list(stvar, part_var);
// 	}
// 	else
// 		sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
// 	printf("total number of instructions:|%i|\n\n", stvar->total_ins);
// 	return (1);
// }
