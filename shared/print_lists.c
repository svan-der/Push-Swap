/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_lists.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 18:17:07 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:39:44 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"

void	print_inst(t_inst *instr)
{
	t_inst	*temp;

	temp = instr;
	while (temp != NULL)
	{
		ft_putstr_fd(temp->operation, 1);
		ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}
