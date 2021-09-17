/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:05:27 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 15:38:28 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst != NULL)
	{
		if (new != NULL)
		{
			if (*lst == NULL)
			{
				*lst = new;
			}
			else
			{
				temp = *lst;
				while (temp->next != NULL)
					temp = temp->next;
				temp->next = new;
			}
		}
	}
}
