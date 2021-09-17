/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:34:38 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 16:21:56 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	ft_dst_first(unsigned char *t_dst, unsigned char *t_src, size_t len)
{
	while (len > 0)
	{
		*t_dst = *t_src;
		++t_dst;
		++t_src;
		--len;
	}
}

static void	ft_src_first(unsigned char *t_dst, unsigned char *t_src, size_t len)
{
	t_dst += len - 1;
	t_src += len - 1;
	while (len > 0)
	{
		*t_dst = *t_src;
		--t_dst;
		--t_src;
		--len;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (dst != src)
	{
		t_dst = (unsigned char *)dst;
		t_src = (unsigned char *)src;
		if (t_dst < t_src)
		{
			ft_dst_first(t_dst, t_src, len);
		}
		else
		{
			ft_src_first(t_dst, t_src, len);
		}
	}
	return (dst);
}
