/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:03:31 by grota             #+#    #+#             */
/*   Updated: 2017/11/24 14:22:12 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	i = 0;
	end = ft_strlen(s);
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			&& s[start])
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t'
				|| s[end] == '\0') && end > 0)
		end--;
	end++;
	if (start > end)
		end = start;
	return (ft_strsub(s, start, end - start));
}
