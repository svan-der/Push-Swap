/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:33:59 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/13 18:07:04 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

int		print_stack(t_stack *stack_a, int ret)
{
	// t_stack *tail;

	while (stack_a != NULL)
	{
		// tail = stack_a;
		if (ret != -1)
		{
			// printf("|this is tail : %d|\n", (*tail->num));
			ft_printf("|%d|\n", (stack_a->num));
		}
		stack_a = stack_a->next;
	}
	if (ret != -1)
	{
		ft_printf(" --\n");
		ft_printf(" A\n\n");
	}
	else
		ft_printf("Error\n");
	return (1);
}

int		print_stack_b(t_stack *stack_b, int ret)
{
	// t_stack *tail;

	while (stack_b != NULL)
	{
		// tail = stack_b;
		if (ret != -1)
			ft_printf("|%d|\n", (stack_b->num));
		stack_b = stack_b->next;
	}
	if (ret != -1)
	{
		ft_printf(" --\n");
		ft_printf(" B\n");
	}
	else
		ft_printf("Error\n");
	return (1);
}
