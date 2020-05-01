/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intround.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 16:51:53 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/13 16:53:07 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

int		int_round(double n)
{
	double	res;
	int		num;

	if (n < 0)
		n = n * -1;
	num = n;
	res = n - num;
	res *= 2;
	if (res >= 1)
		return (n + 0.5);
	return (n);
}
