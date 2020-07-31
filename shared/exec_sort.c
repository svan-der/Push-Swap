/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 11:56:55 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/30 14:58:28 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"
#include "../includes/push_swap.h"

static void	update_size(t_pw_var *stvar, char *str, int instr)
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

int			dispatch_sort(t_pw_var *stvar, char *str, int instr)
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
