/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 11:56:55 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:13:47 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void		update_size(t_pw_var *stvar, char *str, int instr)
{
	int			mod;

	mod = 0;
	if (ft_strequ(str, "pb"))
		mod = -1;
	if (ft_strequ(str, "pa"))
		mod = 1;
	stvar->index += mod;
	stvar->sort_index = stvar->index;
	stvar->total_ins += instr;
}

int				dispatch_sort(t_pw_var *stvar, char *str, int instr)
{
	t_sort		index;
	t_operates	func_arr[10];
	int			ret;
	int			res;

	ret = 1;
	while (str != NULL && instr)
	{
		check_instruction(&index, str, &ret);
		res = put_instruction(&(stvar)->inst_lst, index, str);
		initialize_operations(func_arr);
		ret = func_arr[index](stvar);
		update_size(stvar, str, instr);
		instr -= 1;
	}
	if (ret == -1 || res == -1)
		error_handling(stvar, str, -1);
	return (1);
}

void			initialize_operations(t_operates function_array[10])
{
	function_array[0] = swap_a;
	function_array[1] = rotate_a;
	function_array[2] = rotate_reva;
	function_array[3] = swap_b;
	function_array[4] = rotate_b;
	function_array[5] = rotate_revb;
	function_array[6] = swap_ss;
	function_array[7] = rotate_rr;
	function_array[8] = rotate_rrr;
	function_array[9] = push_a;
	function_array[10] = push_b;
}

void			check_instruction(t_sort *option, char *line, int *valid)
{
	if (ft_strequ(line, SA))
		*option = sa;
	else if (ft_strequ(line, RA))
		*option = ra;
	else if (ft_strequ(line, RRA))
		*option = rra;
	else if (ft_strequ(line, SB))
		*option = sb;
	else if (ft_strequ(line, SS))
		*option = ss;
	else if (ft_strequ(line, PA))
		*option = pa;
	else if (ft_strequ(line, PB))
		*option = pb;
	else if (ft_strequ(line, RB))
		*option = rb;
	else if (ft_strequ(line, RR))
		*option = rr;
	else if (ft_strequ(line, RRB))
		*option = rrb;
	else if (ft_strequ(line, RRR))
		*option = rrr;
	else
		*valid = (ft_strequ(line, "")) ? 0 : -1;
}
