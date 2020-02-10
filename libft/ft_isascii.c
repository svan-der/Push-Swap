/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/28 17:02:11 by svan-der       #+#    #+#                */
/*   Updated: 2019/10/15 13:38:30 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_whitespace(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "\n\t\v\f\r ";
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int		ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
