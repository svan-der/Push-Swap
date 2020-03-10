/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:35:59 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/10 14:56:33 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_format *stvar, t_part *part_var, int argc, int sum)
{
	char low;
	int j;
	int i;

	i = 0;
	j = 0;
	if (stvar->stack_b == NULL)
		return ;
	while (j < argc)
	{
		j++;
		if ((*stvar->stack_b->num) > stvar->median)
		{
			part_var->parts[i] = (*stvar->stack_b->num);
			ft_putstr("pa\n");
			push_a(&stvar->stack_b, &stvar->stack_a);
			part_var->len = i;
			stvar->index += 1;
			sum -= 1;
		}
		else
		{
			if ((*stvar->stack_b->num) == part_var->min)
				low = 1;
			part_var->parts[i] = (*stvar->stack_b->num);
			i++;
			part_var->len = i;
			rotate_b(&stvar->stack_b);
		}
		if (sum == 0)
			break ;
		if (low && i == 3)
			break ;
		stvar->total_ins += 1;
	}
}

void    ft_stackdelone(t_stack **alst, void (*del)(int *, size_t))
{
    if (alst)
    {
        del((*alst)->num, (*alst)->len);
     }
	(void)((*alst)->len);
	free(*alst);
    *alst = NULL;
}

void	ft_stackdel(t_stack **stack_lst, void (*del)(int *, size_t))
{
	t_stack *temp;

	if (!stack_lst)
		return ;
	temp = (*stack_lst)->next;
	ft_stackdelone(stack_lst, del);
	if (temp)
		ft_stackdel(&temp, del);
}

void	ft_stackpop(t_stack **aparent, t_stack *elem)
{
	t_stack *next;

	if (aparent && elem)
	{
		next = (*aparent)->next;
		if (*aparent == elem)
		{
			ft_stackdelone(aparent, content_delete);
			*aparent = next;
			if (*aparent && (*aparent)->next != NULL)
				(*aparent)->prev = NULL;
		}
		else
			ft_stackpop(&(*aparent)->next, elem);
	}
}

void	push_short(t_format *stvar, t_part *part_var)
{
	t_ull size;

	size = (t_ull)(part_var->len / 2);
	insertion_sort(part_var->parts, part_var->len, &part_var->min, &part_var->max);
	stvar->median = find_median_array(part_var->parts, part_var->len);
	push_back(stvar, part_var, part_var->len, ft_min_size((part_var->len / 2), 3));
	set_min_max(part_var);
}

void	push_half(t_format *stvar, t_part *part_var)
{
	insertion_sort(part_var->parts, part_var->len, &part_var->min, &part_var->max);
	stvar->median = find_median_array(part_var->parts, part_var->len);
	push_back(stvar, part_var, ft_min_size(part_var->len, 6), (part_var->len / 2));
	set_min_max(part_var);
}

int		conquer_list(t_format *stvar, t_part *part_var)
{
	while (stvar->index != stvar->argc)
	{
		if (part_var->next == NULL && part_var->len > 3)
			push_half(stvar, part_var);
		else if (stvar->index == stvar->sort_index && part_var->len <= 3)
		{
			sort_short(stvar, &part_var);
			// ft_stackpop(&part_var, part_var);
			part_var = part_var->next;
		}
		else
			push_short(stvar, part_var);
	}
	return (1);
}
