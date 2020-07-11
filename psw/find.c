/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 17:07:02 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/11 17:24:15 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_max(t_stack *current, int max, int *j)
{
	ft_printf("BIGGER THAN MAX\n");
	while (current && current->num != max)
	{
		*j += 1;
		ft_printf("j is:%i\n", *j);
		current = current->next;
	}
}

void	find_min(t_stack *current, int min, int *j)
{
	ft_printf("SMALLER THAN MIN\n");
	while (current && current->num != min)
	{
		*j += 1;
		ft_printf("j is:%i\n", *j);
		current = current->next;
	}
}

char	*find_pos(t_pw_var *stvar, t_stack *current, t_stack *temp, int *j)
{
	char *instr;

	instr = NULL;
	while (temp && temp->next)
	{
		if (temp->num > current->num && temp->next->num < current->num)
		{
			instr = fastest_rotate(stvar, 'b', ((stvar->argc - stvar->index) - *j));
			ft_printf(YEL"INSL:%s J:%i\n"RESET, instr, *j);
			return (instr);
		}
		*j += 1;
		temp = temp->next;
	}
	return (instr);
}

void	find_dist_top(t_stack *stack, int num)
{
	t_stack *temp;
	int		j;

	temp = stack;
	j = 0;
	while (temp)
	{
		if (temp->num == num)
		{
			temp->dist_top = j;
			// ft_printf("dist_top:%i\n", temp->dist_top);
			return ;
		}
		temp = temp->next;
		j++;
	}
}

void	find_distance(t_stack *stack, int num, int *sorted)
{
	t_stack *temp;
	int i;
	int j;

	temp = stack;
	i = 0;
	j = 0;
	while (temp != NULL && temp->num != num)
	{
		temp = temp->next;
		j++;
	}
	// ft_printf(YEL"temp->dist_top:%i\n"RESET, temp->dist_top);
	while (sorted[i] != num)
		i++;
	temp->dist = j - i;
	temp->dist_top = j;
	// ft_printf(CYN"|num:%i\tdist:%i\n|"RESET, temp->num, dist);
	stack = temp;
}

char	*find_low(t_pw_var *stvar, char c, int *index)
{
	t_stack	*current;
	int		dist_top;

	current = (c == 'a') ? stvar->stack_a : stvar->stack_b;
	dist_top = 0;
	while (current)
	{
		if (current->index == *index)
			break ;
		dist_top++;
		current = current->next;
	}
	if (dist_top == 0)
	{
		*index = ((c == 'a')) ? *index + 1 : *index - 1;
		return ((c == 'a') ? PB : PA);
	}
	else
	{
		if (dist_top == 1)
			return (c == 'a' ? SA : SB);
		return (fastest_rotate(stvar, c, dist_top));
	}
}
