/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer_opts.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:49:34 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/12 18:06:03 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "psw_env.h"
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
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = temp;
		i++;
	}
	if (argc >= 3)
	{
		*min = list[argc - 3];
		*max = list[argc - 1];
	}
	print_array(list, argc);
}

void	part_sort(t_format *stvar, int argc)
{
	char low;
	int j;

	j = 0;
	if (stvar->stack_a == NULL)
		return ;
	while (j < argc)
	{
		j++;
		if ((*stvar->stack_a->num) < stvar->median)
			dispatch_sort(stvar, PB, 1);
		else
		{
			if ((*stvar->stack_a->num) == stvar->min)
				low = 1;
			dispatch_sort(stvar, RA, 1);
		}
		if (low && stvar->index == 3)
			break ;
	}
}

void	do_op(t_format *stvar, char *str, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		dispatch_sort(stvar, str, 1);
		i++;
	}
}

void sort_three_part(t_stack **temp, t_format *stvar, int min, int max)
{
	t_stack *stack;

	stack = *temp;
	if ((*stack->num) == min)
	{
		
	}
	else if ((*stack->num) == max)
	{
		if ((*stack->next->num) != min)
			do_op(stvar, PB, 3);
		else
		{
			dispatch_sort(stvar, PB, 1);
			dispatch_sort(stvar, SB, 1);
			do_op(stvar, PB, 2);
		}
	}
	else
	{
		if ((*stack->next->num) == min)
		{
			dispatch_sort(stvar, SB, 1);
			do_op(stvar, RB, 2);
			dispatch_sort(stvar, PB, 1);
			dispatch_sort(stvar, RRB, 1);
			dispatch_sort(stvar, PB, 1);
			dispatch_sort(stvar, RRB, 1);
			dispatch_sort(stvar, PB, 1);
		}
		else
		{
			dispatch_sort(stvar, SB, 1);
			dispatch_sort(stvar, PB, 3);
		}
	}
}

void	sort_two(t_stack **stack_a, t_stack **stack_b, t_format *stvar)
{
	(void)stack_a;
	if ((*(*stack_b)->num) < (*(*stack_b)->next->num))
		dispatch_sort(stvar, SB, 1);
	do_op(stvar, PA, 2);
}

void	sort_short(t_format *stvar, char c, int stack_len)
{
	t_stack *stack;

	if (c == 'a')
		stack = stvar->stack_a;
	else
		stack = stvar->stack_b;
	if ((stvar->argc - stvar->index == 3))
		sort_three_part(&stack, stvar, stvar->min, stvar->max);
	else if (stack_len == 2)
		sort_two(&stvar->stack_a, &stvar->stack_b, stvar);
	else
		dispatch_sort(stvar, PA, 1);
}

int		sort_three(t_stack **temp, t_format *stvar, int min, int max)
{
	t_stack *stack;

	stack = *temp;
	if ((*stack->num) == min && (*stack->next->num) != max)
		return (dispatch_sort(stvar, NULL, 0));
	if ((*stack->num) == min && (*stack->next->num) == max)
		return (dispatch_sort(stvar, RRA, 1) && dispatch_sort(stvar, SA, 1));
	if ((*stack->num) == max && (*stack->next->num) == min)
		return (dispatch_sort(stvar, RA, 1));
	if ((*stack->num) == max && (*stack->next->num) != min)
		return (dispatch_sort(stvar, SA, 1) && dispatch_sort(stvar, RRA, 1));
	if ((*stack->next->num) == max)
		return (dispatch_sort(stvar, RRA, 1));
	if ((*stack->next->num) == min)
		return (dispatch_sort(stvar, SA, 1));
	printf("three are now sorted!!!\n\n");
	return (0);
}
