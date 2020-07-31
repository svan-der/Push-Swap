/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:16:23 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"

void	ft_exit(t_pw_var *stvar, int ret)
{
	if (ret == 1)
		ft_putstr_fd("OK\n", 1);
	free_inst_list(&(stvar)->inst_lst);
	free_stack_list(&(stvar)->stack_a, &(stvar)->stack_b);
	exit(0);
}

void	error_handling(t_pw_var *stvar, char *line, int ret)
{
	if (line != NULL)
		ft_strdel(&line);
	if (ret == -1)
		ft_putstr_fd("Error\n", 2);
	if (ret == 0)
		ft_putstr_fd("KO\n", 1);
	ft_exit(stvar, 0);
}

int		check_dup(t_stack **stack_a)
{
	t_stack *fast;
	t_stack *slow;

	fast = *stack_a;
	slow = *stack_a;
	if (stack_a == NULL)
		return (-1);
	while (slow && slow->next)
	{
		while (fast->next != NULL)
		{
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

int		add_num(char *str, t_llong sign, t_pw_var *stvar)
{
	t_llong num;
	int		j;
	int		i;

	num = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0' && (!ft_isdigit(str[i]) || str[i] == '0'))
	{
		if (str[i] == '0')
			j++;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	i -= j;
	num *= sign;
	if (num > 2147483647 || num < -2147483648 || i > 11)
		return (-1);
	return (stack_addnew(&(stvar)->stack_a, num));
}

int		check_argv(char *str, t_pw_var *stvar)
{
	int		i;
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
			error_handling(stvar, NULL, -1);
		i++;
	}
	i = add_num(str, sign, stvar);
	if (i == -1)
		error_handling(stvar, NULL, i);
	return (1);
}
