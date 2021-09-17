/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:25:06 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 15:26:09 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*t_content;
	t_list	*result;

	result = NULL;
	if ((lst != NULL) && (f != NULL))
	{
		while (lst != NULL)
		{
			t_content = f(lst->content);
			if (t_content == NULL)
			{
				ft_lstclear(&result, del);
				return (NULL);
			}
			ft_lstadd_back(&result, ft_lstnew(t_content));
			lst = lst->next;
		}
		return (result);
	}
	return (NULL);
}
