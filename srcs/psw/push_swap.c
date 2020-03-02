/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:52:42 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/02 15:23:12 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "psw_env.h"
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

void sort_three(t_stack **temp, t_format *stvar, int min, int max)
{
	t_stack *stack;

	stack = *temp;
	if (stack->num == min)
	{
		print_stack(stack, 1);
		if (stack->next->num != max)
			return ;
		else if (stack->next->num == max)
		{
			stvar->total_ins += 2;
			rotate_revb(&stack);
			swap_b(&stack);
		}
		print_stack_b(stack, 1);
	}
	else if (stack->num == max)
	{
		if (stack->next->num == min)
		{
			stvar->total_ins += 1;
			rotate_b(&stack);
		}
		else
		{
			stvar->total_ins += 2;
			swap_b(&stack);
			rotate_revb(&stack);
		}
	}
	else if (stack->num != max && stack->num != min)
	{
		if (stack->next->num == max)
		{
			rotate_revb(&stack);
		}
		else if (stack->next->num == min)
			swap_b(&stack);
		stvar->total_ins += 1;
	}
	*temp = stack;
	stvar->sort_index += 3;
}

void	push_back(t_format *stvar, t_part *part_var, int argc)
{
	t_stack *temp;
	int num;
	int	max;
	int min;
	int j;
	int i;

	i = 0;
	temp = stvar->stack_b;
	if (temp == NULL)
		return ;
	j = 0;
	while (j < argc)
	{
		j++;
		num = temp->num;
		if (num > stvar->median && num)
		{
			max = (!max || max < num) ? num : max;
			min = (!min || min > num) ? num : min;
			ft_putstr("pa\n");
			stvar->total_ins += 1;
			push_a(&stvar->stack_a, &temp);
			if (stvar->stack_a->next == NULL)
				stvar->stack_a->prev == NULL;
			stvar->index += 1;
			i++;
		}
		else
		{
			stvar->total_ins += 1;
			part_var->parts[i] = temp->num;
			if (part_var->min > part_var->parts[i] || !part_var->min)
				part_var->min = part_var->parts[i];
			if (part_var->max < part_var->parts[i] || !part_var->max)
				part_var->max = part_var->parts[i];
			rotate_b(&temp);
		}
	}
	stvar->stack_b = temp;
	part_var->len = i;
	sort_three(&stvar->stack_a, stvar, min, max);
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

void	part_sort(t_format *stvar, t_part *part_var, int argc)
{
	t_stack *temp;
	int num;
	int j;
	int i;

	i = 0;
	temp = stvar->stack_a;
	if (temp == NULL)
		return ;
	j = 0;
	while (j < argc)
	{
		if (stvar->index <= 3)
			break ;
		j++;
		num = temp->num;
		if (num < stvar->median && num)
		{
			part_var->parts[i] = temp->num;
			ft_putstr("pb\n");
			stvar->total_ins += 1;
			push_b(&temp, &stvar->stack_b);
			if (stvar->stack_b->next == NULL)
				stvar->stack_b->prev == NULL;
			stvar->index -= 1;
			i++;
			part_var->len = i;
		}
		else
			rotate_a(&temp);
		stvar->total_ins += 1;
	}
	stvar->stack_a = temp;
}

int find_median(t_stack *stack, int argc, int index)
{
	int i;
	int num;
	double j;
	double median;
	t_stack *temp;

	if (index == argc)
	{
		j = (double)argc / 2;
		if (argc % 2 == 0)
			j -= 1;
	}
	else
	{
		j = (double)index / 2;
		if (index % 2 == 0)
			j -= 1;
	}
	i = j;
	temp = stack;
	while (i)
	{
		temp = temp->next;
		i--;
	}
	median = temp->num;
	return (median);
}

int ft_intround(double n)
{
	double res;
	int num;

	if (n < 0)
		n = n * -1;
	num = n;
	res = n - num;
	res *= 2;
	if (res >= 1)
		return (n + 0.5);
	return (n);
}

int find_median_array(int *list, int index)
{
	int i;
	double j;
	double median;

	j = (double)index / 2;
	if (index % 2 == 0)
		j -= 1;
	i = j;
	median = list[i];
	print_array(list, index);
	return (median);
}

void insertion_sort(int *list, int argc, int *min, int *max)
{
	int i;
	int j;
	int temp;

	i = 1;
	while (i < argc)
	{
		temp = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > temp)
		{
			printf("this is elem 1:%i and elem2:%i\n", list[j + 1], list[j]);
			list[j + 1] = list[j];
			printf("this is elem %i\n", list[j + 1]);
			j--;
		}
		list[j + 1] = temp;
		printf("this is elem :%i\n", list[j + 1]);
		i++;
	}
	if (argc >= 3)
	{
		*min = list[argc - 3];
		*max = list[argc - 1];
	}
}

