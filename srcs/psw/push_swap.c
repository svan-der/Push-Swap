/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:52:42 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/17 16:57:59 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "psw_env.h"
#include <stdio.h>

// void	sort_pushback(t_stack *stack_b,  t_format *stvar)
// {
// 	t_stack *temp;
// 	int		median;
// 	int		num;
// 	int		i;

// 	i = 1;
// 	temp = stack_;
// 	median = stvar->median;
// 	if (stack_a == NULL)
// 		return ;
// 	num = stack_a->num;
// 	if (num < median && num)
// 	{
// 		push_b(&temp, &stvar->stack_b);
// 		temp->prev = stack_a->prev;
// 		temp->prev->next = temp;
// 		stack_a = temp;
// 		stvar->index -= 1;
// 		if (temp != NULL)
// 			pre_sort(stack_a, stvar);
// 	}
// 	else
// 	{
// 		if (temp != NULL)
// 			pre_sort(stack_a->next, stvar);
// 	}
	
// }

void	part_sort(t_stack *stack_a, t_format *stvar)
{
	t_stack *temp;
	int		median;
	int		num;
	int		i;

	i = 1;
	temp = stack_a;
	median = stvar->median;
	if (stack_a == NULL)
		return ;
	num = stack_a->num;
	if (num < median && num)
	{
		push_b(&temp, &stvar->stack_b);
		stvar->index -= 1;
		temp->prev = stack_a->prev;
		temp->prev->next = temp;
		stack_a = temp;
		if (temp != NULL)
			part_sort(stack_a, stvar);
	}
	else
	{
		if (temp != NULL)
			part_sort(stack_a->next, stvar);
	}
}

int		ft_intround(double n)
{
	double	res;
	int		num;

	if (n < 0)
		n = n * -1;
	num = n;
	res = n - num;
	res *= 2;
	if (res >= 1)
		return (n + 0.5);
	return (n);
}

int		split_stack(t_stack *stack_a, int argc)
{
	int 	i;
	double	j;
	int		num;
	double	median;
	t_stack *temp;

	num = 0;
	i = 0;
	j = (argc / 2);
	if (argc % 2 == 0)
		j -= 1;
	temp = stack_a;
	printf("this is median:|%f|\n", j);
	while (i < j)
	{
		temp = temp->next;
		i++;
	}
	median = temp->num;
	if (argc % 2 == 0)
	{
		temp = temp->next;
		num = temp->num;
		median = ((median + num) / 2);
		printf("this is median: %f", median);
	}
	return (ft_intround(median));
}

/** 
 * Breekt elke keer de lijsten op in sublijsten door recursief aanroepen van de functie
 * daarna voegt hij ze samen via sorted_merge
 * 1) Traverse input list and copy next pointer to arbit pointer for every node.
 * 2) Do Merge Sort for the linked list formed by arbit pointers.
 * elke klein sublist sorteer je, en recursief gaat hij dan met de volgende sublist verder
 * met sorteren
 */

// void	split_list(t_stack *list, t_stack **front, t_stack **back)
// {
// 	t_stack *fast;
// 	t_stack *slow;

// 	slow = list;
// 	fast = list->next;
// 	while (fast != NULL)
// 	{
// 		fast = fast->next;
// 		if (fast != NULL)
// 		{
// 			slow = slow->next;
// 			fast = fast->next;
// 		}
// 	}
// 	*front = list;
// 	*back = slow->next;
// 	slow->next = NULL;
// }

// t_stack	*sorted_merge(t_stack *list_a, t_stack *list_b)
// {
// 	t_stack *result;

// 	if (list_a == NULL)
// 		return (list_b);
// 	else if (list_b == NULL)
// 		return (list_a);
// 	if (list_a->num <= list_b->num)
// 	{
// 		result = list_a;
// 		result->next = sorted_merge(list_a->next, list_b);
// 	}
// 	else
// 	{
// 		result = list_b;
// 		result->next = sorted_merge(list_a, list_b->next);	
// 	}
// 	return (result);
// }

// void	merge_sort(t_stack **stack_a)
// {
// 	t_stack *head;
// 	t_stack *temp;
// 	t_stack *temp1;
// 	int i;

// 	i = 0;
// 	head = *stack_a;
// 	if (head == NULL || head->next == NULL)
// 		return ;
// 	split_list(head, &temp, &temp1);
// 	merge_sort(&temp);
// 	merge_sort(&temp1);
// 	stack_a = sorted_merge(temp, temp1);
// }

void	print_array(int *list, int argc)
{
	int i;

	i = 0;
	while (i < argc)
	{
		printf("this is num:%i\n", list[i]);
		list[i];
		i++;
	}
}

void	insertion_sort(int *list, int argc)
{
	int i;
	int j;
	int	temp;

	i = 1;
	while (i < argc)
	{
		temp = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > temp)
		{
			printf("this is elem 1:%i and elem2:%i\n", list[j + 1], list[j]);
			list[j + 1] = list[j];
			printf("this is elem %i\n", list[j + 1]);
			j--;
		}
		list[j + 1] = temp;
		printf("this is elem :%i\n", list[j + 1]);
		i++;
	}
	print_array(list, 6);
}

int		*lst_cpy(int *new_list, t_stack *stack)
{
	t_stack *current;
	int		i;
	int		j;

	new_list = NULL;
	new_list = (int *)malloc(sizeof(int*) * 5);
	current = stack;
	i = 0;
	j = 0;
	while (current != NULL)
	{
		new_list[i] = current->num;
		current = current->next;
		i++;
	}
	return (new_list);
}

int		run_pw(t_format *stvar)
{
	t_stack **temp;
	int		*temp1;
	int		n;
	int		ret;
	t_inst	inst;
	int		i;

	i = 0;
	n = stvar->argc;
	stvar->stack_b = stvar->stack_a;
	temp1 = lst_cpy(temp1, stvar->stack_a);
	insertion_sort(temp1, stvar->argc);
	print_array(temp1, stvar->argc);
	ft_bzero(&inst, sizeof(t_inst));
	print_stack(stvar->stack_a, 1);
	stvar->median = ret;
	part_sort(stvar->stack_a, stvar);
	// // sort_v
	// print_instructions(stvar->inst_lst, ret);
	// print_stack(stvar->stack_a, 1);
	// print_stack_b(stvar->stack_b, 1);
	// ret = check_sorted(stvar->stack_a, stvar->stack_b);
	// printf("This is ret after check_sorted:%d\n", ret);
	return (1);
}
