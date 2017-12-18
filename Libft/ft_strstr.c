/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:03:16 by grota             #+#    #+#             */
/*   Updated: 2017/11/22 16:51:00 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test_str(const char *s1, const char *s2, size_t i)
{
	size_t	j;

	j = 0;
	while (s2[j])
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == s2[0])
			if (ft_test_str(s1, s2, i))
				return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
