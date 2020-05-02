/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 14:44:57 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/02 18:20:20 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include <stdio.h>

// void	debug(t_stack **stack_a, t_stack **stack_b)
// {
// 	int ret;

// 	print_stack(*stack_a, 1);
// 	print_stack_b(*stack_b, 1);
// 	// rotate_a(stack_a);
// 	// swap_a(stack_a);
// 	// rotate_reva(stack_a);
// 	// rotate_rr(stack_a, stack_b);
// 	// rotate_reva(stack_a);
// 	// rotate_reva(stack_a);
// 	push_b(stack_a, stack_b);
// 	// // rotate_a(stack_a);
// 	push_b(stack_a, stack_b);
// 	rotate_revb(stack_b);
// 	// // push_b(stack_a, stack_b);
// 	// swap_a(stack_a);
// 	// swap_b(stack_b);
// 	rotate_revb(stack_b);
// 	// // push_b(stack_a, stack_b);
// 	// rotate_b(stack_b);
// 	// swap_ss(stack_a, stack_b);
// 	// rotate_rr(stack_a, stack_b);
// 	// push_a(stack_a, stack_b);
// 	// push_a(stack_a, stack_b);
// 	rotate_reva(stack_a);
// 	rotate_reva(stack_a);
// 	// print_stack(*stack_a, 1);
// 	// print_stack_b(*stack_b, 1);
// 	ret = check_sorted(*stack_a, *stack_b);
// 	printf("This is ret after check_sorted:|%d|\n", ret);
// }
// // 	// rotate_rr(stack_a, stack_b);
// // 	// push_b(stack_a, stack_b);
// // 	// rotate_rr(stack_a, stack_b);
// // 	// push_b(stack_a, stack_b);
// // 	// rotate_rr(stack_a, stack_b);
// // 	// push_a(stack_a, stack_b);
// // 	print_stack(*stack_a, 1);
// // 	rotate_reva(stack_a);
// // 	push_b(stack_a, stack_b);
// // 	rotate_revb(stack_b);
// // 	push_b(stack_a, stack_b);
// // 	rotate_reva(stack_a);

int		main(int argc, char **argv)
{
	t_pw_var	stvar;
	char		*str;
	int			ret;
	int			i;
	int 		number;

	i = 1;
	number = 2343;
	// printf("this is the start\n\n");
	printf("you write the number:%d\n\n", number);
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
	// debug(&stvar.stack_a, &stvar.stack_b);
	print_stack(stvar.stack_a, 1);
	print_stack_b(stvar.stack_b, 1);
	// print(&stvar.stack_a, &stvar.stack_b);
	get_instruction(&stvar);
	return (1);
}