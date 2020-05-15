/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/15 12:24:57 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	(void)ret;
	ft_putstr_fd("Invalid argument\n", 2);
	// if (ret == -1)
	return (1);
}

// int		error_handler(int ret)
// {
// 	if (ret == 0)
// 	{
// 		ft_putstr_fd("Invalid argument\n", 2);
// 		return (0);
// 	}
// 	if (ret == 1)
// 	{
// 		ft_putstr_fd("Failed to allocate memory\n", 2);
// 		return (1);
// 	}
// 	if (ret == 2)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		return (2);
// 	}
// 	return (1);
// }

int		check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *temp;

	temp = stack_a;
	// ft_printf("inside check sorted\n\n");
	if (stack_b != NULL)
	{
		ft_printf("KO\n");
		return (-1);
	}
	while (temp != NULL && temp->next != NULL)
	{
		if ((temp->num) > (temp->next->num))
		{
			ft_printf("KO\n");
			return (-1);
		}
		temp = temp->next;
	}
	ft_printf("OK\n");
	return (1);
}

t_stack	*fill_stack_begin(t_stack **head, t_stack *new)
{
	t_stack *temp;
	t_stack *new_node;

	temp = *head;
	new_node = new;
	if (*head != NULL)
	{
		new_node->next = temp;
		temp->prev = new_node;
		temp = new_node;
		return (temp);
	}
	else
	{
		temp = new_node;
		temp->prev = NULL;
		return (temp);
	}
}
