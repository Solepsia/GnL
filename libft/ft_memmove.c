/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:55:06 by grota             #+#    #+#             */
/*   Updated: 2017/11/24 14:53:13 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*tmp;

	if (!dest && !src)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dest, tmp, len);
	free(tmp);
	return (dest);
}
