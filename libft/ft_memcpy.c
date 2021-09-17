/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:43:46 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 16:08:34 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (dst != src)
	{
		t_dst = (unsigned char *)dst;
		t_src = (unsigned char *)src;
		while (n > 0)
		{
			*(t_dst) = *(t_src);
			++t_dst;
			++t_src;
			--n;
		}
	}
	return (dst);
}
