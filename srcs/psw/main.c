/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:10:20 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/25 19:01:46 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "psw_env.h"
#include "checker.h"

// void	debug(t_format *stvar)
// {
// 	int *list;
	
// 	list = (int *)malloc(sizeof(int));
// 	list = lst_cpy(stvar->stack_a, list);
// 	insertion_sort(list, stvar->argc, &stvar->min, &stvar->max);
// 	stvar->median = find_median_array(list, stvar->index);
// 	set_min_maxarray(stvar, list, stvar->argc);
// 	conquer_list(stvar, list);
	// sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
	// check_instruction(&stvar->stack_a, &stvar->stack_b, SA);
	// int ret;
	// static t_opt f_stacks = {push_a, push_b, swap_ss, rotate_rr};
	// static t_opt f_stack = {swap_a, swap_b, rotate_a, rotate_b, rotate_revb, rotate_reva};

	// ret = f_stacks.arr_ds[pb](&stvar->stack_a, &stvar->stack_b); 
	// ret = ft_stack.arr_os[]()
	// dispatch_sort(stvar, );
// }

int		pw_check(t_format *stvar, t_stack *stack_a)
{
	int		check;

	check = 1;
	stvar->min = *stack_a->num;
	stvar->max = *stack_a->num;
	while (stack_a != NULL && stack_a->next != NULL)
	{
		if (stvar->min > *stack_a->num)
			stvar->min = *stack_a->num;
		if (stvar->max < *stack_a->num)
			stvar->max = *stack_a->num;
		if (*stack_a->num > *stack_a->next->num)
			check = -1;
		stack_a = stack_a->next;
	}
	return (check);
}

int		push_swap(t_format *stvar)
{
	int	ret;

	ret = pw_check(stvar, stvar->stack_a);
	if (ret == 1)
		return (print_stack(stvar->stack_a, ret));
	ret = run_pw(stvar);
	if (ret == 0)
		return (-1);
	return (print_stack(stvar->stack_a, 1));
}

// int		main(int argc, char **argv)
// {
// 	t_format	stvar;
// 	char		*str;
// 	int			ret;
// 	int			i;

// 	i = 1;
// 	ft_bzero(&stvar, sizeof(t_format));
// 	stvar.argc = argc;
// 	if (argc < 2)
// 		return (0);
// 	while (i < argc)
// 	{
// 		str = argv[i];
// 		ret = check_argv(str, &stvar);
// 		if (ret == -1)
// 			return (error_handler(0));
// 		i++;
// 	}
// 	// debug(&stvar);
// 	print_stack(stvar.stack_a, 1);
// 	print_stack_b(stvar.stack_b, 1);
// 	stvar.argc -= 1;
// 	stvar.index = stvar.argc;
// 	push_swap(&stvar);
// 	return (1);
// }
