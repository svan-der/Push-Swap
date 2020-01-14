/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/14 11:51:38 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

// void	sort_sa()



int		print_error(t_inst *inst_lst)
{
	t_stack *tail;

	while (inst_lst != NULL)
	{
		tail = inst_lst;
		printf("operation: |%s|\n", inst_lst->operation);
		free(inst_lst->operation);
		inst_lst = inst_lst->next;
	}
	printf("Error\n");
	return (1);
}