/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:34:06 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 15:55:40 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t_s1;
	unsigned char	*t_s2;
	int				diff;

	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		diff = *t_s1 - *t_s2;
		if (diff != 0)
		{
			return (diff);
		}
		++t_s1;
		++t_s2;
		--n;
	}
	return (0);
}
