/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_lists.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 18:17:07 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/06 10:41:15 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/psw_env.h"
#include "../includes/push_swap.h"

void				print_input_list(t_list *argv)
{
	t_list *temp;

	temp = argv;
	printf("\n      Linked List with input numbers      \n");
	printf("-----------------------------------------\n");
	printf("|input_num\t\t\tnext_input_num|\n");
	printf("|-------------------------------");
	printf("-----|\n");
	while (temp != NULL)
	{
		printf("|%p\t\t", temp->content);
		if (temp->next != NULL)
			printf("\t-> %p\t|\n", temp->next->content);
		else
			printf("\t-> NULL\t|\n");
		temp = temp->next;
	}
	printf("----------------------------------------\n");
}

void				print_inst_list(t_inst *instr)
{
	t_inst			*temp;

	temp = instr;
	printf("\n      Linked List with instructions       \n");
	printf("-----------------------------------------\n");
	printf("|operation\t\tail\n");
	printf("|-------------------------------");
	printf("-----|\n");
	while (temp != NULL)
	{
		printf("|%s\t\t%s\t", temp->operation, temp->tail->operation);
		temp = temp->next;
	}
	printf("----------------------------------------\n");
}

void				print_stack_list(t_stack *stack)
{
	t_stack			*temp;

	temp = stack;
	printf("\n      Linked List with stack numbers       \n");
	printf("-----------------------------------------\n");
	printf("|stack_num\t\t\ttail_num|\n");
	printf("|-------------------------------");
	printf("-----|\n");
	while (temp != NULL)
	{
		printf("|%i\t\t", *temp->num);
		// printf("|%i\t\t", *temp->tail);
		// if (temp->next != NULL)
		// 	printf("\t-> %i\t|\n", *temp->next->num);
		// else
		// 	printf("\t-> NULL\t|\n");
		temp = temp->next;
	}
	printf("----------------------------------------\n");
}

// void				print_stack_list(t_stack *stack)
// {
// 	t_stack 		*temp;

// 	temp = stack;
// 	printf("\n           Linked List with stack numbers        \n");
// 	printf("-----------------------------------------------------");
// 	printf("--------------------\n");
// 	printf("|room_name\troom_x_coord\troom_y_coord\troom_position\t");
// 	printf("next_room|\n");
// 	while (temp != NULL)
// 	{
// 		printf("|%s\t\t%d\t\t%d", temp->name, temp->x_coord, temp->y_coord);
// 		printf("\t\t%d\t\t", temp->position);
// 		if (temp->next != NULL)
// 			printf("%s\t|\n", temp->next->name);
// 		else
// 			printf("NULL\t|\n");
// 		temp = temp->next;
// 	}
// 	printf("------------------------------------");
// 	printf("------------------------------------\n");
// }

void				print_pw_var(t_pw_var *stvar)
{
	t_pw_var		*temp;

	printf("\n           All pw_VAR        \n");
	printf("-----------------------------------");
	printf("---------------------\n");
	printf("|argc\tindex\tsort_index\tmedian\ttotal_ins\n");
	temp = stvar;
	while (stvar->argc != 0)
	{
		printf("|%d\t\t\t", temp->argc);
		printf("%d\t\t", temp->index);
		printf("%d\t\t|\n", temp->sort_index);
		printf("%d\t\t|\n", temp->median);
		printf("%d\t\t|\n", temp->total_ins);
		temp->argc -= 1;
	}
	printf("------------------------------------");
	printf("--------------------\n");
}

void				print_partition_list(t_part *partition)
{
	t_part			*temp;
	size_t			i;

	temp = partition;
	printf("\n partition list and the min & max of that partition \n");
	printf("--------------------------\n");
	printf("|part_num\tmax\tmin\npart_len\n");
	i = 0;
	while (temp != NULL)
	{
		printf("%i\t\t", *temp->parts);
		printf("%i->", temp->max);
		printf("%i", temp->min);
		printf("%zu", temp->len);
		temp = temp->next;
	}
	printf("-------------------------\n");
}
