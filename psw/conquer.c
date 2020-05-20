/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:35:59 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/20 10:09:11 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

// void 	sort_unsorted(t_pw_var *stvar, char c, int argc)
// {
// 	t_stack *stack;
// 	int min;
// 	int max;
// 	int i;

// 	i = 0;
// 	min = stvar->min;
// 	max = stvar->max;
// 	if (c == 'a')
// 		stack = stvar->stack_a;
// 	else
// 		stack = stvar->stack_b;
// 	if ((*stack->num) == min && (*stack->next->num) != max)
// 		dispatch_sort(stvar, NULL, 0);
// 	if ((*stack->num) == min && (*stack->next->num) == max)

// }

void	sort_and_pushback(t_pw_var *stvar)
{
	if (stvar->stack_b == NULL)
		return ;
	while (stvar->argc - stvar->index > 3)
	{
		if ((stvar->stack_b->num) > stvar->median)
			dispatch_sort(stvar, PA, 1);
		else
			dispatch_sort(stvar, RB, 1);
	}
}

void	push_short(t_pw_var *stvar, int *list, int b_len)
{
	int part_len;
	int argc;
	int index;

	argc = stvar->argc - stvar->sort_index;
	index = stvar->argc - stvar->sort_index - 1;
	lst_cpy(&(stvar)->stack_b, list);
	insertion_sort(list, argc, &stvar->min, &stvar->max);
	stvar->median = find_median_array(list, index);
	sort_and_pushback(stvar);
	part_len = ((b_len) / 2);
	set_min_maxarray(stvar, list + part_len, part_len);
	// sort_unsorted(stvar, 'a');
	// if (part_len <= 3)
	// 	sort_short(stvar, 'b', part_len);
}

void	push_half(t_pw_var *stvar, int *list, int b_len)
{
	int part_len;
	int argc;
	int index;

	argc = stvar->argc - stvar->sort_index;
	index = stvar->argc - stvar->sort_index - 1;
	lst_cpy(&(stvar)->stack_b, list);
	insertion_sort(list, argc, &stvar->min, &stvar->max);
	stvar->median = find_median_array(list, index);
	sort_and_pushback(stvar);
	part_len = ((b_len) / 2);
	set_min_maxarray(stvar, list + part_len, part_len);
}

int		conquer_list(t_pw_var *stvar, int *list)
{
	int b_len;

	while (stvar->index != stvar->argc)
	{
		b_len = stvar->argc - stvar->sort_index;
		if (b_len > 3)
			push_half(stvar, list, b_len);
		else if (stvar->index == stvar->sort_index && b_len <= 3)
			sort_short(stvar, 'b', b_len);
		else
			push_short(stvar, list, b_len);
	}
	return (1);
}
