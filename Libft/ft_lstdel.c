/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:15:00 by grota             #+#    #+#             */
/*   Updated: 2017/11/24 16:09:50 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	list = *alst;
	if (list)
	{
		del(list->content, list->content_size);
		if (list->next != NULL)
			ft_lstdel(&(*alst)->next, del);
		free(list);
		*alst = (NULL);
	}
}
