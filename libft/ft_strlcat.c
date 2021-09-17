/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:51:47 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 16:09:47 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	returnsize;

	returnsize = ft_strlen(src);
	while ((*dst != '\0') && (dstsize > 0))
	{
		++returnsize;
		++dst;
		--dstsize;
	}
	if (!(dstsize > 0))
	{
		return (returnsize);
	}
	ft_strlcpy(dst, src, dstsize);
	return (returnsize);
}
