/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:54:26 by grota             #+#    #+#             */
/*   Updated: 2017/11/27 11:25:12 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

static char	*ft_putnbr_str(int n, char *s)
{
	if (n / 10 != 0)
		s = ft_putnbr_str((n / 10), s);
	else if (n < 0)
		*s++ = '-';
	*s++ = ft_abs(n % 10) + '0';
	*s = '\0';
	return (s);
}

char		*ft_itoa(int n)
{
	size_t	i;
	int		n_cpy;
	char	*s;

	i = 0;
	n_cpy = n;
	if (n_cpy < 0)
	{
		i++;
		n_cpy = -n_cpy;
	}
	while (n_cpy > 9)
	{
		n_cpy /= 10;
		i++;
	}
	if (!(s = ft_strnew(i)))
		return (NULL);
	ft_putnbr_str(n, s);
	return (s);
}
