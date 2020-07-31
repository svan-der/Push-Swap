/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:52:42 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:28:14 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_min_maxarray(t_pw_var *stvar, int *list, int len)
{
	int i;

	i = 0;
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

static int	*lst_cpy(t_pw_var *stvar)
{
	t_stack *current;
	int		i;

	current = stvar->stack_a;
	i = 0;
	while (current != NULL)
	{
		stvar->sorted[i] = current->num;
		current = current->next;
		i++;
	}
	return (stvar->sorted);
}

static int	presort_list(t_pw_var *stvar)
{
	stvar->sorted = (int *)malloc(stvar->argc * sizeof(int));
	if (stvar->sorted == NULL)
		return (0);
	stvar->sorted = lst_cpy(stvar);
	insertion_sort(stvar->sorted, stvar->argc);
	set_index(&(stvar)->stack_a, stvar->sorted, stvar->argc);
	set_min_maxarray(stvar, stvar->sorted, stvar->argc);
	stvar->median = find_median_array(stvar->sorted, stvar->index);
	return (1);
}

int			run_pw(t_pw_var *stvar)
{
	int ret;

	stvar->argc -= 1;
	stvar->index = stvar->argc;
	ret = check_sorted(&(stvar->stack_a), &(stvar->stack_b));
	if (ret == 1)
		return (0);
	ret = presort_list(stvar);
	if (ret == 0)
		return (0);
	if (stvar->argc > 0 && stvar->argc < 6)
		sort_short_opts(stvar);
	else if (stvar->argc > 3)
		ret = divide_list(stvar, stvar->argc, stvar->index);
	return (ret);
}

int			main(int argc, char **argv)
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
		check_argv(str, &stvar);
		i++;
	}
	ret = check_dup(&(stvar.stack_a));
	if (ret == -1)
		error_handling(&stvar, NULL, ret);
	ret = run_pw(&stvar);
	if (ret == -1)
		error_handling(&stvar, NULL, ret);
	print_inst(stvar.inst_lst);
	ft_exit(&stvar, 0);
}
