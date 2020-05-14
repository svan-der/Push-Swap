/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:12:42 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/14 15:46:37 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

t_stack		*create_stack(int num)
{
	t_stack *stack;

	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->len = ft_numlen(num);
	stack->num = num;
	if (!stack->num)
		return (NULL);
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

int			stack_addnew(t_stack **stack, int num)
{
	t_stack *new;
	t_stack *temp;

	new = create_stack(num);
	ft_printf("size of new_node:%ld\n\n", sizeof(new));
	if (new == NULL)
		return (0);
	if (*stack == NULL)
	{
		*stack = new;
		(new)->prev = NULL;
		ft_printf("addres *stack:%p\n\n", *stack);
		return (1);
	}
	// temp = *stack;
	ft_printf("going in fill_stack\n\n");
	temp = fill_stack_begin(stack, new);
	(void)temp;
	// *stack = temp;
	return (1);
}

int			add_num(char *str, int i, int neg, t_stack *stack_a)
{
	int num;
	int ret;

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
	ret = stack_addnew(&stack_a, num);
	ft_printf("stack_a address:%p\n\n", stack_a);
	return (ret);
}

int			check_argv(char *str, t_pw_var *stvar)
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
	return (add_num(&str[i], i, neg, stvar->stack_a));
}
