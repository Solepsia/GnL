/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:51:53 by grota             #+#    #+#             */
/*   Updated: 2017/12/20 19:33:16 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_split_next(char **line, char **next)
{
	size_t	i;

	i = 1;
	if (!next || !ft_isinstr(*next, '\n'))
		return (0);
	*line = ft_strsub(*next, 0, ft_strclen(*next, '\n'));
	*next = ft_strsub(*next, ft_strclen(*next, '\n'), ft_strlen(*next));
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
		{
			*line = ft_strjoinf(next, ft_strsub(buf, 0,
						ft_strclen(buf, '\n')), 0);
			next = ft_strsub(buf, ft_strclen(buf, '\n') + 1, BUFF_SIZE + 1);
			return (1);
		}
		next = ft_strjoinf(next, buf, 0);
	}
	*line = NULL;
	return (ret);
}

/*int				main(int argc, char **argv)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	line = ft_strnew(12);
	if (argc != 2)
		return(0);
	fd = open(argv[1], O_RDONLY);
	i = get_next_line(fd, &line);
	ft_putnbr(i);
	ft_putendl(line);
	i = get_next_line(fd, &line);
	ft_putnbr(i);
	ft_putendl(line);
	i = get_next_line(fd, &line);
	ft_putnbr(i);
	ft_putendl(line);
	i = get_next_line(fd, &line);
	ft_putnbr(i);
	ft_putendl(line);
}*/
