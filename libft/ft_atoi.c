/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 17:56:39 by svan-der       #+#    #+#                */
/*   Updated: 2019/11/14 18:12:07 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libdefs.h"

int		ft_atoip_base(const char *str, unsigned int base, int *dest)
{
	int res;
	int i;

	i = 0;
	while (ft_whitespace(str[i]))
		i++;
	if (!ft_isdigit_base(str[i], base))
	{
		if (str[i] == '-' && ft_isdigit_base(str[i + 1], base))
			return (ft_atoi_base(&str[i] + 1, base) * -1);
		else if (str[i] == '+' && ft_isdigit(str[i + 1]))
			return (ft_atoi_base(&str[i] + 1, base));
		else
			return (0);
	}
	res = 0;
	while (ft_isdigit_base(str[i], base))
	{
		res *= base;
		res += (base == 1) ? 1 : ft_strchri(HEX, str[i]);
		i++;
	}
	*dest = res;
	return (i);
}

int		ft_atoip(const char *str, int *dest)
{
	return (ft_atoip_base(str, 10, dest));
}

int		ft_atoi_base(const char *str, unsigned int base)
{
	int		ret;

	ft_atoip_base(str, base, &ret);
	return (ret);
}

int		ft_atoi(const char *str)
{
	int i;
	int res;

	i = 0;
	while (ft_whitespace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			return (ft_atoi(&str[i] + 1) * -1);
		else if (str[i] == '+' && ft_isdigit(str[i + 1]))
			return (ft_atoi(&str[i] + 1));
		else
			return (0);
	}
	res = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}
