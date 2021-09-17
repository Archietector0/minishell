/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:02:47 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 16:03:12 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static unsigned int	ft_find_size(char const *s)
{
	unsigned int	size;

	size = 0;
	while (*s != '\0')
	{
		++size;
		++s;
	}
	return (size);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	pos;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_find_size(s) + 1));
	if (result == NULL)
		return (NULL);
	pos = 0;
	while (*s != '\0')
	{
		*result = f(pos, *s);
		++pos;
		++result;
		++s;
	}
	*result = '\0';
	return (result - pos);
}
