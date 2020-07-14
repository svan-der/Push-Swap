/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conquer_opts.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:49:34 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/13 22:38:55 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/psw_env.h"

void insertion_sort(int *list, int argc, int *min, int *max)
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
	if (argc >= 3)
	{
		*min = list[argc - 3];
		*max = list[argc - 1];
	}
	if (argc == 2)
	{
		*min = list[argc - 2];
		*max = list[argc - 1];
	}
	// print_array(list, argc);
}

/**
*** calculates if either the top or bottom is nearest to the top number in stack b
*** apart from checken absolute values also need to check the distance
**/

int	 calc_dist_top_b(t_pw_var *stvar, t_stack *top, t_stack *bottom)
{
	t_stack *current;
	int dist_top;
	int dist_bottom;
	int len;
	int i;

	if (stvar->stack_b == NULL)
		return (0);
	// print_stack_list(stvar->stack_b, 'b');
	// print_stack_list(stvar->stack_a, 'a');
	current = stvar->stack_b;
	// ft_printf("actual index order calculate closest to dist top b\n");
	len = stvar->index;
	i = (len % 2) ? ((len / 2) + 1) : len / 2;
	if (bottom->dist_top > i)
		dist_bottom = stvar->index - bottom->dist_top;
	else
		dist_bottom = bottom->dist_top;
	if (top->dist_top > i)
		dist_top = stvar->index - top->dist_top;
	else
		dist_top = top->dist_top;
	// ft_printf("num %i index:%i dist_top:%i top:%i\n", bottom->num, bottom->index, bottom->dist_top, bottom->dist);
	// ft_printf("dist bottom:%i\n", dist_bottom);

	// ft_printf("num:%i top->dist in stack_b:%i absolute dist_top:%i\n", top->num, top->dist, dist_top);
	// ft_printf("dist top:%i\n", dist_top);
	if (dist_top == dist_bottom)
	{
		// print_stack_list(stvar->stack_a, 'a');
		// ft_printf(YEL"num:%i top->dist_top:%i bottom->dist_top:%i\n"RESET, top->num, top->dist_top, bottom->dist_top);
		if (top->dist_top < bottom->dist_top)
			return (0);
		return (1);
	}
	if (dist_top < dist_bottom)
		return (0);
	return (1);
}

t_stack *return_bottom_position(t_pw_var *stvar, t_stack *temp, char *instr, int i)
{
	t_stack *bottom;
	int		j;

	j = 1;
	(void)instr;
	bottom = stvar->stack_b->tail;
	if (temp->num && stvar->stack_b->next)
	{
		while (bottom && j < i)
		{
			bottom = bottom->prev;
			if (bottom == NULL)
				bottom = stvar->stack_b->tail;
			j++;
		}
	}
	return (bottom);
}

t_stack *return_top_position(t_pw_var *stvar, t_stack *temp, char *instr, int i)
{
	t_stack *top;
	int		j;

	j = 1;
	top = stvar->stack_b;
	(void)instr;
	while (j < i && temp)
	{
		temp = temp->next;
		j++;
		if (temp == NULL)
			temp = stvar->stack_b;
	}
	if (temp->num && stvar->stack_b->next)
	{
		if (temp->next)
			top = temp->next;
		else
			top = stvar->stack_b;
	}
	return (top);
}

char	*check_double(t_pw_var *stvar, char *instr, int i, t_stack *current)
{
	t_stack *temp;
	t_stack *bottom;
	t_stack	*top;

	temp = stvar->stack_b;
	(void)current;
	if (instr == RA)
	{
		if (temp && temp->next)
		{
			// ft_printf(YEL"IN CHECK DOUBLE %s %i\n", instr, i);
			top = return_top_position(stvar, temp, instr, i);
			// ft_printf("top:%i top next:%i\n", temp->num, top->num);
			if (temp->num < top->num)
				instr = RR;
		}
	}
	else if (instr == RRA)
	{
		if (temp && temp->tail)
		{
			bottom = return_bottom_position(stvar, temp, instr, i);
			// ft_printf("top:%i top next:%i\n", temp->num, bottom->num);
			if (bottom->num > temp->num)
				instr = RRR;
		}
	}
	// ft_printf("INSTR:%s\n"RESET, instr);
	return (instr);
}

