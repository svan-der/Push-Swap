/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/12 15:09:50 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/24 20:53:13 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include "list.h"
# include "mathlib.h"
# include "ntoa.h"
# include "ftoa.h"
# include <stdarg.h>

int				ft_vasprintf(char **str, const char *fmt, va_list ap);
int				ft_vdprintf(int fd, const char *fmt, va_list ap);
int				ft_vprintf(const char *fmt, va_list ap);
int				ft_asprintf(char **str, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf(const char *fmt, ...);
#endif
