/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:44:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/14 17:16:00 by svan-der      ########   odam.nl         */
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
			return (error_handler(0));
		i++;
	}
	// print(&stvar.stack_a, &stvar.stack_b);
	get_instruction(&stvar);
	// print_stack(stvar.stack_a, 1);
	// print_stack_b(stvar.stack_b, 1);
	t_stack *temp;

	temp = stvar.stack_b;
	ft_printf("prev adress: %p\n", temp->prev);
	ft_printf("addres:%p\n", temp);
	ft_printf("adress after:%p\n", temp->next);
	free_inst_list(&(stvar).inst_lst);
	free_stack_list(&(stvar).stack_a, &(stvar).stack_b);
	return (1);
}
