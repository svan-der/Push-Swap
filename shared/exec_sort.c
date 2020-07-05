/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 11:56:55 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/05 16:57:03 by svan-der      ########   odam.nl         */
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
	// ft_printf("|\e[1;35m inst:%s\t\e[1;33m total:%i -> \e[1;32m %i|\n"RESET, str, stvar->total_ins - instr, stvar->total_ins);
	// ft_printf("stvar->index:%i\n", stvar->index);
// 	ft_printf("stvar->sort_index:%i\n", stvar->index);
}

int 	dispatch_sort(t_pw_var *stvar, char *str, int instr)
{
	t_sort 			index;
	t_operates		func_arr[10];
	int ret;
	int res;

	ret = 1;
	// index == sa;
	while (str != NULL && instr)
	{
		// ft_printf("str is:%s\n", str);
		// ft_printf("instr is:%i\n", instr);
		check_instruction(&index, str, &ret);
		// ft_printf("ret is:%d\n", index);
		res = put_instruction(&(stvar)->inst_lst, index, str);
		// ft_printf("temp->option:%i\n", stvar->inst_lst->option);
		// ft_printf("res is:%d\n", res);
		// print_inst_list(stvar->inst_lst);
		initialize_operations(func_arr);
		// ft_printf("index:%i\n", index);
		ret = func_arr[index](stvar);
		// ft_printf("return funct is:%d\n", ret);
		update_size(stvar, str, instr);
		instr -= 1;
	}
	// ft_printf("return is:%d\n\n", ret);
	if (ret == -1 || res == -1)
	{
		error_handler(-1);
		return (ft_exit(stvar));
	}
	// ft_printf("%s\n", str);
	return (1);
}
