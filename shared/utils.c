/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/05 23:10:21 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/checker.h"
#include "../includes/psw_env.h"

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
	t_stack *temp;

	temp = stack_a;
	printf("inside check sorted\n\n");
	if (stack_b != NULL)
	{
		printf("KO\n");
		return (-1);
	}
	while (temp != NULL && temp->next != NULL)
	{
		if ((temp->num) > (temp->next->num))
		{
			printf("KO\n");
			return (-1);
		}
		temp = temp->next;
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
