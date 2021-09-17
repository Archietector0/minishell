/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:38:31 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/08 14:09:06 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t_s;
	unsigned char	t_c;

	t_s = (unsigned char *)s;
	t_c = (unsigned char)c;
	while (n > 0)
	{
		if (*t_s == t_c)
		{
			return (t_s);
		}
		++t_s;
		--n;
	}
	return (NULL);
}
