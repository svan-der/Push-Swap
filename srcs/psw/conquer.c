/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:35:59 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/12 18:02:01 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_format *stvar, t_part *part_var)
{
	(void)part_var;
	if (stvar->stack_b == NULL)
		return ;
	while (stvar->argc - stvar->index > 3)
	{
        if ((*stvar->stack_b->num) > stvar->median)
            dispatch_sort(stvar, PA, 1);
		else
            dispatch_sort(stvar, RB, 1);
	}
}

// void    ft_stackdelone(t_stack **alst, void (*del)(int *, size_t))
// {
//     if (alst)
//     {
//         del((*alst)->num, (*alst)->len);
//      }
// 	(void)((*alst)->len);
// 	free(*alst);
//     *alst = NULL;
// }

// void	ft_stackdel(t_stack **stack_lst, void (*del)(int *, size_t))
// {
// 	t_stack *temp;

// 	if (!stack_lst)
// 		return ;
// 	temp = (*stack_lst)->next;
// 	ft_stackdelone(stack_lst, del);
// 	if (temp)
// 		ft_stackdel(&temp, del);
// }

// void	ft_stackpop(t_stack **aparent, t_stack *elem)
// {
// 	t_stack *next;

// 	if (aparent && elem)
// 	{
// 		next = (*aparent)->next;
// 		if (*aparent == elem)
// 		{
// 			ft_stackdelone(aparent, content_delete);
// 			*aparent = next;
// 			if (*aparent && (*aparent)->next != NULL)
// 				(*aparent)->prev = NULL;
// 		}
// 		else
// 			ft_stackpop(&(*aparent)->next, elem);
// 	}
// }

void	push_short(t_format *stvar, t_part *part_var)
{
	t_ull size;

	size = (t_ull)(part_var->len / 2);
	insertion_sort(part_var->parts, part_var->len, &part_var->min, &part_var->max);
	stvar->median = find_median_array(part_var->parts, part_var->len);
	push_back(stvar, part_var);
	set_min_max(part_var);
}

void	push_half(t_format *stvar, t_part *part_var, int *list, int b_len)
{
	int part_len;
	
	lst_cpy(stvar->stack_b, list);
	insertion_sort(list, stvar->argc - stvar->sort_index, &stvar->min, &stvar->max);
	stvar->median = find_median_array(list, (stvar->argc - stvar->sort_index - 1));
	push_back(stvar, part_var);
	part_len = ((b_len) / 2);
	set_min_maxarray(stvar, list + part_len, part_len);
	if (part_len <= 3)
		sort_short(stvar, 'b', part_len);
}

// // t_part *setup_part(t_format *stvar, t_part *part_var, int *list)
// // {
// // 	// ret = part_addnew(&part_var, list, part_len);
// // 	// part_var = (t_part *)malloc(sizeof(t_part));
// // 	part_var = (t_part *)malloc(sizeof(t_part));
// // 	part_var->parts = list;
// // 	part_var->len = ((stvar->argc - stvar->sort_index) / 2);
// // 	part_var->next = NULL;
// // 	part_var->prev = NULL;
// // 	part_var->min = 0;
// // 	part_var->max = 0;
// // 	return (part_var);
// // }

int		conquer_list(t_format *stvar, t_part *part_var, int *list)
{
	int b_len;

	while (stvar->index != stvar->argc)
	{
		b_len = stvar->argc - stvar->sort_index;
		if (b_len > 3)
			push_half(stvar, part_var, list, b_len);
		else if (stvar->index == stvar->sort_index && b_len <= 3)
			sort_short(stvar, 'b', b_len);
		else
			push_short(stvar, part_var);
	}
	return (1);
}
