/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:52:08 by grota             #+#    #+#             */
/*   Updated: 2017/11/24 15:54:35 by grota            ###   ########.fr       */
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

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		check;

	i = 0;
	check = 0;
	if (!ft_strlen(s1))
		return (NULL);
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			if (ft_strlen(s2) + i <= n)
				check = ft_test_str(s1, s2, i);
			if (check)
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
