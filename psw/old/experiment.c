#include "../includes/psw_env.h"
#include "../includes/push_swap.h"

void	sort_fastest(t_pw_var *stvar, t_stack *current, int *dist, char *ins)
{
	int i;

	i = 0;
	if (dist != 0)
	{
		do_op(stvar, ins, 'a', *dist);
		if (ins == RRA || ins == RA)
			check_dble(stvar, ins);
		// check_dble(stvar, ins);
	}
	ins = presort_stack_b(stvar, current, &i);
	// if (ins)
	// 	ft_printf(MAG"presort stack_b ins:%s\n"RESET, ins);
	if (ins != NULL)
	{
		do_op(stvar, ins, 'a', i);
		if (ins == RRB || ins == RB)
			check_dble(stvar, ins);
	}
	do_op(stvar, PB, 'a', 1);
	// check_top_b(stvar);
	*dist = stvar->index;
	current = NULL;
	// print_stack_list(stvar->stack_b, 'b');
	// print_stack_list(stvar->stack_a, 'a');
}

void	experiment_sort(t_pw_var *stvar, int argc, int index)
{
	int		shortest;
	int 	dist;
	char	*instr;
	char	*ins_f;
	t_stack *fastest;
	t_stack *temp;

	temp = stvar->stack_a;
	fastest = 0;
	shortest = argc;
	// ft_printf("part_id:%i index:%i\n", temp->part_id, index);
	// print_stack_list(stvar->stack_a, 'a');
	while (argc)
	{
		while (temp)
		{
			// ft_printf("temp->part_id:%i index:%i\n", temp->part_id, index);
			if (temp->part_id == index)
			{
				dist = temp->dist_top;
				instr = fastest_rotate(stvar, 'a', &dist);
				// ft_printf("num:%i dist:%i\n", temp->num, dist);
				if (stvar->argc - stvar->index != 0)
				{
					set_min_max(stvar, 'b');
					dist += presort_exp_b(stvar, temp);
					// ft_printf("dist now:%i\n", dist);
				}
				if (dist < shortest)
				{
					ins_f = instr;
					shortest = temp->dist_top;
					fastest = temp;
					// ft_printf("shortest:%i dist:%i num:%i\n", shortest, dist, temp->num);
				}
			}
			temp = temp->next;
		}
		// if (fastest->index != index)
		// 	ft_printf("shortest:%i, num:%i ins:%s\n", shortest, fastest->num, ins_f);
		sort_fastest(stvar, fastest, &shortest, ins_f);
		argc--;
		temp = stvar->stack_a;
	}
}

int		presort_exp_b(t_pw_var *stvar, t_stack *current)
{
	t_stack *temp;
	char	*oper_b;
	int		i;

	temp = stvar->stack_b;
	oper_b = NULL;
	i = 0;
	if (temp && temp->next)
	{
		if (current->num < stvar->min)
			find_min(temp, stvar->min, &i);
		else if (current->num > stvar->min && current->num < stvar->max)
			oper_b = find_pos(stvar, current, temp, &i);
		// ft_printf(CYN"min:%i max:%i current:%i i:%i\n"RESET, stvar->min, stvar->max, current->num, i);
	}
	if (oper_b == NULL && i != 0)
		oper_b = fastest_rotate(stvar, 'b', &i);
	return (i);
}
