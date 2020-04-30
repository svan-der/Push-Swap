/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   diff_vers.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 10:56:27 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/25 11:43:20 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// int find_median(t_stack *stack_a, int argc, int min, int max)
// {
// 	int i;
// 	double j;
// 	int num;
// 	double median;
// 	t_stack *temp;

// 	num = 0;
// 	i = 0;
// 	j = (argc / 2);
// 	if (argc % 2 == 0)
// 		j -= 1;
// 	temp = stack_a;
// 	printf("this is median:|%f|\n", j);
// 	while (i < j)
// 	{
// 		temp = temp->next;
// 		i++;
// 	}
// 	median = temp->num;
// 	if (argc % 2 == 0)
// 	{
// 		temp = temp->next;
// 		num = temp->num;
// 		median = ((median + num) / 2);
// 		printf("this is median: %f\n", median);
// 	}
// 	return (ft_intround(median));
// }


// int		*pre_sort(int *list, t_format *stvar, int i, int *partition)
// {
// 	int 	temp;
// 	int		median;
// 	int		num;

// 	temp = list[i];
// 	median = stvar->median;
// 	if (list == NULL)
// 		return (partition);
// 	num = list[i];
// 	if (num < median && num && index > 3)
// 	{
// 		// stvar->partition[i] = &temp;
// 		partition[i] = temp;
// 		stvar->index -= 1;
// 		i++;
// 		if (temp != NULL)
// 			pre_sort(list, stvar, i, partition);
// 	}
// 	else
// 	{
// 		i++;
// 		if (temp != NULL)
// 			pre_sort(list, stvar, i, partition);
// 	}
// 	return (partition);
// }

// int		*part_sort_copy(t_stack *stack_a, t_format *stvar, int i, int *partition)
// {
// 	t_stack *temp;
// 	int		median;
// 	int		num;

// 	temp = stack_a;
// 	median = stvar->median;
// 	if (stack_a == NULL)
// 		return (partition);
// 	num = stack_a->num;
// 	if (num < median && num)
// 	{
// 		partition[i] = temp->num;
// 		ft_putstr("pb\n");
// 		push_b(&temp, &stvar->stack_b);
// 		stvar->index -= 1;
// 		temp->prev = stack_a->prev;
// 		temp->prev->next = temp;
// 		stack_a = temp;
// 		i++;
// 		if (temp != NULL)
// 			part_sort(stack_a, stvar, i, partition);
// 	}
// 	else
// 	{
// 		if (temp != NULL)
// 			part_sort(stack_a->next, stvar, i, partition);
// 	}
// 	return (partition);
// }

// int		push_back(t_stack *stack_b, t_format *stvar, int i, int *partition)
// {
// 	t_stack *temp;
// 	int		median;
// 	int		num;
// 	int		j;

// 	temp = stack_b;
// 	median = stvar->median;
// 	if (stack_b == NULL)
// 		return (partition);
// 	j = 0;
// 	while (j != 3)
// 	{
// 		j++;
// 		num = stack_b->num;
// 		if (num < median && num)
// 		{
// 			partition[i] -= i;
// 			ft_putstr("pb\n");
// 			push_a(&stack_b, &stvar->stack_a);
// 			stvar->index += 1;
// 			i++;
// 		}
// 		else
// 			rotate_a(&stack_b);
// 	}
// 	return (i);
// }

// int		*pre_sort_array(int *list, t_format *stvar, int i, int *partition)
// {
// 	int 	temp;
// 	int		median;
// 	int		num;

// 	temp = list[i];
// 	median = stvar->median;
// 	if (list == NULL)
// 		return (partition);
// 	num = list[i];
// 	if (num < median && num && index > 3)
// 	{
// 		// stvar->partition[i] = &temp;
// 		partition[i] = temp;
// 		stvar->index -= 1;
// 		i++;
// 		if (temp != NULL)
// 			pre_sort(list, stvar, i, partition);
// 	}
// 	else
// 	{
// 		i++;
// 		if (temp != NULL)
// 			pre_sort(list, stvar, i, partition);
// 	}
// 	return (partition);
// }


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
