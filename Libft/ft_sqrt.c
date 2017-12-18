/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:57:39 by grota             #+#    #+#             */
/*   Updated: 2017/12/12 15:58:56 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int racine;
	int sqrt;

	racine = 1;
	sqrt = 0;
	while (racine <= nb / 2)
	{
		sqrt = racine * racine;
		if (sqrt == nb)
		{
			return (racine);
		}
		racine = racine + 1;
	}
	return (0);
}
