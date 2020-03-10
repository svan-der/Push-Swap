/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer_opts.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:49:34 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/10 15:11:20 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
			// printf("this is elem 1:%i and elem2:%i\n", list[j + 1], list[j]);
			list[j + 1] = list[j];
			// printf("this is elem %i\n", list[j + 1]);
			j--;
		}
		list[j + 1] = temp;
		// printf("this is elem :%i\n", list[j + 1]);
		i++;
	}
	if (argc >= 3)
	{
		*min = list[argc - 3];
		*max = list[argc - 1];
	}
	print_array(list, argc);
}

int *part_sort(t_format *stvar, int *list, int argc)
{
	char low;
	int j;
	int i;

	i = 0;
	j = 0;
	if (stvar->stack_a == NULL)
		return (NULL);
	while (j < argc)
	{
		j++;
		if ((*stvar->stack_a->num) < stvar->median)
		{
			list[i] = (*stvar->stack_a->num);
			ft_putstr("pb\n");
			push_b(&stvar->stack_a, &stvar->stack_b);
			stvar->index -= 1;
			i++;
		}
		else
		{
			if ((*stvar->stack_a->num) == stvar->min)
				low = 1;
			rotate_a(&stvar->stack_a);
		}
		if (low && stvar->index == 3)
			break ;
		stvar->total_ins += 1;
	}
	return (list);
}

void sort_threeb(t_stack **temp, t_format *stvar, int min, int max, int len)
{
	t_stack *stack;

	stack = *temp;
	if ((*stack->num) == min)
	{
		if ((*stack->next->num) == max)
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
	else if ((*stack->num) == max)
	{
		if ((*stack->next->num) != min)
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
		if ((*stack->next->num) == min)
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

void	sort_two(t_stack **stack_a, t_stack **stack_b, t_format *stvar)
{
	if ((*(*stack_b)->num) < (*(*stack_b)->next->num))
	{
		swap_b(stack_b);
		stvar->total_ins += 1;
	}
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	stvar->total_ins += 2;
	stvar->sort_index += 2;
	stvar->index += 2;
}

void	sort_short(t_format *stvar, t_part **part_var)
{
	if ((*part_var)->len == 3)
		sort_threeb(&stvar->stack_b, stvar, (*part_var)->min, (*part_var)->max, (*part_var)->len);
	else if ((*part_var)->len == 2)
		sort_two(&stvar->stack_a, &stvar->stack_b, stvar);
	else
	{
		push_a(&stvar->stack_a, &stvar->stack_b);
		stvar->total_ins += 1;
		stvar->sort_index += 1;
		stvar->index += 1;
	}
}

void sort_three(t_stack **temp, t_format *stvar, int min, int max)
{
	t_stack *stack;

	stack = *temp;
	stvar->sort_index += 3;
	if ((*stack->num) == min)
	{
		print_stack(stack, 1);
		if ((*stack->next->num) != max)
			return ;
		else if ((*stack->next->num) == max)
		{
			stvar->total_ins += 2;
			rotate_reva(&stack);
			swap_a(&stack);
		}
		print_stack(stack, 1);
	}
	else if ((*stack->num) == max)
	{
		if ((*stack->next->num) == min)
		{
			stvar->total_ins += 1;
			rotate_a(&stack);
		}
		else
		{
			stvar->total_ins += 2;
			swap_a(&stack);
			rotate_reva(&stack);
		}
	}
	else
	{
		if ((*stack->next->num) == max)
		{
			rotate_revb(&stack);
		}
		else if ((*stack->next->num) == min)
			swap_b(&stack);
		stvar->total_ins += 1;
	}
	*temp = stack;
	printf("three are now sorted!!!\n\n");
}

