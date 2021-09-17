/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:17:55 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 13:24:29 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if ((lst != NULL) && (f != NULL))
	{
		f(lst->content);
		if (lst->next != NULL)
			ft_lstiter(lst->next, f);
	}
}
