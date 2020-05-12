/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:20:11 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/11 16:08:47 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int		last_line(char **line, char **buff, int ret)
{
	if (ret == 0 && ft_strlen(*buff))
	{
		*line = ft_strdup(*buff);
		ft_strdel(buff);
		if (!*line)
			return (-1);
		return (1);
	}
	else
	{
		*line = ft_strnew(0);
		ft_strdel(buff);
	}
	return (0);
}

static char		*find_line(char *buff, char *fndnwl, char **line)
{
	char *tmp;

	fndnwl[0] = '\0';
	*line = ft_strdup(buff);
	if (line == NULL)
	{
		ft_strdel(line);
		return (NULL);
	}
	tmp = ft_strdup(&fndnwl[1]);
	ft_strdel(&buff);
	buff = tmp;
	return (buff);
}

static char		*read_buff(const int fd, char *str, char *buff, int *ret)
{
	char *tmp;

	*ret = (int)read(fd, str, BUFF_SIZE);
	if (*ret < 0)
		return (NULL);
	str[*ret] = '\0';
	tmp = buff;
	buff = ft_strjoin(tmp, str);
	ft_strdel(&tmp);
	if (!buff)
		return (NULL);
	return (buff);
}

static int		check_buff(char **buff, const int fd, char **line)
{
	if (!(*buff))
		*buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !buff || !line)
	{
		if (buff)
			ft_strdel(buff);
		return (-1);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char *buff;
	char		str[BUFF_SIZE + 1];
	char		*fndnwl;
	int			ret;

	if (check_buff(&buff, fd, line) == -1)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		fndnwl = ft_strchr(buff, '\n');
		if (fndnwl != NULL)
		{
			buff = find_line(buff, fndnwl, line);
			return (1);
		}
		buff = read_buff(fd, str, buff, &ret);
		if (!buff)
			return (-1);
	}
	ret = last_line(line, &buff, ret);
	// ft_strdel(line);
	return (ret);
}
