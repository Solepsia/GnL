/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:55:03 by grota             #+#    #+#             */
/*   Updated: 2017/11/22 16:19:48 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*p;

	i = 0;
	if ((p = malloc(size)))
	{
		while (i < size)
			((unsigned char *)p)[i++] = 0;
		return (p);
	}
	else
		return (NULL);
}
