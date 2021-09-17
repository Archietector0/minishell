/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:37:21 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 16:04:41 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	res_len;
	char	*result;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	res_len = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		start = s_len;
	s += start;
	while ((*s != '\0') && (len > 0))
	{
		++s;
		++res_len;
		--len;
	}
	s -= res_len;
	result = (char *)malloc(res_len + 1);
	if (result == NULL)
		return (NULL);
	result = ft_memcpy(result, s, res_len);
	result[res_len] = '\0';
	return (result);
}
