/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 16:18:16 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/07 12:29:12 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				temp;

	i = 0;
	j = 0;
	while (i < (size - 1))
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j += 1;
		}
		i += 1;
	}
}

int		check_num(int argc, char *str)
{
	int i;
	int min;
	// int len; 
	// int res;

	i = 0;
	min = 0;
	(void)argc;
	while (argc && ft_isdigit(str[i]))
	{
		while (ft_whitespace(str[i]))
			i++;
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
		{
			min += 1;
			i++;
		}
		else if (str[i] == '+' && ft_isdigit(str[i + 1]))
			i++;
		argc = 0;
	}
	return (1);
	// if (str == )
	// res = 0;
	// while (str[i] != '\0' && ft_isdigit(str[i]))
	// {
	// 	res *= 10;
	// 	res += str[i] - '0';
	// 	i++;
	// }
	// return (res);
}

int		main(int argc, char **argv)
{
	char *str;
	int ret;
	int i;
	int	num;

	num = 0;
	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		str = argv[i];
		ret = check_num(argc, str);
		if (ret == 0)
			return (0);
		i++;
	}
	// sort_int_tab(array, argc);
	// i = 0;
    // while (i < argc)
    // {
    //     printf("This is reversed tab %d\n", array[argc - 1]);
    //     argc--;
	// }
	// while (i < argc)
	// {
	// 	array[i] = argv[i];
	// 	i++;
	// }
	// printf("This is num %d\n", ret);
	return (0);
}

// #include <stdlib.h>
// #include <stdio.h>

// void    fprime(unsigned int nb)
// {
//     unsigned int prime;

//     if (nb == 1)
//         printf("1");
//     else
//     {
//         prime = 2;
//         while (nb > 1)
//         {
//             if(nb % prime == 0)
//             {
//                 printf("%d", prime);
//                 nb /= prime;
//                 if (nb > 1)
//                     printf("*");
//                 prime--;
//             }
//             prime++;
//         }
//     }
// }

// int     main(int argc, char **argv)
// {
//     if (argc == 2 && *argv[1])
//         fprime(atoi(argv[1]));
//     printf("\n");
//     return (0);
// }
