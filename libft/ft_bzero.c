/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:25:47 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/08 14:41:56 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	zero;
	unsigned char	*t_s;

	zero = 0;
	t_s = (unsigned char *)s;
	while (n > 0)
	{
		*t_s = zero;
		--n;
		++t_s;
	}
}