int		presort_stack_b(t_pw_var *stvar, t_stack *current, char *oper_a, int i)
{
	t_stack *temp;
	char	*instr;
	int		j;
	int		ret;

	j = 0;
	ret = 0;
	temp = stvar->stack_b;
	instr = NULL;
	ft_printf("oper_a:%s i:%i\n", oper_a, i);
	if (temp && temp->next)
	{
		// ft_printf("temp:%i temp->next:%i\n", temp->num, temp->next->num);
		ft_printf(CYN"IN PRESORT STACK_B\n"RESET);
		print_stack_list(stvar->stack_b, 'b');
		set_min_max(stvar, 'b');
		ft_printf("min:%i max:%i current:%i\n", stvar->min, stvar->max, current->num);
		if (current->num < stvar->min)
			find_min(temp, stvar->min, &j);
		else if (current->num > stvar->max)
			find_max(temp, stvar->max, &j);
		else if (current->num > stvar->min && current->num < stvar->max)
			instr = find_pos(stvar, current, temp, &j);
	}
	ft_printf(MAG"J is:%i\n"RESET, j);
	if (j > 0)
	{
		if (!instr)
			instr = fastest_rotate(stvar, 'b', j);
		ret = check_dble(stvar, oper_a, instr, ft_min(i, j));
		ft_printf(MAG"RET:%i OPER_A:%s INS:%s I:%i J:%i\n"RESET, ret, oper_a, instr, i, j);
		if (j > i && ret > 0)
		{
			ft_printf("j > i  j:%i\n", j - i);
			do_op(stvar, instr, 'b', j - i);
		}
		else if (j > 0)
		{
			ft_printf("instr:%s j:%i\n", instr, j);
			// print_stack_list(stvar->stack_b, 'b');
			do_op(stvar, instr, 'b', j);
			// print_stack_list(stvar->stack_b, 'b');
			// ft_printf("j:%i\n", j);
		}
		ft_printf("ret:%i i:%i  i - ret = %i\n", ret, i, (i - ret));
	}
	i = i - ret;
	ft_printf("END i:%i\n", i);
	return (i);
}

void	sort_top_bottom(t_pw_var *stvar, int i, t_stack *top, t_stack *bottom)
{
	char	*instr;
	int		j;
	int		ret;

	if (i != 0)
	{
		// ft_printf("bottom dist_top:%i\n", bottom->dist_top);
		instr = fastest_rotate(stvar, 'a', bottom->dist_top);
		if (ft_strnequ(instr, RR, 2))
		{
			// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, stvar->index - bottom->dist_top);
			j = stvar->index - bottom->dist_top;
			do_op(stvar, instr, 'a', j);
			do_op(stvar, PB, 'a', 1);
			find_solution(stvar, bottom, instr);
			// instr = check_double(stvar, instr, stvar->index - bottom->dist_top, bottom);
			// do_op(stvar, instr, 'a', stvar->index - bottom->dist_top);
		}
		else if (i == 1)
		{
			do_op(stvar, PB, 'a', 1);
			find_solution(stvar, top, NULL);
			// ret = presort_stack_b(stvar, top, NULL, 0);
		}
		else
		{
			// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, bottom->dist);
			j = bottom->dist_top;
			do_op(stvar, instr, 'a', j);
			do_op(stvar, PB, 'a', 1);
			find_solution(stvar, bottom, instr);
		}
		// ret = presort_stack_b(stvar, bottom, instr, j);
		// if (ret > 0)
		// {
		// 	ft_printf(YEL"do_op rest INSTR:%s NUM:%i\n"RESET, instr, j);
		// 	do_op(stvar, instr, 'a', j);
		// }
	}
	else
	{
		do_op(stvar, PB, 'a', 1);
		find_solution(stvar, top, NULL);
	}
	
}

void	sort_bottom(t_pw_var *stvar, t_stack *bottom)
{
	char	*instr;
	int		j;
	int		i;

	j = 0;
	instr = fastest_rotate(stvar, 'a', bottom->dist_top);
	ft_printf(RED"instr is:%s dist_top:%i\n"RESET, instr, bottom->dist_top);
	if (ft_strnequ(instr, RR, 2))
	{
		print_stack_list(stvar->stack_b, 'b');
		do_op(stvar, instr, 'a', stvar->index - bottom->dist_top);
		print_stack_list(stvar->stack_a, 'a');
		do_op(stvar, PB, 'a', 1);
		print_stack_list(stvar->stack_b, 'b');
		find_solution(stvar, bottom, NULL);
		print_stack_list(stvar->stack_a, 'a');
		// find_solution(stvar, bottom, RR);
		// i = stvar->index - bottom->dist_top;
		// instr = check_double(stvar, instr, stvar->index - bottom->dist_top, bottom);
		// do_op(stvar, instr, 'a', stvar->index - bottom->dist_top);
	}
	else
	{
		do_op(stvar, instr, 'a', bottom->dist_top);
		do_op(stvar, PB, 'a', 1);
		// ft_printf("bottom->index:%i bottom->dist_top:%i\n", bottom->index, bottom->dist);
		find_solution(stvar, bottom, instr);
		// i = bottom->dist_top;
		// instr = check_double(stvar, instr, bottom->dist_top, bottom);
		// do_op(stvar, instr, 'a', bottom->dist_top);
	}
	// j = presort_stack_b(stvar, bottom, instr, i);
	// if (j > 0)
	// {
	// 	ft_printf(YEL"do_op rest INSTR:%s NUM:%i\n"RESET, instr, j);
	// 	do_op(stvar, instr, 'a', j);
	// }
}

