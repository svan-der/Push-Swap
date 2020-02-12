/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:52:42 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/12 14:59:24 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "psw_env.h"
#include <stdio.h>

void	pre_sort(t_stack *stack_a, t_format *stvar)
{
	t_stack *temp;
	int		median;
	int		num;
	int		i;

	i = 1;
	temp = stack_a;
	median = stvar->median;
	if (stack_a == NULL)
		return ;
	num = stack_a->num;
	if (num < median && num)
	{
		push_b(&temp, &stvar->stack_b);
		temp->prev = stack_a->prev;
		temp->prev->next = temp;
		stack_a = temp;
		stvar->index -= 1;
		if (temp != NULL)
			pre_sort(stack_a, stvar);
	}
	else
	{
		if (temp != NULL)
			pre_sort(stack_a->next, stvar);
	}
}

int		split_stack(t_stack *stack_a, int argc)
{
	int 	i;
	double	j;
	int		num;
	double 	median;
	t_stack *temp;

	num = 0;
	i = 0;
	j = (argc / 2);
	if (argc % 2 == 0)
		j -= 1;
	temp = stack_a;
	printf("this is median:|%i|\n", j);
	while (i < j)
	{
		temp = temp->next;
		i++;
	}
	median = temp->num;
	if (argc % 2 == 0)
	{
		temp = temp->next;
		num = temp->num;
		median = ((median + num) / 2);
		printf("this is median: %f", median);
	}
	return (median);
}

int		run_pw(t_format *stvar)
{
	char	*line;
	int		ret;
	t_inst	inst;
	int		i;

	i = 0;
	ft_bzero(&inst, sizeof(t_inst));
	ret = split_stack(stvar->stack_a, stvar->argc);
	stvar->median = ret;
	pre_sort(stvar->stack_a, stvar);
	print_instructions(stvar->inst_lst, ret);
	print_stack(stvar->stack_a, 1);
	print_stack_b(stvar->stack_b, 1);
	ret = check_sorted(stvar->stack_a, stvar->stack_b);
	printf("This is ret after check_sorted:%d\n", ret);
	return (1);
}
