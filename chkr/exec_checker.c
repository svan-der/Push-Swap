/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:34:26 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/18 10:17:53 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/psw_env.h"

int		check_instruction(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strequ(line, "sa"))
		return (swap_a(stack_a));
	if (ft_strequ(line, "sb"))
		return (swap_b(stack_b));
	if (ft_strequ(line, "ss"))
		return (swap_ss(stack_a, stack_b));
	if (ft_strequ(line, "pa"))
		return (push_a(stack_a, stack_b));
	if (ft_strequ(line, "pb"))
		return (push_b(stack_a, stack_b));
	if (ft_strequ(line, "ra"))
		return (rotate_a(stack_a));
	if (ft_strequ(line, "rb"))
		return (rotate_b(stack_b));
	if (ft_strequ(line, "rr"))
		return (rotate_rr(stack_a, stack_b));
	if (ft_strequ(line, "rra"))
		return (rotate_reva(stack_a));
	if (ft_strequ(line, "rrb"))
		return (rotate_revb(stack_b));
	if (ft_strequ(line, "rrr"))
		return (rotate_rr(stack_a, stack_b));
	else if (ft_strequ(line, ""))
		return (0);
	return (-1);
}

int		get_instruction(t_pw_var *stvar)
{
	char	*line;
	int		ret;
	int		valid;

	ret = 1;
	line = NULL;
	stvar->inst_lst = NULL;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		valid = check_instruction(&stvar->stack_a, &stvar->stack_b, line);
		put_instruction(&(*stvar).inst_lst, line);
		free(line);
		line = NULL;
		if (ret == -1 || valid == -1)
			return (-1);
		if (ret == 0 || valid == 0)
			break ;
	}
	// print_stack_list(stvar->stack_a, 'a');
	// print_instructions(stvar->inst_lst, ret);
	ret = check_sorted(&stvar->stack_a, &stvar->stack_b);
	return (ret);
}
