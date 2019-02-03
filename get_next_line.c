/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:51:53 by grota             #+#    #+#             */
/*   Updated: 2019/02/03 18:03:23 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_split_next(char **line, t_gnl *gnl)
{
	if (!next || !ft_isinstr(gnl->line, '\n'))
		return (0);
	*line = ft_strsub(gnl->line, 0, ft_strclen(gnl->line, '\n'));
	gnl->line = ft_strsub(gnl->line, ft_strclen(gnl->line, '\n') + 1, ft_strlen(gnl->line));
	return (1);
}

static int		ft_linefeed_in_buf(char **line, t_gnl *gnl, char **buf)
{
	*line = ft_strjoinf(gnl->line, ft_strsub(*buf, 0, ft_strclen(*buf, '\n')), 2);
	gnl->line = ft_strsub(*buf, ft_strclen(*buf, '\n') + 1, BUFF_SIZE + 1);
	return (1);
}

static int		ft_newlink(const int fd, t_gnl *gnl)
{
	if (!gnl)
	{
		if (!(gnl = (t_gnl *)malloc(sizeof(*t_gnl))))
			return (0);
		gnl->first = gnl;
	}
	else
	{
		while (gnl->next)
			gnl = gnl->next;
		if (!(gnl->next = (t_gnl *)malloc(sizeof(*t_gnl))))
			return (0);
		gnl->next->first = gnl->first;
		gnl = gnl->next;
	}
		gnl->fd = fd;
		gnl->line = NULL;
		gnl->next = NULL;
	return (1);
}

static t_gnl	*ft_select_fd(const int fd, t_gnl *gnl)
{
	t_gnl			*tmp;

	if (!gnl && ft_newlink(fd, gnl) == 0)
		return (0);
	gnl = gnl->first;
	while (fd != gnl->fd && gnl->next)
		gnl = gnl->next;
	if (fd != gnl->fd && gnl->next == NULL)
		if (ft_newlink(fd, gnl) == 0)
			return (0);
	return (gnl);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	int				ret;
	char			*buf;

	if (fd < 0 || BUFF_SIZE < 1 || !line || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	gnl = ft_select_fd(fd, gnl);
	if (ft_strlen(gnl->line) && ft_split_next(line, &(gnl->line)))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret > 0)
	{
		if (ft_isinstr(buf, '\n'))
			return (ft_linefeed_in_buf(line, &(gnl->line), &buf));
		gnl->line = ft_strjoinf(gnl->line, buf, 3);
		buf = ft_strnew(BUFF_SIZE);
	}
	if (ft_strlen(gnl->line))
	{
		*line = gnl->line;
		gnl->line = NULL;
		return (1);
	}
	else
		*line = NULL;
	return (ret);
}
