/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:03:23 by grota             #+#    #+#             */
/*   Updated: 2017/11/22 17:22:30 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;

	i = 0;
	if (!(d = ft_strnew(len)))
		return (NULL);
	while (i < len && s[start + i])
	{
		d[i] = s[start + i];
		i++;
	}
	return (d);
}
