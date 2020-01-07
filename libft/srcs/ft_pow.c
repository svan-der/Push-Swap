/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 17:10:10 by svan-der       #+#    #+#                */
/*   Updated: 2019/12/10 17:14:29 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

t_u128	ft_pow(t_u128 n, t_u128 pow)
{
	t_u128 i;

	if (pow == 0)
		return (1);
	if (pow % 2 == 0)
	{
		i = ft_pow(n, pow / 2);
		return (i * i);
	}
	else
		return (n * ft_pow(n, pow - 1));
}
