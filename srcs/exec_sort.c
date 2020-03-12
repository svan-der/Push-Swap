/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 11:56:55 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/12 15:30:47 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "psw_env.h"
#include "push_swap.h"

void update_size(int *index, int *sort_index, int *total_ins)
{
    *sort_index += 1;
    *total_ins += 1;
    (void)index;
}

int dispatch_sort(t_format *stvar, char *str)
{
    int ret;

    ret = check_instruction(&stvar->stack_a, &stvar->stack_b, str);
    if (ret == -1)
        return (error_handler(2));
    update_size(&stvar->index, &stvar->sort_index, &stvar->total_ins);
    return (1);
}
