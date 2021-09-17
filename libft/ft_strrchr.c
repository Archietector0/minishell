/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:29:17 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/07 16:38:13 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	t_c;
	char	*result;

	t_c = (char)c;
	result = NULL;
	while (*s != '\0')
	{
		if (*s == t_c)
		{
			result = (char *)s;
		}
		s++;
	}
	if (*s == t_c)
	{
		result = (char *)s;
	}
	return (result);
}
