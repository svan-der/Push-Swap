/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gridset.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:41:41 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/01 12:33:32 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_gridset(void **grid, char c, size_t y, size_t x)
{
	size_t	i;

	i = 0;
	while (i < y)
	{
		ft_memset(grid[i], c, x);
		i++;
	}
}
