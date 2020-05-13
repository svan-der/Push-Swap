/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 11:56:55 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/13 10:56:37 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"
#include <stdio.h>
// #include "../includes/push_swap.h"

void 	update_size(t_pw_var *stvar, char *str, int instr)
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

int 	dispatch_sort(t_pw_var *stvar, char *str, int instr)
{
	int ret;

	ret = 0;
	if (str != NULL)
		ret = check_instruction(&stvar->stack_a, &stvar->stack_b, str);
	printf("return is:%d\n\n", ret);
	if (ret == -1)
		return (error_handler(2));
	update_size(stvar, str, instr);
	return (1);
}
