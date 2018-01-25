/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:01:24 by grota             #+#    #+#             */
/*   Updated: 2017/11/27 11:07:40 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!size && !dest && !src)
		return (0);
	while (dest[i] && i < size)
		i++;
	while (j + i + 1 < size && src[j])
	{
		if (j + i < size)
			dest[i + j] = src[j];
		j++;
	}
	if (j + i < size)
		dest[i + j] = '\0';
	if (size < i)
		return (size + j);
	return (ft_strlen(src) + i);
}
