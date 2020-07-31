/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:34:26 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:16:40 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		execute_instruction(t_pw_var *stvar)
{
	int				ret;
	t_inst			*temp;
	t_operates		func_arr[10];

	temp = stvar->inst_lst;
	ret = 1;
	initialize_operations(func_arr);
	while (temp != NULL)
	{
		ret = func_arr[temp->option](stvar);
		temp = temp->next;
		if (ret == -1)
			error_handling(stvar, NULL, -1);
	}
	return (ret);
}

void	get_instruction(t_pw_var *stvar)
{
	char	*line;
	int		ret;
	int		valid;
	t_sort	index;

	ret = 1;
	valid = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		check_instruction(&index, line, &valid);
		if (ret < 1 || valid < 1)
		{
			if (ret == -1 || valid == -1)
				error_handling(stvar, line, -1);
			break ;
		}
		ret = put_instruction(&stvar->inst_lst, index, line);
		ft_strdel(&line);
		index = 0;
		if (ret == -1 || valid == -1)
			error_handling(stvar, line, -1);
	}
	if (ret >= 0 && valid >= 0)
		execute_instruction(stvar);
}
