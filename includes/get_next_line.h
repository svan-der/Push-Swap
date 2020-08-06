/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 11:02:05 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:33:01 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);

#endif
