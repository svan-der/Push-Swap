/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_lists.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 18:17:07 by svan-der      #+#    #+#                 */
/*   Updated: 2020/06/09 13:12:44 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/psw_env.h"
#include "../includes/push_swap.h"

void	print_array(int *list, int argc)
{
	int i;

	i = 0;
	ft_printf("\nArray sorted\n");
	ft_printf("--------------\n");
	ft_printf("|sorted|\n");
	while (i < argc)
	{
		ft_printf("|%i|\n", list[i]);
		i++;
	}
	ft_printf("--------------\n");
	ft_printf("				 \n");
}

void	print_input_list(t_stack *stack_a, int *list)
{
	int i;
	t_stack *temp;

	i = 0;
	temp = stack_a;
	ft_printf("\nInput list and array\n");
	ft_printf("----------------------\n");
	ft_printf("|input\t\tsorted|\n");
	while (temp != NULL)
	{
		ft_printf("|%d\t-->\t%d|", temp->num, list[i]);
		ft_printf("\n");
		temp = temp->next;
		i++;
	}
	ft_printf("----------------------\n");
	ft_printf("				 		\n");
}


// void				print_input_list(t_list *argv)
// {
// 	t_list *temp;

// 	temp = argv;
// 	ft_printf("\n      Linked List with input numbers      \n");
// 	ft_printf("-----------------------------------------\n");
// 	ft_printf("|input_num\t\t\tnext_input_num|\n");
// 	ft_printf("|-------------------------------");
// 	ft_printf("-----|\n");
// 	while (temp != NULL)
// 	{
// 		ft_printf("|%p\t\t", temp->content);
// 		if (temp->next != NULL)
// 			ft_printf("\t-> %p\t|\n", temp->next->content);
// 		else
// 			ft_printf("\t-> NULL\t|\n");
// 		temp = temp->next;
// 	}
// 	ft_printf("----------------------------------------\n");
// }

void				print_inst(t_inst *instr)
{
	t_inst	*temp;

	temp = instr;
	while (temp != NULL)
	{
		ft_putstr_fd(temp->operation, 1);
		ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}

void				print_inst_list(t_inst *instr)
{
	t_inst			*temp;

	temp = instr;
	// ft_printf("ptr instructions is:%p\n", instr);
	// ft_printf("instruction is:%s\n", instr->operation);
	ft_printf("Linked List with instructions\n");
	ft_printf("-------------------------------\n");
	ft_printf("|operation\tcur\t\tprev\t\tnext\t\t\toption\n");
	ft_printf("--------------------------|\n");
	while (temp != NULL)
	{
		ft_printf("|%s\t\t%p\t%p\t\t%p\t\t\t%d|\n", temp->operation, temp, temp->prev, temp->next, temp->option);
		temp = temp->next;
	}
	ft_printf("-----------\n");
}

void				print_tail(t_stack *tail)
{
	t_stack *temp;

	temp = tail;
	// ft_printf("going to print tail\n");
	// ft_printf("temp->num:%d\n", temp->num);
	ft_printf("\n     Bottom and bottom prev       \n");
	ft_printf("-------------------------------------");
	ft_printf("--------------------\n");
	ft_printf("|tail->prev\t\tnum\ttail\t\tnum|");
	ft_printf("\n");
	while (temp != NULL)
	{
		if (temp->prev)
			ft_printf("|%p\t\t%d\t%p\t%d|", temp->prev, temp->prev->num, temp, temp->num);
		else
		{
			ft_printf("|%p\t\t\t%d\t%p\t%d|", NULL, 0, temp, temp->num);
		}
		ft_printf("\n");
		temp = temp->next;
	}
	ft_printf("------------------------------------");
	ft_printf("------------------------------------\n");
	ft_printf("									   \n");
}

void				print_stack_list(t_stack *stack, char c)
{
	t_stack	*temp;

	temp = stack;
	ft_printf("\n         Linked List with stack_%c numbers       \n", c);
	ft_printf("-----------------------------------------------------");
	ft_printf("--------------------\n");
	ft_printf("|num\tdist\tindex\t\tcurr\t\tprev\t\tnext|");
	ft_printf("\n");
	while (temp != NULL)
	{
		ft_printf("|%d\t%d\t%d\t\t%p\t%p\t%p|", temp->num, temp->dist, temp->index, temp, temp->prev, temp->next);
		ft_printf("\n");
		temp = temp->next;
	}
	ft_printf("------------------------------------");
	ft_printf("------------------------------------\n");
	ft_printf("									   \n");
}

void				print_pw_var(t_pw_var *stvar)
{
	t_pw_var		*temp;

	ft_printf("\n           All pw_VAR        \n");
	ft_printf("-----------------------------------");
	ft_printf("---------------------\n");
	ft_printf("|argc\tindex\tsort_index\tmedian\ttotal_ins\n");
	temp = stvar;
	while (stvar->argc != 0)
	{
		ft_printf("|%d\t\t\t", temp->argc);
		ft_printf("%d\t\t", temp->index);
		ft_printf("%d\t\t|\n", temp->sort_index);
		ft_printf("%d\t\t|\n", temp->median);
		ft_printf("%d\t\t|\n", temp->total_ins);
		temp->argc -= 1;
	}
	ft_printf("------------------------------------");
	ft_printf("--------------------\n");
}

void				print_partition_list(t_part *partition)
{
	t_part			*temp;

	temp = partition;
	ft_printf("\n partition list and the min & max of that partition \n");
	ft_printf("--------------------------\n");
	ft_printf("|part_num\tmax\tmin\npart_len\n");
	while (temp != NULL)
	{
		ft_printf("%i\t\t", *temp->parts);
		ft_printf("%i->", temp->max);
		ft_printf("%i", temp->min);
		ft_printf("%zu", temp->len);
		temp = temp->next;
	}
	ft_printf("-------------------------\n");
}
