/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:50:21 by grota             #+#    #+#             */
/*   Updated: 2018/01/26 16:52:16 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubf(char *s, unsigned int start, size_t len)
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
	free(s);
	return (d);
}
