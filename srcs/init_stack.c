/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:12:42 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/12 17:27:38 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "psw_env.h"

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

	stack = create_stack(num);
	if (*stack_a == NULL)
	{
		stack->prev = NULL;
		*stack_a = stack;
		return ;
	}
	fill_stack_begin(stack_a, num);
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

int		check_argv(char *str, t_format *stvar)
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
