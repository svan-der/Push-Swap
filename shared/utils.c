/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/15 17:08:28 by svan-der      ########   odam.nl         */
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
	(void)ret;
	ft_putstr_fd("error\n", 2);
	// if (ret == 1)
	// 	return (exit())
	return (1);
}

int		check_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	int		valid;

	temp = *stack_a;
	valid = 1;
	print_stack(stack_a, 1);
	// ft_printf("inside check sorted\n\n");
	if (stack_b != NULL)
	{
		valid = 0;
		ft_printf("not valid\n");
	}
	while (temp != NULL && temp->next != NULL)
	{
		if ((temp->num) > (temp->next->num))
		{
			ft_printf("num is:%d\n", temp->num);
			valid = 0;
			ft_printf("not valid\n");
		}
		temp = temp->next;
	}
	if (valid == 0)
		ft_printf("KO\n");
	else
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
