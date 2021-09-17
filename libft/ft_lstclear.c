/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:05:40 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 13:17:05 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static void	ft_lstclear_rec(t_list *lst, void (*del)(void*))
{
	if (lst->next != NULL)
	{
		ft_lstclear_rec(lst->next, del);
	}
	ft_lstdelone(lst, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if ((lst != NULL) && (*lst != NULL) && (del != NULL))
	{
		ft_lstclear_rec(*lst, del);
		*lst = NULL;
	}
}