void	check_top_b(t_pw_var *stvar)
{
	int i;
	t_stack *temp;

	if (stvar->stack_b && stvar->stack_b->next)
	{
		i = stvar->argc - stvar->index;
		set_min_max(stvar, 'b');
		if (stvar->stack_b->num == stvar->max)
			return ;
		else
		{
			// temp = find_max(stvar->stack_b, stvar->max, &i);
			print_stack_b(&stvar->stack_b, 1);
			temp = find_high(stvar, 'b', &i);
			ft_printf("num:%i temp->dist_top:%i\n", temp->num, temp->dist_top);
			print_stack_b(&stvar->stack_b, 1);
			fastest_rotate(stvar, 'b', temp->dist_top);
		}
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
		ft_printf("\n\n");
<<<<<<< HEAD
		print_stack_list(stvar->stack_a, 'a');
		print_stack_list(stvar->stack_b, 'b');
		ft_printf("j is:%i\n", j);
=======
		// print_stack_list(stvar->stack_a, 'a');
		// print_stack_list(stvar->stack_b, 'b');
		print_stack(&stvar->stack_a, 1);
		print_stack_b(&stvar->stack_b, 1);
		ft_printf("\n");
>>>>>>> b010f318bbccb06c56a10dacb3dfc12257f63979
		res = 0;
		top = stvar->stack_a;
		ft_printf(GRN"|i:%i top:%i part_id:%i top->index:%i dist_top:%i|\n"RESET, i, top->num, top->part_id, top->index, top->dist_top);
		bottom = stvar->stack_a->tail;
<<<<<<< HEAD
		check_top_b(stvar);
		ft_printf(YEL"|i:%i bottom:%i part_id:%i bottom->index:%i|\n"RESET, i, bottom->num, bottom->part_id, bottom->index);
=======
		ft_printf(YEL"|i:%i bottom:%i part_id:%i bottom->index:%i dist_top:%i|\n"RESET, i, bottom->num, bottom->part_id, bottom->index, bottom->dist_top);
>>>>>>> b010f318bbccb06c56a10dacb3dfc12257f63979
		if (top->part_id == i || bottom->part_id == i)
		{
			if (top->part_id == i && bottom->part_id == i)
			{
				ft_printf(CYN"OPTION 1\n"RESET);
				if (j != 1)
					res = calc_dist_top_b(stvar, top, bottom);
				do_op(stvar, (instr = PB), 'b', 1);
				sort_top_bottom(stvar, res, top, bottom);
				// print_stack_list(stvar->stack_b, 'b');
			}
			else if (bottom->part_id == i)
			{
				ft_printf(BLU"OPTION 2\n"RESET);
				sort_bottom(stvar, bottom);
			}
			// print_stack_list(stvar->stack_b, 'b');
		}
		else if (top->part_id != i && bottom->part_id != i)
		{
			ft_printf(RED"OPTION 3\n"RESET);
			find_part(stvar, i);
			instr = PB;
			// print_stack_list(stvar->stack_b, 'b');
		}
		// ft_printf("instr:%s\n", instr);
		if (ft_strequ(instr, PB))
			j--;
	}
	ft_printf("\n\n");
}

int		do_op(t_pw_var *stvar, char *str, char c, int num)
{
	int i;
	int ret;

	i = 0;
	while (i < num)
	{
		ret = dispatch_sort(stvar, str, 1);
		if (ret == -1)
			return (-1);
		update_stack(stvar, c);
		set_index(&stvar->stack_a, stvar->sorted, stvar->index);
		set_index(&stvar->stack_b, stvar->sorted, stvar->argc - stvar->index);
		i++;
	}
	return (ret);
}

char	*fastest_rotate(t_pw_var *stvar, char c, int index)
{
	int i;
	int len;

	len = (c == 'a') ? stvar->index : (stvar->argc - stvar->index);
	// i = (len % 2) ? ((len + 1) / 2) : len / 2;
	i = (len % 2) ? ((len / 2) + 1) : len / 2;
	// ft_printf("len:%i\t i:%i\n", len, i);
	ft_printf("char:%c\tindex:%i\t i:%i\n", c, index, i);
	// if (index <= i)
	if (index < i)
		return (c == 'a' ? RA : RB);
	else
		return (c == 'a' ? RRA : RRB);
}

void	update_stack(t_pw_var *stvar, char c)
{
	t_stack *temp;

	if (c == 'a')
		temp = stvar->stack_a;
	if (c == 'b')
		temp = stvar->stack_b;
	if (c == 'a')
	{
		while (temp != NULL && temp->next != NULL)
		{
			find_distance(temp, temp->num, stvar->sorted);
			temp = temp->next;
		}
	}
	add_tail(&stvar->stack_a);
	add_tail(&stvar->stack_b);
}
