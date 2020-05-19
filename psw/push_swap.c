/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:52:42 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/19 13:32:45 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/psw_env.h"


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

int		find_median_array(int *list, int index)
{
	int		i;
	double	j;
	int		median;

	j = (double)index / 2;
	i = j;
	median = list[i];
	// print_array(list, index);
	return (median);
}

int		*lst_cpy(t_stack *stack, int *new_list)
{
	t_stack *current;
	int		i;
	int		j;

	current = stack;
	i = 0;
	j = 0;
	while (current != NULL)
	{
		new_list[i] = (current->num);
		current = current->next;
		i++;
	}
	return (new_list);
}

void	*ft_calloc(size_t count, size_t size)
{
	void *res;

	res = (char *)malloc(size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

// static void		add_tail(t_stack *tail, int *list)
// {
// 	tail->
// 	while (list != 0)
// 	{
// 		tail->num  = list[i]
// 	}
// }

int				set_index(t_stack **stack_a, int *sorted, int argc)
{
	int	i;
	int j;
	t_stack *temp;

	i = 0;
	j = 0;
	temp = *stack_a;
	while (argc)
	{
		ft_printf("sorted num is:%d\n\n", sorted[i]);
		if ((temp)->num == sorted[i])
		{
			(temp)->dist = j - i;
			ft_printf("number distance is:%d\n\n", (temp)->dist);
			if ((temp)->next != NULL)
				(temp) = (temp)->next;
			else
				break ;
			i = 0;
			j += 1;
			argc -= 1;
		}
		else
			i++;
		ft_printf("stack num is:%d\n\n", (temp)->num);
		ft_printf("i is::%d\t j is:%d\n", i, j);
		ft_printf("stvar->argc is:%d\n", argc);
	}
}

static int		presort_list(t_pw_var *stvar)
{
	int i;

	i = 0;
	stvar->sorted = (int *)malloc(sizeof(int));
	if (stvar->sorted == NULL)
		return (0);
	stvar->sorted = lst_cpy(stvar->stack_a, stvar->sorted);
	// add_tail(stvar.tail, stvar->sorted);
	// stvar->tail = stvar->sorted[stvar->argc - 1];
	insertion_sort(stvar->sorted, stvar->argc, &stvar->min, &stvar->max);
	set_index(&(stvar)->stack_a, stvar->sorted, stvar->argc);
	print_array(stvar->sorted, stvar->argc);
	return (1);
}

int		run_pw(t_pw_var *stvar)
{
	int ret;

	// print_stack_list(stvar->stack_a, 'a');
	ret = check_sorted(&(stvar->stack_a), &(stvar->stack_b));
	if (ret == 1)
		return (0);
	presort_list(stvar);
	print_input_list(stvar->stack_a, stvar->sorted);
	print_stack_list(stvar->stack_a, 'a');
	// ft_printf("stvar->argc:%d\n\n", stvar->argc);
	// ft_printf("min:%d\n", stvar->min);
	// ft_printf("max:%d\n", stvar->max);
	// if (stvar->argc > 3)
	// 	divide_list(stvar);
	// else if (stvar->argc != 1)
	// {
	// 	ft_printf("goes in sort three\n");
		// sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
	// }
	// ft_printf("total number of instructions:|%i|\n\n", stvar->total_ins);
	// print_stack_list(stvar->stack_a, 'a');
	return (1);
}

void	add_tail(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	(*stack)->prev = temp;
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
	stvar.argc -= 1;
	stvar.index = stvar.argc;
	print_stack(&stvar.stack_a->tail, 1);
	print_stack_list(stvar.stack_a, 'a');
	ret = run_pw(&stvar);
	if (ret == -1)
		error_handler(0);
	// print_stack_list(stvar.stack_a, 'a');
	// print_stack_list(stvar.stack_b, 'b');
	free_inst_list(&(stvar).inst_lst);
	free_stack_list(&(stvar).stack_a, &(stvar).stack_b);
	free(stvar.sorted);
	// push_swap(&stvar);
	return (1);
}
