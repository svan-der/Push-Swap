/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:52:42 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/22 09:43:05 by svan-der      ########   odam.nl         */
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

int		*lst_cpy(t_stack **stack, int *new_list)
{
	t_stack *current;
	int		i;
	int		j;

	current = *stack;
	i = 0;
	j = 0;
	// ft_printf("current->num:%d\n", current->num);
	while (current->next != NULL)
	{
		new_list[i] = (current->num);
		current = current->next;
		i++;
	}
	// ft_printf("current prev is:%p\n", current->prev);
	// ft_printf("current is:%p\n", current);
	new_list[i] = current->num;
	// current->prev->prev = NULL;
	// current->next = NULL;
	add_tail(stack);
	// (*stack)->tail = current;
	// (*stack)->tail->prev = current->prev;
	// ft_printf("tail->prev is:%p\n", (*stack)->tail->prev);
	// ft_printf("tail is:%p\n", (*stack)->tail);
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

void		add_tail(t_stack **stack)
{
	t_stack *tail;
	t_stack *prev_tail;

	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = NULL;
	tail->prev = tail->prev;
	// tail->prev->prev = NULL;
	(*stack)->tail = tail;
	// ft_printf("tail is:%d\n", (*stack)->tail->num);
	// ft_printf("tail is:%d\n", tail->num);
	// ft_printf("tail->prev is:%d\n", tail->prev->num);
	// ft_printf("tail->prev is:%d\n", (*stack)->tail->prev->num);
	// ft_printf("tail->prev is:%p\n", (*stack)->tail->prev);
	// ft_printf("tail->prev is:%p\n", (*stack)->tail->prev);
	// ft_printf("tail next is:%p\n", tail->next);
	// ft_printf("tail prev prev is:%p\n", tail->prev->prev);
}

/*
** function sets for unsorted list the right index per number
*/

int				set_index(t_stack **stack_a, int *sorted, int argc)
{
	int		i;
	int 	j;
	t_stack *temp;

	i = 0;
	j = 0;
	temp = *stack_a;
	while (argc)
	{
		// ft_printf("sorted num is:%d\n\n", sorted[i]);
		if ((temp)->num == sorted[i])
		{
			(temp)->dist = j - i;
			temp->index = i;
			// ft_printf("number distance is:%d\n\n", (temp)->dist);
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
		// ft_printf("stack num is:%d\n\n", (temp)->num);
		// ft_printf("i is::%d\t j is:%d\n", i, j);
		// ft_printf("stvar->argc is:%d\n", argc);
	}
}

static int		presort_list(t_pw_var *stvar)
{
	int i;

	i = 0;
	stvar->sorted = (int *)malloc(sizeof(int));
	if (stvar->sorted == NULL)
		return (0);
	stvar->sorted = lst_cpy(&(stvar)->stack_a, stvar->sorted);
	// print_array(stvar->sorted, stvar->argc);
	insertion_sort(stvar->sorted, stvar->argc, &stvar->min, &stvar->max);
	set_index(&(stvar)->stack_a, stvar->sorted, stvar->argc);
	// ft_printf("printing tail\n");
	// print_tail(stvar->stack_a->tail);
	return (1);
}

int		run_pw(t_pw_var *stvar)
{
	int ret;

	// print_stack_list(stvar->stack_a, 'a');
	ret = check_sorted(&(stvar->stack_a), &(stvar->stack_b));
	if (ret == 1)
		return (0);
	ret = presort_list(stvar);
	if (ret == 0)
		return (0);
	// print_input_list(stvar->stack_a, stvar->sorted);
	// print_stack_list(stvar->stack_a, 'a');
	// // ft_printf("stvar->argc:%d\n\n", stvar->argc);
	// // ft_printf("min:%d\n", stvar->min);
	// // ft_printf("max:%d\n", stvar->max);
	if (stvar->argc > 3)
		ret = divide_list(stvar);
	else if (stvar->argc != 1)
	{
		// ft_printf("goes in sort three\n");
		ret = sort_three(&stvar->stack_a, stvar, stvar->min, stvar->max);
	}
	// ft_printf("total number of instructions:|%i|\n\n", stvar->total_ins);
	// print_stack_list(stvar->stack_a, 'a');
	// ft_printf("ret is:%d\n", ret);
	return (ret);
}

// void	add_tail(t_stack **stack)
// {
// 	t_stack *temp;

// 	temp = *stack;
// 	while (temp->next != NULL)
// 	{
// 		temp = temp->next;
// 	}
// 	(*stack)->prev = temp;
// }

int		main(int argc, char **argv)
{
	t_pw_var	stvar;
	int			valid;
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
		valid = check_argv(str, &stvar);
		if (valid == -1)
		{
			error_handler(valid);
			return (ft_exit(&stvar));
		}
		i++;
	}
	valid = check_dup(&(stvar.stack_a));
	if (valid == -1)
	{
		error_handler(valid);
		return (ft_exit(&stvar));
	}
	stvar.argc -= 1;
	stvar.index = stvar.argc;
	// print_stack(&stvar.stack_a->tail, 1);
	ret = run_pw(&stvar);
	// print_stack_list(stvar.stack_a, 'a');
	if (ret != 1)
		error_handler(ret);
	print_inst(stvar.inst_lst);
	// print_stack(&stvar.stack_a, 1);
	// ft_printf("total inst:%d\n", stvar.total_ins);
	// print_stack_list(stvar.stack_a, 'a');
	ft_exit(&stvar);
	// print_instructions(stvar.inst_lst, ret);
	// print_stack_list(stvar.stack_b, 'b');
	return (1);
}
