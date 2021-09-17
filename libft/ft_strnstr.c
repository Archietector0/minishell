/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:38:54 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/17 17:55:36 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
	{
		return ((char *)haystack);
	}
	while ((*haystack != '\0') && (len + 1 > n_len))
	{
		if (ft_strncmp(haystack, needle, n_len) == 0)
		{
			return ((char *)haystack);
		}
		++haystack;
		--len;
	}
	return (NULL);
}
