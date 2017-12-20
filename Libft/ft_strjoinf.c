/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:51:54 by grota             #+#    #+#             */
/*   Updated: 2017/12/20 17:43:37 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char *s2, int flag)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*d;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	d = ft_strnew(size);
	if (!d)
		return (NULL);
	while (s1 && s1[j])
		d[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		d[i++] = s2[j++];
	if (s1 && (flag & 1))
		free(s1);
	if (s2 && (flag & 2))
		free(s2);
	return (d);
}
