/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:44:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/21 04:23:13 by svan-der      ########   odam.nl         */
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
		if (valid == -1)
		{
			error_handler(valid);
			return (ft_exit(&stvar));
		}
		i++;
	}
	valid = check_dup(&(stvar.stack_a));
	// print_stack_list(stvar.stack_a, 'a');
	// ft_printf("valid is:%d\n", valid);
	// print_stack_list(stvar.stack_a, 'a');
	if (valid == -1)
	{
		error_handler(valid);
		return (ft_exit(&stvar));
	}
	ret = get_instruction(&stvar);
	ft_printf("ret is:%d\n", ret);
	// ft_putstr_fd("ret is s", 2);
	if (ret == -1)
	{
		error_handler(ret);
		return (ft_exit(&stvar));
	}
	ret = check_sorted(&stvar.stack_a, &stvar.stack_b);
	// ft_putstr_fd("ret\n", 1);
	// print_stack(&stvar.stack_a, 1);
	if (ret == 1)
		ft_putstr_fd("OK\n", 1);
	else
		error_handler(ret);
	ft_exit(&stvar);
	return (1);
}
