/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:15:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/17 18:56:30 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"
#include "../includes/push_swap.h"

// /*
// ** functions divides the list in partitions
// */

// int		divide_and_presort(t_pw_var *stvar, int *sorted_list)
// {
// 	int i;

// 	i = 0;
// 	while (stvar->index > 3)
// 	{
// 		part_sort(stvar, ft_min_size(stvar->index, stvar->argc));
// 		ft_printf("stvar->index:%d\n", stvar->index);
// 		if (stvar->index <= 3)
// 		{
// 			sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
// 			break ;
// 		}
// 		sorted_list = lst_cpy(&(stvar)->stack_a, *(&sorted_list));
// 		// stvar->tail = sorted_list[stvar->index - 1];
// 		insertion_sort(sorted_list, stvar->index, &stvar->min, &stvar->max);
// 		stvar->median = find_median_array(sorted_list, stvar->index);
// 		i++;
// 	}
// 	// return (1);
// 	return (conquer_list(stvar, sorted_list));
// }

// void		ft_memdel(void **ap)
// {
// 	if (*ap)
// 	{
// 		free(*ap);
// 		*ap = NULL;
// 	}
// }

void	set_partitions(t_pw_var *stvar, int partitions, int part_len)
{
	t_stack *temp;
	int		part_index;
	int		i;
	int		j;

	temp = stvar->stack_a;
	part_index = 1;
	i = 0;
	j = 0;
	// print_array(stvar->sorted, stvar->argc);
	// ft_printf("partitions:%i\t\tpart_len:%i\n", partitions, part_len);
	// ft_printf("temp->num:%i\tsorted:%i\n", temp->num, stvar->sorted[i]);
	while (partitions)
	{
		if (j == part_len)
		{
			// ft_printf("\e[1;93mj is:%i\e[0m\n", j);
			j = 0;
			partitions -= 1;
			part_index += 1;
			if (partitions == 1)
			{
				// ft_printf("part_len before:%i\n", part_len);
				part_len = (stvar->argc - i);
				// ft_printf("\e[1;92mstvar->argc:%i\tpart_len:%i\e[0m\n", stvar->argc, part_len);
			}
			// ft_printf("i:%i\tj:%i\n", i, j);
			// ft_printf("\e[1;91mpartitions:%i\t\tpart_len:%i\tpart_index:%i\e[0m\n", partitions, part_len, part_index);
		}
		if (temp->num == stvar->sorted[i])
		{
			// ft_printf("\e[1;94mstvar->sorted[i]:%i\e[0m\n", stvar->sorted[i]);
			// ft_printf("temp->num:%i\tindex sorted:%i\t\tpart_index:%i\t\tsorted:%i\n", temp->num, i, part_index, stvar->sorted[i]);
			temp->part_id = part_index;
			// ft_printf("temp->part_id:%i\n", temp->part_id);
			// print_stack_list(stvar->stack_a, 'a');
			i++;
			j++;
		}
		temp = temp->next;
		if (temp == NULL)
			temp = stvar->stack_a;
	}
	// print_stack_list(stvar->stack_a, 'a');
}

int	assign_partitions(t_pw_var *stvar, int *part_num)
{
	int partitions;
	int num;

	partitions = 1;
	num = stvar->argc;
	if (num < 100)
	{
		while (num > 10)
		{
			num = (num / 2);
			partitions++;
		}
	}
	if (num >= 100 && num < 500)
		partitions = 5;
	else if (num == 500)
		partitions = 11;
	// ft_printf("amount of partitions:%i\n", partitions);
	*part_num = ((stvar->argc % partitions)) ? 1 : 0;
	// ft_printf("num is:%i\n", *part_num);
	*part_num += (stvar->argc / partitions);
	set_partitions(stvar, partitions, *part_num);
	return (partitions);
}

void	sort_short_opts(t_pw_var *stvar)
{
	if (stvar->index == 2)
		sort_two('a', stvar);
	else if (stvar->index == 3)
		sort_three(stvar, stvar->min, stvar->max);
	else if (stvar->index < 6)
		sort_five_stack(stvar, 'a', stvar->index - stvar->sort_index);
}

// char	*find_high(t_pw_var *stvar, char c, int *index)
// {
// 	t_stack	*current;
// 	int		dist_top;

// 	current = (c == 'a') ? stvar->stack_a : stvar->stack_b;
// 	// print_stack_list(current, c);
// 	ft_printf("index find high:%i\n", *index);
// 	dist_top = 0;
// 	while (current)
// 	{
// 		ft_printf("num is:%i\n", current->num);
// 		if (current->index == *index)
// 			break ;
// 		dist_top++;
// 		current = current->next;
// 	}
// 	// if (c == 'b')
// 	current->dist_top = dist_top;
// 	ft_printf("dist_top is:%d\n", dist_top);
// 	if (dist_top == 0)
// 	{
// 		ft_printf("option 1\n");
// 		*index = ((c == 'a')) ? *index + 1 : *index - 1;
// 		return ((c == 'a') ? PB : PA);
// 	}
// 	else
// 	{
// 		if (dist_top == 1)
// 		{
// 			ft_printf("option 2\n");
// 			return (c == 'a' ? SA : SB);
// 		}
// 		ft_printf("option 3\n");
// 		return (fastest_rotate(stvar, c, dist_top));
// 	}
// }

