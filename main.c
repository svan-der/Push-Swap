/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 16:18:16 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/10 12:15:10 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				temp;

	i = 0;
	j = 0;
	while (i < (size - 1))
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j += 1;
		}
		i += 1;
	}
}

t_stack		*create_stack(int num)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->num = num;
	stack->len = ft_numlen(num);
	stack->next = NULL;
	return (stack);
}

void	fill_stack(t_stack **stack_a, int num)
{
	t_stack *stack;
	t_stack *tail;

	tail = *stack_a;
	stack = create_stack(num);
	if (*stack_a == NULL)
	{
		stack->prev = NULL;
		*stack_a = stack;
		return ;
	}
	else
		while (tail->next != NULL)
			tail = tail->next;
	tail->next = stack;
	stack->prev = tail;
	return ;
}

void 	print_stack(t_stack *stack)
{
	t_stack *tail;

	while (stack != NULL)
	{
		tail = stack;
		printf("|%d|\n", stack->num);
		stack = stack->next;
	}
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
	if (ft_strnequ(str, "214748364", 9))
		if ((str[i + 9] > '6' && !neg) || (str[i + 9] > '8' && neg))
			return (0);
	return (add_num(&str[i], i, neg, stvar));
}

int		main(int argc, char **argv)
{

	t_format	stvar;
	char 		*str;
	int 		ret;
	int 		i;
	
	i = 1;
	ft_bzero(&stvar, sizeof(t_format));
	stvar.argc = argc;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		str = argv[i];
		ret = check_num(str, &stvar);
		if (ret == 0)
			return (0);
		i++;
	}
	print_stack(stvar.stack_a);
	return (1);
}
