/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:27:26 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/08 16:28:00 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	while ((*t_s1 == *t_s2) && (*t_s1 != '\0') && (n > 0))
	{
		++t_s1;
		++t_s2;
		--n;
	}
	if ((*t_s1 == *t_s2) || (n <= 0))
	{
		return (0);
	}
	return (*t_s1 - *t_s2);
}
