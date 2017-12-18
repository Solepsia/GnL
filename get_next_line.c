/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:51:53 by grota             #+#    #+#             */
/*   Updated: 2017/12/18 18:44:01 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_split_next(char **line, char **next)
{
	char	**split;
	size_t	i;

	i = 1;
	if (!next || !ft_isinstr(*next, '\n') ||
			!(split = ft_strsplit(*next, '\n')))
		return (0);
	*line = ft_strdup(split[0]);
	free(*next);
	next = ft_strnew(0);
	while (split[i])
	{
		*next = ft_strjoinf(*next, split[i], 3);
		ft_strdel(split[i++]);
	}
	free(split);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*next = NULL;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (ft_strlen(next) && ft_split_next(line, &next))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret > 0)
	{
		buf[ret] = '\0';
		if (ft_isinstr(buf, '\n'))
		{
			*line = ft_strjoinf(next, ft_strsub(buf, 0, ft_strclen(buf, '\n')), 2);
			next = ft_strsub(buf, ft_strclen(buf, '\n') + 1, BUFF_SIZE + 1);
			return (1);
		}
		next = ft_strjoinf(next, buf, 3);
	}
	if (ret == 0 && next)
	{
		*line = ft_strdup(next);
		return (0);
	}
	return ((ret == -1) ? -1 : 0);
}
