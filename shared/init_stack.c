/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:12:42 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/28 06:25:26 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
// #include "../includes/psw_env.h"
#include "../includes/push_swap.h"

t_stack		*create_stack(int num)
{
	t_stack *stack;

	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->dist = 0;
	stack->dist_top = 0;
	stack->num = num;
	stack->next = NULL;
	stack->prev = NULL;
	stack->tail = NULL;
	return (stack);
}

int			stack_addnew(t_stack **stack, int num)
{
	t_stack *new;

	new = create_stack(num);
	if (new == NULL)
		return (0);
	if (*stack == NULL)
	{
		*stack = new;
		(new)->prev = NULL;
		(new)->tail = new;
		(new)->tail->next = NULL;
		return (1);
	}
	// ft_printf("new\n");
	// ft_printf("num is:%i\n", num);
	ft_stackaddend(stack, new);
	add_tail(stack);
	return (1);
}

int			check_dup(t_stack **stack_a)
{
	t_stack		*fast;
	t_stack		*slow;

	fast = *stack_a;
	slow = *stack_a;
	if (stack_a == NULL)
		return (-1);
	while (slow && slow->next)
	{
		while (fast->next != NULL)
		{
			// ft_printf("slow->num:%d fast->next->num:%d\n", slow->num, fast->next->num);
			if (slow->num == fast->next->num)
				return (-1);
			else
				fast = fast->next;
		}
		slow = slow->next;
		fast = slow;
	}
	return (1);
}

int			add_num(char *str, t_llong sign, t_pw_var *stvar)
{
	t_llong			num;
	int				j;
	int				ret;
	int				i;

	num = 0;
	i = 0;
	j = 0;
	while (!ft_isdigit(str[i]) || str[i] == '0')
	{
		if (str[i] == '0')
			j++;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		// ft_printf("num:%lld\n", num);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	// ft_printf("i:%i j:%i\n", i, j);
	i -= j;
	// ft_printf("num after is:%lld i:%i\n", num, i);
	num *= sign;
	if (num > 2147483647 || num < -2147483648 || i > 11)
		return (-1);
	ret = stack_addnew(&(stvar)->stack_a, num);
	// ft_printf("ret is:%i\n", ret);
	return (ret);
}

int			check_argv(char *str, t_pw_var *stvar)
{
	int i;
	t_llong sign;

	sign = 1;
	i = 0;
	while (ft_whitespace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	// ft_printf("sign:%lld\n", sign);
	return (add_num(str, sign, stvar));
}
