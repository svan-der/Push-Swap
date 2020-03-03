/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:52:42 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/03 18:08:33 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_array(int *list, int argc)
{
	int i;

	i = 0;
	while (i < argc)
	{
		printf("this is number:%i\n", list[i]);
		list[i];
		i++;
	}
}

void	set_min_max(t_part *part_var)
{
	int i;

	i = 0;
	part_var->min = 0;
	part_var->max = 0;
	while (i < part_var->len)
	{
		if (part_var->min > part_var->parts[i] || !part_var->min)
			part_var->min = part_var->parts[i];
		if (part_var->max < part_var->parts[i] || !part_var->max)
			part_var->max = part_var->parts[i];
		i++;
	}
}

// int find_median(t_stack *stack, int argc, int index)
// {
// 	int i;
// 	int num;
// 	double j;
// 	double median;
// 	t_stack *temp;

// 	if (index == argc)
// 	{
// 		j = (double)argc / 2;
// 		if (argc % 2 == 0)
// 			j -= 1;
// 	}
// 	else
// 	{
// 		j = (double)index / 2;
// 		if (index % 2 == 0)
// 			j -= 1;
// 	}
// 	i = j;
// 	temp = stack;
// 	while (i)
// 	{
// 		temp = temp->next;
// 		i--;
// 	}
// 	median = temp->num;
// 	return (median);
// }

int find_median_array(int *list, int index, int sort, int b_len)
{
	int i;
	double j;
	double median;

	j = (double)index / 2;
	i = j;
	median = list[i];
	print_array(list, index);
	return (median);
}

// int	find_median_b(int *list, int index, int sort, int b_len)
// {
// 	int i;
// 	int len;
// 	double j;
// 	double median;

// 	if (b_len > 3)
// 	{
// 		len = ((index - 1) / 2) + 1;
// 		median = list[len - 1];
// 	}
// 	else
// 	{
// 		median = list[]
// 	}
	

// }

// int find_median_a(int *list, int index, int sort, int b_len)
// {
// 	int i;
// 	int len;
// 	double j;
// 	double median;

// 	j = (double)index / 2;
// 	if (index < 6)
// 	{
// 		j -= 1;
// 		i = j;
// 		median = list[i];
// 	}
// 	else if (sort == 0)
// 	{
// 		len = ((index - 1) / 2) + 1;
// 		median = list[len - 1];
// 	}
// 	else
// 	{
// 		len = (((index - sort) - 1) / 2) + 1;
// 		median = list[((b_len + len) - 1)];
// 	}
// 	print_array(list, index);
// 	return (median);
// }

int *lst_cpy(t_stack *stack, int argc)
{
	t_stack *current;
	int *new_list;
	int i;
	int j;

	// new_list = NULL;
	// new_list = (int *)malloc(sizeof(int) * (argc - 1));
	new_list = (int *)malloc(sizeof(int));
	current = stack;
	i = 0;
	j = 0;
	while (current != NULL)
	{
		new_list[i] = current->num;
		current = current->next;
		i++;
	}
	return (new_list);
}

void *ft_calloc(size_t count, size_t size)
{
	void *res;

	res = (char *)malloc(size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

int run_pw(t_format *stvar)
{
	t_part *part_var;

	part_var = (t_part *)ft_memalloc(sizeof(t_part *));
	ft_bzero(part_var, sizeof(t_part));
	if (!part_var)
		return (0);
	if (stvar->argc > 3)
	{
		divide_list(stvar, part_var);
		conquer_list(stvar, part_var);
	}
	else
		sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
	printf("total number of instructions:|%i|\n\n", stvar->total_ins);
	return (1);
}
