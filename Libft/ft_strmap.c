/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:01:45 by grota             #+#    #+#             */
/*   Updated: 2017/11/24 15:16:59 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*d;
	size_t	i;

	i = 0;
	if (!s || !(d = ft_strnew(ft_strlen(s))))
		return (NULL);
	d = ft_strcpy(d, s);
	while (d[i] && s[i])
	{
		d[i] = f(s[i]);
		i++;
	}
	return (d);
}
