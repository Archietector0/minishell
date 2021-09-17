/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:30:38 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 16:03:49 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;

	if ((s1 == NULL) || (s2 == NULL))
	{
		return (NULL);
	}
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(size);
	if (result == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(result, s1, size);
	ft_strlcat(result, s2, size);
	return (result);
}
