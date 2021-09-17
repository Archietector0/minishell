/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:57:39 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/16 15:55:36 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	while ((dstsize > 1) && (*src != '\0'))
	{
		*dst = *src;
		++dst;
		++src;
		--dstsize;
	}
	if (dstsize > 0)
	{
		*dst = '\0';
	}
	return (srcsize);
}
