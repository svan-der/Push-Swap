/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 14:55:23 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 16:57:23 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mathlib.h"

long double	ft_ldabs(long double n)
{
	return (n < 0 ? -n : n);
}

double		ft_dabs(double n)
{
	return (n < 0 ? -n : n);
}

t_ull		ft_abs(t_llong n)
{
	return (n < 0 ? -n : n);
}
