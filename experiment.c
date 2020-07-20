#include "../includes/push_swap.h"
#include "../includes/psw_env.h"

// void	part_sort(t_pw_var *stvar, int argc, int i)
// {
// 	char *instr;
// 	int j;
// 	t_stack *top;
// 	t_stack *bottom;
// 	int res;

// 	j = argc;
// 	while (j)
// 	{
// 		ft_printf("\n\n");
// 		// print_stack_list(stvar->stack_a, 'a');
// 		// print_stack_list(stvar->stack_b, 'b');
// 		res = 0;
// 		top = stvar->stack_a;
// 		ft_printf(GRN"|i:%i top:%i part_id:%i top->index:%i|\n"RESET, i, top->num, top->part_id, top->index);
// 		bottom = stvar->stack_a->tail;
// 		check_top_b(stvar);
// 		ft_printf(YEL"|i:%i bottom:%i part_id:%i bottom->index:%i|\n"RESET, i, bottom->num, bottom->part_id, bottom->index);
// 		if (top->part_id == i || bottom->part_id == i)
// 		{
// 			do_op(stvar, (instr = PB), 'b', 1);
// 			if (top->part_id == i && bottom->part_id == i)
// 			{
// 				ft_printf(CYN"OPTION 1\n"RESET);
// 				if (j != 1)
// 					res = calc_shortest_dist_top(stvar, top, bottom);
// 				sort_top_bottom(stvar, res, top, bottom);
// 				// print_stack_list(stvar->stack_b, 'b');
// 			}
// 			else if (bottom->part_id == i)
// 			{
// 				ft_printf(BLU"OPTION 2\n"RESET);
// 				sort_bottom(stvar, bottom);
// 			}
// 			// print_stack_list(stvar->stack_b, 'b');
// 		}
// 		else if (top->part_id != i && bottom->part_id != i)
// 		{
// 			ft_printf(RED"OPTION 3\n"RESET);
// 			find_part(stvar, i);
// 			instr = PB;
// 			// print_stack_list(stvar->stack_b, 'b');
// 		}
// 		// ft_printf("instr:%s\n", instr);
// 	}
// 	j -= 1;
// 	ft_printf("\n\n");
// }