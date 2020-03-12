/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_opts.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 11:22:12 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/12 13:14:28 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void sort_three_opt1(t_format *stvar, t_stack *stack, int min, int max)
// {
// 	if ((*stack->next->num) == max)
// 	{
// 		rotate_b(&stack);
// 		push_b(&stack, &stvar->stack_a);
// 		push_b(&stack, &stvar->stack_a);
// 		rotate_revb(&stack);
// 		push_b(&stack, &stvar->stack_a);
// 		stvar->total_ins += 5;
// 	}
// 	else
// 	{
// 		rotate_b(&stack);
// 		rotate_b(&stack);
// 		push_b(&stack, &stvar->stack_a);
// 		rotate_revb(&stack);
// 		push_b(&stack, &stvar->stack_a);
// 		rotate_revb(&stack);
// 		push_b(&stack, &stvar->stack_a);
// 		stvar->total_ins += 7;
// 	}
// }