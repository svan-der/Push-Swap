/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:15:26 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/23 16:35:03 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int     rotate_a(t_stack **stack_a)
{
    t_stack *temp;

    printf("in rotate a function\n");
    temp = *stack_a;
    printf("this is tail:%d", temp->tail->num);
    // while (temp->next != NULL)
    //     temp = temp->next;
    return (1);
}