/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:57:20 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/17 15:54:43 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static int	ft_setcmp(char const *set, char c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (0);
		++set;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*begin;
	char const	*end;
	ptrdiff_t	r_len;
	char		*result;

	if ((s1 == NULL) || (set == NULL))
		return (NULL);
	begin = s1;
	end = s1 + ft_strlen(s1);
	while ((*begin != '\0') && (ft_setcmp(set, *begin) == 0))
		begin++;
	if (*begin != '\0')
	{
		while (ft_setcmp(set, *(end - 1)) == 0)
			--end;
	}
	r_len = end - begin;
	result = (char *)malloc(sizeof(char) * (r_len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, begin, r_len + 1);
	return (result);
}
