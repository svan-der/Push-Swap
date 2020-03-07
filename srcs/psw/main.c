/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:10:20 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/07 23:31:14 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug(t_format *stvar)
{
	int ret;
	int *numb;

	numb = (int *)malloc(sizeof(int));
	*numb = 20;
	stvar->stack_a->num = numb;
	ft_stackpop(&stvar->stack_a, stvar->stack_a);
}
// 	// rotate_rr(stack_a, stack_b);
// 	// push_b(stack_a, stack_b);
// 	// rotate_rr(stack_a, stack_b);
// 	// push_b(stack_a, stack_b);
// 	// rotate_rr(stack_a, stack_b);
// 	// push_a(stack_a, stack_b);
// 	print_stack(*stack_a, 1);
// 	rotate_reva(stack_a);
// 	push_b(stack_a, stack_b);
// 	rotate_revb(stack_b);
// 	push_b(stack_a, stack_b);
// 	rotate_reva(stack_a);

int		pw_check(t_format *stvar)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		check;

	stack_a = stvar->stack_a;
	stack_b = stvar->stack_b;
	print_stack(stack_a, 1);
	print_stack_b(stack_b, 1);
	check = 1;
	stvar->min = stack_a->num;
	while (stack_a != NULL && stack_a->next != NULL)
	{
		printf("this is num: %i\n", stack_a->num);
		printf("this is num next: %i\n", stack_a->next->num);
		if (stvar->min > stack_a->num)
			stvar->min = stack_a->num;
		if (stvar->max < stack_a->num)
			stvar->max = stack_a->num;
		if (stack_a->num > stack_a->next->num)
			check = -1;
		stack_a = stack_a->next;
	}
	return (check);
}

int		push_swap(t_format *stvar)
{
	int ret;

	ret = pw_check(stvar);
	if (ret == 1)
		return (print_stack(stvar->stack_a, ret));
	ret = run_pw(stvar);
	if (ret == 0)
		return (-1);
	return (print_stack(stvar->stack_a, 1));
}

int		main(int argc, char **argv)
{
	t_format	stvar;
	char		*str;
	int			ret;
	int			i;

	i = 1;
	ft_bzero(&stvar, sizeof(t_format));
	stvar.argc = argc;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		str = argv[i];
		ret = check_argv(str, &stvar);
		if (ret == -1)
			return (print_stack(stvar.stack_a, ret));
		i++;
	}
	// debug(&stvar);
	print_stack(stvar.stack_a, 1);
	print_stack_b(stvar.stack_b, 1);
	stvar.argc -= 1;
	stvar.index = stvar.argc;
	push_swap(&stvar);
	return (1);
}
