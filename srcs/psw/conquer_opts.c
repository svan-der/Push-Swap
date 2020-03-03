/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer_opts.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:49:34 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/03 18:31:06 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		*min = list[0];
		*max = list[argc - 1];
	}
	print_array(list, argc);
}

void	part_sort(t_format *stvar, t_part *part_var, int argc)
{
	t_stack *temp;
	char low;
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
		j++;
		num = temp->num;
		if (num == stvar->min)
			low = 1;
		if (num < stvar->median && num)
		{
			part_var->parts[i] = temp->num;
			ft_putstr("pb\n");
			push_b(&temp, &stvar->stack_b);
			if (stvar->stack_b->next == NULL)
				stvar->stack_b->prev == NULL;
			stvar->index -= 1;
			i++;
			part_var->len = i;
		}
		else
		{
			rotate_a(&temp);
			// if (temp->next->num < temp->num)
			// 	swap_a(&temp);
			// else
			// 	rotate_reva(&temp);
		}
		if (low && stvar->index == 3)
			break ;
			// rotate_a(&temp);
		// else
		// {
		// 	if (temp)
		// 		rotate_a(&temp);
		// 	if (temp->next->num < temp->num)
		// 		swap_a(&temp);
		// }
		stvar->total_ins += 1;
	}
	stvar->stack_a = temp;
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

void	sort_two(t_stack **stack_a, t_stack **stack_b, t_format *stvar)
{
	if ((*stack_b)->num < (*stack_b)->next->num)
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
	*part_var = (*part_var)->next;
}

void sort_three(t_stack **temp, t_format *stvar, int min, int max)
{
	t_stack *stack;

	stack = *temp;
	stvar->sort_index += 3;
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
}

