/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:44:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/30 17:07:32 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

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
		check_argv(str, &stvar);
		i++;
	}
	ret = check_dup(&(stvar.stack_a));
	if (ret == -1)
		error_handling(&stvar, NULL, ret);
	get_instruction(&stvar);
	ret = check_sorted(&stvar.stack_a, &stvar.stack_b);
	// print_stack(&(stvar).stack_a, 1);
	if (ret == -1 || ret == 0)
		error_handling(&stvar, NULL, ret);
	ft_exit(&stvar, ret);
}
