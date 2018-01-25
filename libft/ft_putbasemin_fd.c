/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbasemin_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:22:31 by grota             #+#    #+#             */
/*   Updated: 2017/11/24 13:37:28 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putbasemin_fd(int n, int base, int fd)
{
	if (base < 2)
		return (0);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > base - 1)
	{
		ft_putbasemin_fd(n / base, base, fd);
		ft_putbasemin_fd(n % base, base, fd);
	}
	else
	{
		if (n > 9)
			ft_putchar_fd(n + 'a' - 10, fd);
		else
			ft_putchar_fd(n + '0', fd);
	}
	return (1);
}
