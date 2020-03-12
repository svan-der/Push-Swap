/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 11:56:55 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/12 18:04:53 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "psw_env.h"
#include "push_swap.h"

void update_size(t_format *stvar, char *str, int instr)
{
	int mod;

	mod = 0;
	if (ft_strequ(str, "pb"))
		mod = -1;
	if (ft_strequ(str, "pa"))
		mod = 1;
	stvar->index += mod;
	stvar->sort_index = stvar->index;
	stvar->total_ins += instr;
}

int dispatch_sort(t_format *stvar, char *str, int instr)
{
	int ret;

	ret = check_instruction(&stvar->stack_a, &stvar->stack_b, str);
	if (ret == -1)
		return (error_handler(2));
	update_size(stvar, str, instr);
	return (1);
}