t_stack 	*find_high(t_pw_var *stvar, char c, int *index)
{
	t_stack	*current;
	int		dist_top;

	current = (c == 'a') ? stvar->stack_a : stvar->stack_b;
	// print_stack_list(current, c);
	// ft_printf("index find high:%i\n", *index);
	dist_top = 0;
	while (current)
	{
		// ft_printf("num is:%i\n", current->num);
		if (current->index == *index)
			return (current);
		dist_top++;
		current = current->next;
	}
	return (NULL);
	// if (c == 'b')
	// current->dist_top = dist_top;
	// ft_printf("dist_top is:%d\n", dist_top);
	// if (dist_top == 0)
	// {
	// 	ft_printf("option 1\n");
	// 	*index = ((c == 'a')) ? *index + 1 : *index - 1;
	// 	return ((c == 'a') ? PB : PA);
	// }
	// else
	// {
	// 	if (dist_top == 1)
	// 	{
	// 		ft_printf("option 2\n");
	// 		return (c == 'a' ? SA : SB);
	// 	}
	// 	ft_printf("option 3\n");
	// 	return (fastest_rotate(stvar, c, dist_top));
	// }
}

void	push_back_part(t_pw_var *stvar)
{
	int		argc;
	int		total;
	char	*instr;
	t_stack	*current;

	total = stvar->argc - 1;
	// ft_printf("total:%i\n", total);
	// ft_printf("index is:%i\n", stvar->sort_index);
	// ft_printf("amount in stack_a:%i\n", stvar->index);
	argc = stvar->argc;
	while (argc)
	{
		// ft_printf(YEL"TOTAL IS:%i\n"RESET, total);
		current = find_high(stvar, 'b', &total);
		// ft_printf(GRN"dist_top:%i\n"RESET, current->dist_top);
		if (current->dist_top == 1)
		{
			instr = SB;
			if (current->prev && current->next)
			{
				// ft_printf(RED"prev:%i next:%i\n"RESET, current->prev->num, current->next->num);
				instr = (current->prev->num < current->next->num) ? RB : SB;
			}
			do_op(stvar, instr, 'b', 1);
		}
		else if (current->dist_top > 1)
		{
			instr = fastest_rotate(stvar, 'b', current->dist_top);
			if (ft_strnequ(instr, RR, 2))
			{
				// ft_printf("instr:%s index:%i\n", instr, total - (current->dist_top - 1));
				do_op(stvar, instr, 'a', total - (current->dist_top - 1));
				// print_stack_list(stvar->stack_b, 'b');
			}
			else
			{
				// ft_printf(CYN"instr:%s index:%i dist_top:%i\n"RESET, instr, current->dist_top);
				do_op(stvar, instr, 'a', current->dist_top);
			}
		}
		// ft_printf(GRN"instr:%s current->dist_top:%i\n"RESET, instr, current->dist_top);
		// do_op(stvar, instr, 'b', current->dist_top);
		do_op(stvar, PA, 'b', 1);
		total--;
		argc--;
		// print_stack_list(stvar->stack_a, 'a');
		// print_stack_list(stvar->stack_b, 'b');
	}
}

int		divide_and_presort(t_pw_var *stvar, int *sorted_list)
{
	int part_index;
	int	part_num;
	int	i;

	i = 1;
	part_index = assign_partitions(stvar, &part_num);
	// ft_printf("argc:%i\t amount of partitions:%i with %i num \n", stvar->argc, part_index, part_num);
	// ft_printf("received parts\n");
	// ft_printf("part_num:%i index:%i\n", part_num, i);
	// print_stack_list(stvar->stack_a, 'a');
	part_index == 1;
	while (part_index != 0)
	{
		// ft_printf(BLU"ITERATION:%i\n"RESET, part_index);
		part_index--;
		// ft_printf(YEL"part_num:%i i:%i\n"RESET, part_num, i);
		if (part_index == 0)
		{
			part_num = stvar->index;
		}
		part_sort(stvar, part_num, i);
		// if (part_index == 0)
		// {
			// print_stack_list(stvar->stack_a, 'a');
			// print_stack_list(stvar->stack_b, 'b');
		// }
		i++;
	}
	(void)sorted_list;
	// ft_printf(GRN"total ins after presort:%i\n"RESET, stvar->total_ins);
	push_back_part(stvar);
	// print_stack_list(stvar->stack_a, 'a');
	// print_stack_list(stvar->stack_b, 'b');
	return (1);
}

int		divide_list(t_pw_var *stvar)
{
	stvar->median = find_median_array(stvar->sorted, stvar->index);
	// ft_printf("stvar->sort_index:%i\n", stvar->sort_index);
	// print_tail(stvar->stack_a->tail);
	// ft_printf("median is:%d\n\n", stvar->median);
	// ft_printf("stvar->index:%i\tstvar->argc:%i\n", stvar->index, stvar->argc);
	if (stvar->argc < 6)
		return (sort_five_stack(stvar, 'a', stvar->index - stvar->sort_index));
	// ft_printf("return after sorting:%i\n", ret);
	else if (stvar->argc < 11)
		return (sort_short_stack(stvar, ft_min_size(stvar->index, stvar->argc)));
	else
	{
		return (divide_and_presort(stvar, stvar->sorted));
	}
}
