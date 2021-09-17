/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:59:17 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 16:08:01 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;
	unsigned char	t_c;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	t_c = (unsigned char)c;
	while (n > 0)
	{
		*t_dst = *t_src;
		++t_dst;
		if (*t_src == t_c)
		{
			return (t_dst);
		}
		++t_src;
		--n;
	}
	return (NULL);
}
