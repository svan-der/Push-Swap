/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:52:42 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/06 10:57:50 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/psw_env.h"
#include <stdio.h>

void print_array(int *list, int argc)
{
	int i;

	i = 0;
	while (i < argc)
	{
		printf("this is number:%i\n", list[i]);
		i++;
	}
}

void	set_min_maxarray(t_pw_var *stvar, int *list, int len)
{
	int i;
	int num;

	i = 0;
	num = list[i];
	stvar->min = list[i];
	stvar->max = list[i];
	while (i < len)
	{
		if (stvar->min > list[i])
			stvar->min = list[i];
		if (stvar->max < list[i])
			stvar->max = list[i];
		i++;
	}
}

// void	set_min_max(t_part *part_var)
// {
// 	int i;
// 	int	len;

// 	i = 0;
// 	len = (int)part_var->len;
// 	part_var->min = 0;
// 	part_var->max = 0;
// 	while (i < len)
// 	{
// 		if (part_var->min > part_var->parts[i] || !part_var->min)
// 			part_var->min = part_var->parts[i];
// 		if (part_var->max < part_var->parts[i] || !part_var->max)
// 			part_var->max = part_var->parts[i];
// 		i++;
// 	}
// }

int find_median_array(int *list, int index)
{
	int i;
	double j;
	int median;

	j = (double)index / 2;
	i = j;
	median = list[i];
	print_array(list, index);
	return (median);
}

int *lst_cpy(t_stack *stack, int *new_list)
{
	t_stack *current;
	int i;
	int j;

	current = stack;
	i = 0;
	j = 0;
	while (current != NULL)
	{
		new_list[i] = (*current->num);
		current = current->next;
		i++;
	}
	return (new_list);
}

void *ft_calloc(size_t count, size_t size)
{
	void *res;

	res = (char *)malloc(size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

int run_pw(t_pw_var *stvar)
{
	if (stvar->argc > 3)
		divide_list(stvar);
	// else
	// 	sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
	// sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
	printf("total number of instructions:|%i|\n\n", stvar->total_ins);
	return (1);
}

int		main(int argc, char **argv)
{
	t_pw_var	stvar;
	char		*str;
	int			ret;
	int			i;

	i = 1;
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
	// debug(&stvar);
	print_stack(stvar.stack_a, 1);
	print_stack_b(stvar.stack_b, 1);
	stvar.argc -= 1;
	stvar.index = stvar.argc;
	run_pw(&stvar);
	// push_swap(&stvar);
	return (1);
}
