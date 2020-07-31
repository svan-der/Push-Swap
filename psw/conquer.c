/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:35:59 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/30 16:27:54 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*presort_stack_b(t_pw_var *stvar, t_stack *current, int *i)
{
	t_stack *temp;
	char	*oper_b;

	temp = stvar->stack_b;
	oper_b = NULL;
	*i = 0;
	if (temp && temp->next)
	{
		// ft_printf("temp:%i temp->next:%i\n", temp->num, temp->next->num);
		// ft_printf(CYN"IN PRESORT STACK_B\n"RESET);
		// print_stack_list(stvar->stack_b, 'b');

		// set_min_max(stvar, 'b');
		// ft_printf(CYN"min:%i max:%i current:%i i:%i\n"RESET, stvar->min, stvar->max, current->num, *i);
		if (current->num < stvar->min)
			find_min(temp, stvar->min, i);
		else if (current->num > stvar->max)
			find_max(temp, stvar->max, i);
		else if (current->num > stvar->min && current->num < stvar->max)
			oper_b = find_pos(stvar, current, temp, i);
		// if (*i == (stvar->argc - stvar->index))
		// 	*i = 0;
	}
	if (*i > 1)
		oper_b = fastest_rotate(stvar, 'b', i);
	// if (oper_b)
	// 	ft_printf("oper_b:%s i:%i\n", oper_b, *i);
	return (oper_b);
}

int			sort_short_stack(t_pw_var *stvar, int argc)
{
	int ret;
	int j;

	ret = 1;
	j = (argc % 2) ? ((argc + 1) / 2) : argc / 2;
	argc = j;
	while (stvar->index != j)
	{
		if (stvar->stack_a->num < stvar->median)
			ret = do_op(stvar, PB, 'b', 1);
		else
			ret = do_op(stvar, RA, 'a', 1);
		if (ret == -1)
			error_handling(stvar, NULL, -1);
	}
	ret = sort_five_stack(stvar, 'a', stvar->index);
	if (ret == -1)
		error_handling(stvar, NULL, -1);
	set_min_max(stvar, 'b');
	ret = sort_five_stack(stvar, 'b', stvar->argc - stvar->index);
	if (ret == 1)
		return (ret);
	else
		error_handling(stvar, NULL, -1);
}

void	push_back_part(t_pw_var *stvar, int argc)
{
	int		total;
	char	*instr;
	t_stack	*current;

	total = stvar->argc - 1;
	while (argc)
	{
		current = find_high(stvar, 'b', &total);
		if (current->dist_top == 1)
		{
			instr = SB;
			if (current->prev && current->next)
				instr = (current->prev->num < current->next->num) ? RB : SB;
			do_op(stvar, instr, 'b', 1);
		}
		else if (current->dist_top > 1)
		{
			instr = fastest_rotate(stvar, 'b', &current->dist_top);
			do_op(stvar, instr, 'a', current->dist_top);
		}
		do_op(stvar, PA, 'b', 1);
		argc--;
		total--;
	}
}

void	part_sort(t_pw_var *stvar, int argc, int i)
{
	char *instr;
	int j;
	t_stack *top;
	t_stack *bottom;
	int res;

	j = argc;
	while (j)
	{
		// ft_printf("j is:%i\n", j);
		res = 0;
		top = stvar->stack_a;
		// ft_printf(GRN"|i:%i top:%i    part_id:%i top->index:%i    dist_top:%i|\n"RESET, i, top->num, top->part_id, top->index, top->dist_top);
		bottom = stvar->stack_a->tail;
		// ft_printf(YEL"|i:%i bottom:%i part_id:%i bottom->index:%i dist_top:%i|\n"RESET, i, bottom->num, bottom->part_id, bottom->index, bottom->dist_top);
		if (top->part_id == i || bottom->part_id == i)
		{
			if (top->part_id == i && bottom->part_id == i)
			{
				// ft_printf("\n");
				// ft_printf(CYN"=========== OPTION 1 ===========\n\n"RESET);
				if (j != 1)
					res = shortest_dist(stvar, top, bottom);
				sort_top_bottom(stvar, res, top, bottom);
			}
			else if (top->part_id == i)
			{
				// ft_printf(BLU"=================== OPTION 2 ==============\n\n"RESET);
				sort_top(stvar, top);
			}
			else if (bottom->part_id == i)
			{
				// ft_printf("\n");
				// ft_printf(YEL"=================== OPTION 3 ==============\n\n"RESET);
				sort_bottom(stvar, bottom);
				// find_part(stvar, i);
			}
			// print_stack_list(stvar->stack_b, 'b');
		}
		else if (top->part_id != i && bottom->part_id != i)
		{
			// ft_printf("\n");
			// ft_printf(RED"================== OPTION 4 =================\n\n"RESET);
			find_part(stvar, i);
		}
		check_top_b(stvar);
		// print_stack_list(stvar->stack_b, 'b');
		j -= 1;
	}
	// ft_printf("END\n\n");
}

void	insertion_sort(int *list, int argc, int *min, int *max)
{
	int i;
	int j;
	int temp;

	i = 1;
	while (i < argc)
	{
		temp = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > temp)
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = temp;
		i++;
	}
}
