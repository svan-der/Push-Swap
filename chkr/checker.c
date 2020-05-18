/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:44:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/18 11:14:56 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/ft_printf.h"

int		main(int argc, char **argv)
{
	t_pw_var	stvar;
	int			valid;
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
		valid = check_argv(str, &stvar);
		// ft_printf("Valid is:%d\n", valid);
		if (valid == -1)
		{
			error_handler(valid);
			return (ft_exit(&stvar));
		}
		i++;
	}
	valid = check_dup(&(stvar.stack_a));
	print_stack_list(stvar.stack_a, 'a');
	// ft_printf("valid is:%d\n", valid);
	// print_stack_list(stvar.stack_a, 'a');
	if (valid == -1)
	{
		error_handler(valid);
		return (ft_exit(&stvar));
	}
	ret = get_instruction(&stvar);
	if (ret != 1)
		error_handler(ret);
	if (ret == 1)
		ft_printf("OK\n");
	ft_exit(&stvar);
	return (1);
}
