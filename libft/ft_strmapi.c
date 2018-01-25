/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:01:53 by grota             #+#    #+#             */
/*   Updated: 2017/11/24 15:17:19 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;

	i = 0;
	if (!s || !(d = ft_strnew(ft_strlen(s))))
		return (NULL);
	d = ft_strcpy(d, s);
	while (d[i] && s[i])
	{
		d[i] = f(i, s[i]);
		i++;
	}
	return (d);
}
