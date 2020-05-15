/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:44:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/15 13:53:04 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/ft_printf.h"

int		main(int argc, char **argv)
{
	t_pw_var	stvar;
	char		*str;
	int			ret;
	int			i;

	i = 1;
	ft_bzero(&stvar, sizeof(t_pw_var));
	stvar.argc = argc;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		str = argv[i];
		ret = check_argv(str, &stvar);
		if (ret == -1)
			return (error_handler(ret));
		i++;
	}
	ret = check_dup(stvar.stack_a);
	ft_printf("ret is:%d\n", ret);
	// ret = get_instruction(&stvar);
	// // if (ret == -1)
	// // 	error_handler(0);
	// // print_stack_list(stvar.stack_a, 'a');
	// free_inst_list(&(stvar).inst_lst);
	// free_stack_list(&(stvar).stack_a, &(stvar).stack_b);
	return (1);
}
