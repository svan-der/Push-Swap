/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/29 16:32:40 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include "psw_env.h"

void	content_delete(int *content, size_t size)
{
	if (content)
		free(content);
	(void)size;
}

int		error_handler(int ret)
{
	if (ret == 0)
		ft_putstr_fd("Invalid argument\n", 2);
	if (ret == 1)
		ft_putstr_fd("Failed to allocate memory\n", 2);
	if (ret == 2)
		ft_putstr_fd("Error\n", 2);
	return (1);
}

int		check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	printf("inside check sorted\n\n");
	if (stack_b != NULL)
	{
		printf("KO\n");
		return (-1);
	}
	while (stack_a != NULL && stack_a->next != NULL)
	{
		if ((*stack_a->num) > (*stack_a->next->num))
		{
			printf("KO\n");
			return (-1);
		}
		stack_a = stack_a->next;
	}
	printf("OK\n");
	return (1);
}

void	fill_stack_begin(t_stack **head, t_stack *new)
{
	if (*head != NULL)
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	else
	{
		*head = new;
		(*head)->prev = NULL;
	}
}
