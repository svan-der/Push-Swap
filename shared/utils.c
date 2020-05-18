/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/18 10:10:05 by svan-der      ########   odam.nl         */
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

int		ft_exit(t_pw_var *stvar)
{
	free_inst_list(&(stvar)->inst_lst);
	free_stack_list(&(stvar)->stack_a, &(stvar)->stack_b);
	return (1);
}

int		error_handler(int ret)
{
	if (ret == -1)
		ft_putstr_fd("Error\n", 2);
	if (ret == 0)
		ft_putstr_fd("KO\n", 2);
	return (1);
}

int		check_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	int		sign;
	int		valid;

	temp = *stack_a;
	valid = 1;
	// print_stack(stack_a, 1);
	if (*stack_b != NULL)
		valid = 0;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->num > temp->next->num)
		{
			// ft_printf("num is:%d\n", temp->num);
			valid = 0;
			// ft_printf("not valid\n");
		}
		temp = temp->next;
	}
	if (valid == 0)
	{
		// ft_printf("KO\n");
		return (0);
	}
	else
	{
		// ft_printf("OK\n");
		return (1);
	}
}

void	ft_stackaddend(t_stack **stack_lst, t_stack *new)
{
	t_stack	*temp;

	if (*stack_lst == NULL)
	{
		(*stack_lst)->prev = NULL;
		*stack_lst = new;
		return ;
	}
	temp = *stack_lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	temp->next->prev = temp;
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
