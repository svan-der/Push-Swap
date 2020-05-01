/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 15:48:35 by svan-der       #+#    #+#                */
/*   Updated: 2019/12/21 17:14:24 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mathlib.h"

size_t	ft_count_num(t_llong num)
{
	size_t	len;

	if (num < 0)
		num = num * -1;
	len = 1;
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		s;
	int		i;
	size_t	len;

	s = (n < 0) ? 1 : 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = (n < 0) ? n * -1 : n;
	len = ft_count_num(n);
	str = (char *)malloc(sizeof(char) * (len + s + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	str = str + s;
	i = len - 1;
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[len] = '\0';
	return (str - s);
}
