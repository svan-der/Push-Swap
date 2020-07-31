/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:34:26 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/30 14:58:06 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"
#include "../includes/push_swap.h"

void	initialize_operations(t_operates function_array[10])
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

int		execute_instruction(t_pw_var *stvar)
{
	int				ret;
	t_inst			*temp;
	t_operates		func_arr[10];

	temp = stvar->inst_lst;
	ret = 1;
	initialize_operations(func_arr);
	while (temp != NULL)
	{
		ret = func_arr[temp->option](stvar);
		temp = temp->next;
		if (ret == -1)
			error_handling(stvar, NULL, -1);
	}
	return (ret);
}

void	check_instruction(t_sort *option, char *line, int *valid)
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

void	get_instruction(t_pw_var *stvar)
{
	char	*line;
	int		ret;
	int		valid;
	t_sort	index;

	ret = 1;
	valid = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		check_instruction(&index, line, &valid);
		if (ret < 1 || valid < 1)
		{
			if (ret == -1 || valid == -1)
				error_handling(stvar, line, -1);
			break ;
		}
		ret = put_instruction(&stvar->inst_lst, index, line);
		ft_strdel(&line);
		index = 0;
		if (ret == -1 || valid == -1)
			error_handling(stvar, line, -1);
	}
	if (ret >= 0 && valid >= 0)
		execute_instruction(stvar);
}
