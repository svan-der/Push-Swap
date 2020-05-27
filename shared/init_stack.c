/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:12:42 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/27 16:48:29 by svan-der      ########   odam.nl         */
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
	stack->dist = 0;
	stack->num = num;
	stack->next = NULL;
	stack->prev = NULL;
	stack->tail = NULL;
	return (stack);
}

t_stack		*ft_addtail(t_stack **tail, t_stack *new)
{
	t_stack *temp;

	temp = *tail;
	while (temp->next != NULL)
        temp = temp->next;
	ft_printf("temp->num:%d\n", temp->num);
    temp = new;
	*tail = temp;
	return (*tail);
    // temp->prev = temp->tail;
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
		// (*stack)->tail = new;
		// ft_printf("stack->tail:%d\n", (*stack)->tail->num);
		return (1);
	}
	ft_stackaddend(stack, new);
	// (*stack)->tail = ft_addtail(&(*stack)->tail, new);
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

int			add_num(char *str, int sign, t_pw_var *stvar)
{
	long long int	num;
	int				ret;
	int				i;

	num = 0;
	i = 0;
	if (!ft_isdigit(str[i]))
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	num *= sign;
	if (num > 2147483647 || num < -2147483648)
		return (-1);
	ret = stack_addnew(&(stvar)->stack_a, num);
	return (ret);
}

int			check_argv(char *str, t_pw_var *stvar)
{
	int i;
	int sign;

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
	return (add_num(str, sign, stvar));
}
