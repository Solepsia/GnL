/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:51:52 by grota             #+#    #+#             */
/*   Updated: 2019/02/03 18:03:26 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4

# include "libft/libft.h"

typedef			s_gnl
{
	int			fd;
	char		*line;
	t_gnl		*next;
	t_gnl		*first;
}

int		get_next_line(const int fd, char **line);

#endif
