/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:51:53 by grota             #+#    #+#             */
/*   Updated: 2018/02/02 17:23:35 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_split_next(char **line, char **next)
{
	if (!next || !ft_isinstr(*next, '\n'))
		return (0);
	*line = ft_strsub(*next, 0, ft_strclen(*next, '\n'));
	*next = ft_strsub(*next, ft_strclen(*next, '\n') + 1, ft_strlen(*next));
	return (1);
}

static int		ft_linefeed_in_buf(char **line, char **next, char **buf)
{
	*line = ft_strjoinf(*next, ft_strsub(*buf, 0, ft_strclen(*buf, '\n')), 2);
	*next = ft_strsub(*buf, ft_strclen(*buf, '\n') + 1, BUFF_SIZE + 1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*next = NULL;
	int			ret;
	char		*buf;

	if (fd < 0 || BUFF_SIZE < 1 || !line || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (ft_strlen(next) && ft_split_next(line, &next))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret > 0)
	{
		if (ft_isinstr(buf, '\n'))
			return (ft_linefeed_in_buf(line, &next, &buf));
		next = ft_strjoinf(next, buf, 3);
		buf = ft_strnew(BUFF_SIZE);
	}
	if (ft_strlen(next))
	{
		*line = next;
		next = NULL;
		return (1);
	}
	else
		*line = NULL;
	return (ret);
}
