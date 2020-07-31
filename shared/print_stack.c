/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:33:59 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/29 17:25:04 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

int		print_stack(t_stack **stack_a, int ret)
{
	t_stack *temp;
	t_stack	*next;

	temp = *stack_a;
	while (temp != NULL)
	{
		next = temp->next;
		if (ret != -1)
			ft_printf("|%d|\n", temp->num);
		temp = next;
	}
	if (ret != -1)
	{
		ft_printf(" --\n");
		ft_printf(" A\n\n");
	}
	return (1);
}

int		print_stack_b(t_stack **stack_b, int ret)
{
	t_stack *temp;
	t_stack *next;

	temp = *stack_b;
	while (temp != NULL)
	{
		next = temp->next;
		if (ret != -1)
			ft_printf("|%d|\n", temp->num);
		temp = next;
	}
	if (ret != -1)
	{
		ft_printf(" --\n");
		ft_printf(" B\n");
	}
	return (1);
}
