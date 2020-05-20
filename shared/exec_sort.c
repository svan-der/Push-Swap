/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 11:56:55 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/20 17:27:51 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

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
	int res;

	ret = 0;
	if (str != NULL)
	{
		// ft_printf("put instr\n");
		res = put_instruction(&(stvar)->inst_lst, str);
		// ft_printf("ret is:%d\n", ret);
		// ft_printf("str is:%s\n", str);
		ret = check_instruction(&stvar->stack_a, &stvar->stack_b, str);
		// ft_printf("ret is:%d\n", ret);
	}
	// ft_printf("return is:%d\n\n", ret);
	if (ret == -1 || res == -1)
		return (error_handler(ret));
	// ft_printf("%s\n", str);
	update_size(stvar, str, instr);
	return (1);
}
