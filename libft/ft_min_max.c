/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min_max.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
<<<<<<< HEAD
/*   Created: 2019/11/11 18:44:52 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 16:56:44 by svan-der      ########   odam.nl         */
=======
/*   Created: 2019/11/11 18:44:52 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/11 18:45:11 by svan-der      ########   odam.nl         */
>>>>>>> parent of eb144b2... Modified Makefile and add README file
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

t_ull		ft_max_size(t_ull a, t_ull b)
{
	return (a > b ? a : b);
}

t_llong		ft_max(t_llong a, t_llong b)
{
	return (a > b ? a : b);
}

t_ull		ft_min_size(t_ull a, t_ull b)
{
	return (a < b ? a : b);
}

t_llong		ft_min(t_llong a, t_llong b)
{
	return (a < b ? a : b);
}
