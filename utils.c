/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:32:31 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/14 19:29:47 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

int		sort_sa(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *temp;

	(void)stack_b;
	temp = stack_a->next;
	// printf("sort list:|%d|\n", stack_a->next->num);
	printf("sort list:|%d|\n", temp->num);
	// printf("sort list:|%d|\n", temp->next->num);
	stack_a->next = temp->next;
	printf("sort list:|%d|\n", stack_a->num);
	temp->next = stack_a;
	printf("sort list:|%d|\n", temp->num);
	stack_a = temp;
	printf("sort list:|%d|\n", stack_a->num);
	print_stack(stack_a, 1);
	return (1);
}



// void	sort_and_check(t_inst *inst_lst, int ret)
// {
	
// }





// void	sort_sa()

// void	sort_sa()

// void	sort_pa()

// void	sort_pa()

// void	sort_ra()


// if (ft_strequ(line, "sa"))
// 		return (1);
// 	if (ft_strequ(line, "sb"))
// 		return (1);
// 	if (ft_strequ(line, "ss"))
// 		return (1);
// 	if (ft_strequ(line, "pa"))
// 		return (1);
// 	if (ft_strequ(line, "pb"))
// 		return (1);
// 	if (ft_strequ(line, "ra"))
// 		return (1);
// 	if (ft_strequ(line, "rb"))
// 		return (1);
// 	if (ft_strequ(line, "rr"))
// 		return (1);
// 	if (ft_strequ(line, "rra"))
// 		return (1);
// 	if (ft_strequ(line, "rrb"))
// 		return (1);
// 	if (ft_strequ(line, "rrr"))