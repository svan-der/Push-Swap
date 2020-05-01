/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
<<<<<<< HEAD
/*   Created: 2019/10/12 15:08:04 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 11:56:27 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf/ft_printf.h"
=======
/*   Created: 2019/10/12 15:08:04 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/08 17:48:28 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf/ft_printf.h"
#include "../includes/ft_printf/fndm.h"
>>>>>>> parent of eb144b2... Modified Makefile and add README file

/*
** dynamically allocate a new string with malloc
*/

int		ft_vasprintf(char **str, const char *format, va_list ap)
{
	t_format	fmt;
	int			ret;

	fmt = (t_format){0, 0, 0, NULL, NULL, NULL};
	if (process(&fmt, format, ap) == -1)
		return (-1);
	*str = NULL;
	ret = print_buffer(fmt.buffer, 0, str, 0);
	return (ret);
}

/*
** writes argument to given filedescriptor
*/

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_format	fmt;

	fmt = (t_format){0, 0, fd, NULL, NULL, NULL};
	if (process(&fmt, format, ap) == -1 && !fmt.buffer)
		return (-1);
	return (print_buffer(fmt.buffer, fd, NULL, 0));
}

/*
** writes argument to standard output
*/

int		ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}
