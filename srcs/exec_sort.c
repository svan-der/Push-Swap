/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
<<<<<<< HEAD
/*   Created: 2020/03/12 11:56:55 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 23:08:40 by svan-der      ########   odam.nl         */
=======
/*   Created: 2020/03/12 11:56:55 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/14 17:25:07 by svan-der      ########   odam.nl         */
>>>>>>> parent of eb144b2... Modified Makefile and add README file
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"
#include "../includes/checker.h"
#include "../includes/push_swap.h"

<<<<<<< HEAD
void 	update_size(t_pw_var *stvar, char *str, int instr)
=======
void update_size(t_format *stvar, char *str, int instr)
>>>>>>> parent of eb144b2... Modified Makefile and add README file
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

<<<<<<< HEAD
int 	dispatch_sort(t_pw_var *stvar, char *str, int instr)
=======
int dispatch_sort(t_format *stvar, char *str, int instr)
>>>>>>> parent of eb144b2... Modified Makefile and add README file
{
	int ret;

	ret = check_instruction(&stvar->stack_a, &stvar->stack_b, str);
	if (ret == -1)
		return (error_handler(2));
	update_size(stvar, str, instr);
	return (1);
}
