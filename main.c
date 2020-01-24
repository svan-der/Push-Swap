/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 16:18:16 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/24 17:41:01 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

t_stack		*create_stack(int num)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->num = num;
	stack->len = ft_numlen(num);
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

void	fill_stack(t_stack **stack_a, int num)
{
	t_stack *stack;
	t_stack *tail;

	stack = create_stack(num);
	stack->tail = *stack_a;
	tail = stack;
	if (*stack_a != NULL)
		printf("this is tail num: %i\n", stack->tail->num);
	if (*stack_a == NULL)
	{
		// stack->prev = NULL;
		*stack_a = stack;
		(*stack_a)->tail = stack;
		return ;
	}
	fill_stack_begin(&(*stack_a)->tail, num);
	while (stack->tail->next != NULL)
		stack->tail = stack->tail->next;
	stack->tail->next = stack;
	stack->prev = stack->tail;
}

int		print_stack(t_stack *stack_a, int ret)
{
	t_stack *tail;

	while (stack_a != NULL)
	{
		tail = stack_a;
		if (ret != -1)
			printf("|%d|\n", stack_a->num);
		// if (stack_a->next != NULL)
		// 	free(stack_a);
		stack_a = stack_a->next;
	}
	if (ret != -1)
	{
		printf(" --\n");
		printf(" A\n\n");
	}
	else
		printf("Error\n");
	// stack_a ? (stack_a = stack_a->next) : 0;
	return (1);
}

int		add_num(char *str, int i, int neg, t_format *stvar)
{
	int num;

	num = 0;
	i = (neg == -1) ? i - 1 : i;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	num *= neg;
	fill_stack(&stvar->stack_a, num);
	return (1);
}

int		check_num(char *str, t_format *stvar)
{
	int i;
	int neg;

	neg = 1;
	i = 0;
	while (ft_whitespace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
	{
		if (ft_isdigit(str[i + 1]) && (str[i] == '-' || str[i] == '+'))
		{
			if (str[i] == '-')
				neg = -1;
			i++;
		}
		else if (str[i] != '-' || str[i] != '+')
			return (-1);
	}
	if (ft_strnequ(&str[i], "214748364", 9))
		if ((str[i + 9] > '6' && neg != -1) || (str[i + 9] > '8' && neg == -1))
			return (-1);
	return (add_num(&str[i], i, neg, stvar));
}

void	debug(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack *temp1;

	temp = *stack_a;
	temp1 = *stack_b;
	// push_b(stvar->stack_a, stvar->stack_b);
	// push_a(stvar->stack_a, stvar->stack_b);
	fill_stack(stack_a, 10);
	// fill_stack(stack_a, 50);
	rotate_a(stack_a, &(*stack_a)->tail);
	rotate_a(stack_a, &(*stack_a)->tail);
	rotate_a(stack_a, &(*stack_a)->tail);
	rotate_a(stack_a, &(*stack_a)->tail);
	rotate_a(stack_a, &(*stack_a)->tail);
	rotate_a(stack_a, &(*stack_a)->tail);
	rotate_a(stack_a, &(*stack_a)->tail);
	rotate_a(stack_a, &(*stack_a)->tail);
	rotate_a(stack_a, &(*stack_a)->tail);
	rotate_a(stack_a, &(*stack_a)->tail);
	rotate_a(stack_a, &(*stack_a)->tail);
	// rotate_a(stack_a);
	// *stack_a = temp;
	print_stack(*stack_a, 1);
}

int		main(int argc, char **argv)
{
	t_format	stvar;
	char		*str;
	int			ret;
	int			i;

	i = 1;
	ft_bzero(&stvar, sizeof(t_format));
	stvar.argc = argc;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		str = argv[i];
		ret = check_num(str, &stvar);
		if (ret == -1)
			return (print_stack(stvar.stack_a, ret));
		i++;
	}
	// debug(&stvar.stack_a, &stvar.stack_b);
	// print_stack(stvar.stack_a, 1);
	get_instruction(&stvar);
	return (1);
}
