/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
<<<<<<< HEAD
/*   Created: 2019/12/23 00:32:50 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 11:54:11 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf/ft_printf.h"
=======
/*   Created: 2019/12/23 00:32:50 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/08 17:53:13 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf/ft_printf.h"
>>>>>>> parent of eb144b2... Modified Makefile and add README file

int		ft_asprintf(char **str, const char *format, ...)
{
	va_list ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vasprintf(str, format, ap);
	va_end(ap);
	return (ret);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}
