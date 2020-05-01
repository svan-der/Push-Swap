/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
<<<<<<< HEAD
/*   Created: 2020/02/06 14:12:42 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 17:44:28 by svan-der      ########   odam.nl         */
=======
/*   Created: 2020/02/06 14:12:42 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/09 18:12:59 by svan-der      ########   odam.nl         */
>>>>>>> parent of eb144b2... Modified Makefile and add README file
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

t_stack		*create_stack(int num)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->len = ft_numlen(num);
	stack->num = (int *)ft_memdup(&num, stack->len);
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

int	stack_addnew(t_stack **stack, int num)
{
	t_stack *new;

	new = create_stack(num);
	if (!new)
		return (0);
	if (*stack == NULL)
	{
		*stack = new;
		(*stack)->prev = NULL;
		return (1);
	}
	if (*stack != NULL)
		fill_stack_begin(stack, new);
	return (1);
}

<<<<<<< HEAD
int			add_num(char *str, int i, int neg, t_pw_var *stvar)
=======
int		add_num(char *str, int i, int neg, t_format *stvar)
>>>>>>> parent of eb144b2... Modified Makefile and add README file
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
	stack_addnew(&stvar->stack_a, num);
	return (1);
}

<<<<<<< HEAD
int			check_argv(char *str, t_pw_var *stvar)
=======
int		check_argv(char *str, t_format *stvar)
>>>>>>> parent of eb144b2... Modified Makefile and add README file
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