int *lst_cpy(t_stack *stack, int argc)
{
	t_stack *current;
	int *new_list;
	int i;
	int j;

	new_list = NULL;
	new_list = (int *)malloc(sizeof(int *) * (argc - 1));
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

void sort_threeb(t_stack **temp, t_format *stvar, int min, int max, int len)
{
	t_stack *stack;

	stack = *temp;
	if (stack->num == min)
	{
		if (stack->next->num == max)
		{
			rotate_b(&stack);
			push_b(&stack, &stvar->stack_a);
			push_b(&stack, &stvar->stack_a);
			rotate_revb(&stack);
			push_b(&stack, &stvar->stack_a);
			stvar->total_ins += 5;
		}
		else
		{
			rotate_b(&stack);
			rotate_b(&stack);
			push_b(&stack, &stvar->stack_a);
			rotate_revb(&stack);
			push_b(&stack, &stvar->stack_a);
			rotate_revb(&stack);
			push_b(&stack, &stvar->stack_a);
			stvar->total_ins += 7;
		}
	}
	else if (stack->num == max)
	{
		if (stack->next->num != min)
		{
			push_b(&stack, &stvar->stack_a);
			push_b(&stack, &stvar->stack_a);
			push_b(&stack, &stvar->stack_a);
			stvar->total_ins += 3;
		}
		else
		{
			push_b(&stack, &stvar->stack_a);
			swap_b(&stack);
			push_b(&stack, &stvar->stack_a);
			push_b(&stack, &stvar->stack_a);
			stvar->total_ins += 4;
		}
		print_stack_b(stack, 1);
	}
	else
	{
		if (stack->next->num == min)
		{
			swap_b(&stack);
			rotate_b(&stack);
			rotate_b(&stack);
			push_b(&stack, &stvar->stack_a);
			rotate_revb(&stack);
			push_b(&stack, &stvar->stack_a);
			rotate_revb(&stack);
			push_b(&stack, &stvar->stack_a);
			stvar->total_ins += 8;
		}
		else
		{
			swap_b(&stack);
			push_b(&stack, &stvar->stack_a);
			push_b(&stack, &stvar->stack_a);
			push_b(&stack, &stvar->stack_a);
			stvar->total_ins += 4;
		}
	}
	*temp = stack;
	stvar->sort_index += len;
	stvar->index += len;
}

void	sort_two(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->num < (*stack_b)->next->num)
		swap_b(stack_b);
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
}

void	sort_short(t_format *stvar, t_part **part_var)
{
	if ((*part_var)->len == 3)
		sort_threeb(&stvar->stack_b, stvar, (*part_var)->min, (*part_var)->max, (*part_var)->len);
	else if ((*part_var)->len == 2)
		sort_two(&stvar->stack_a, &stvar->stack_b);
	else
		push_b(&stvar->stack_a, &stvar->stack_b);
	*part_var = (*part_var)->next;
}

int run_pw(t_format *stvar)
{
	int *temp1;
	t_part *part_var;
	t_part *new;
	int len;
	int ret;
	int i;

	i = 0;
	ret = 0;
	part_var = (t_part *)ft_memalloc(sizeof(t_part *));
	ft_bzero(part_var, sizeof(t_part));
	if (!part_var)
		return (0);
	temp1 = lst_cpy(stvar->stack_a, stvar->argc);
	insertion_sort(temp1, stvar->argc, &stvar->min, &stvar->max);
	stvar->median = find_median_array(temp1, stvar->index);
	if (temp1)
		free(temp1);
	while (stvar->index > 3)
	{
		part_var->parts = ft_calloc(stvar->argc / (i + 1 * 2), sizeof(int));
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
		if (temp1)
			free(temp1);
		new = (t_part *)ft_memalloc(sizeof(t_part));
		if (part_var)
		{
			part_var->next = NULL;
			part_var->prev = new;
			new->next = part_var;
			part_var = new;
		}
		i++;
	}
	while (stvar->index != stvar->argc && part_var != NULL)
	{
		if (stvar->index == stvar->sort_index && part_var->len <= 3)
		{
			sort_short(stvar, &part_var);
		}
		else
		{
			insertion_sort(part_var->parts, part_var->len, &part_var->min, &part_var->max);
			stvar->median = find_median_array(part_var->parts, part_var->len);
			part_var->min = 0;
			part_var->max = 0;
			push_back(stvar, part_var, part_var->len);
		}
	}
	if (stvar->argc == 3)
		sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
	printf("total number of instructions:|%i|\n\n", stvar->total_ins);
	return (1);
}
