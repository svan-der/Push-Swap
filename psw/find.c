/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 17:07:02 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/30 12:41:01 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_max(t_stack *current, int max, int *j)
{
	// ft_printf("BIGGER THAN MAX\n");
	while (current && current->num != max)
	{
		*j += 1;
	// ft_printf("current num:%i max:%i\n", current->num, max);
		// ft_printf("j is:%i\n", *j);
		current = current->next;
	}
}

void	find_min(t_stack *current, int min, int *j)
{
	// ft_printf("SMALLER THAN MIN\n");
	// *j = 1;
	while (current && current->num != min)
	{
		*j += 1;
		// ft_printf("j is:%i\n", *j);
		current = current->next;
	}
}

char	*find_pos(t_pw_var *stvar, t_stack *current, t_stack *temp, int *j)
{
	char *instr;

	instr = NULL;
	// ft_printf("FIND POSITION\n");
	// ft_printf("j is:%i\n", *j);
	*j = 1;
	while (temp && temp->next)
	{
		if (temp->num > current->num && temp->next->num < current->num)
		{
			if (*j == 1)
				return (SB);
			instr = fastest_rotate(stvar, 'b', j);
			// ft_printf(YEL"INSL:%s index:%i j:%i\n"RESET, instr, ((stvar->argc - stvar->index) - *j), *j);
			return (instr);
		}
		*j += 1;
		temp = temp->next;
	}
	*j = 0;
	return (instr);
}

t_stack		*find_high(t_pw_var *stvar, char c, int *index)
{
	t_stack	*current;
	int		dist_top;

	current = (c == 'a') ? stvar->stack_a : stvar->stack_b;
	dist_top = 0;
	while (current)
	{
		if (current->index == *index)
			return (current);
		dist_top++;
		current = current->next;
	}
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
		return (fastest_rotate(stvar, c, &dist_top));
	}
}
