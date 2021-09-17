/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:21:38 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/08 14:35:58 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_b;
	unsigned char	temp_c;

	temp_b = (unsigned char *)b;
	temp_c = (unsigned char)c;
	while (len > 0)
	{
		*temp_b = temp_c;
		++temp_b;
		--len;
	}
	return (b);
}
