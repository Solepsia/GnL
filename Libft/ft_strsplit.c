/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:23:12 by grota             #+#    #+#             */
/*   Updated: 2017/11/24 16:06:15 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
		if (s[i] != 0)
			i++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc((ft_nb_words(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[ft_nb_words(s, c)] = NULL;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j++] = ft_strsub(s, i, ft_strclen(&s[i], c));
			i = i + ft_strclen(&s[i], c) - 1;
		}
		i++;
	}
	return (tab);
}
