/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:52:15 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/16 14:43:40 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static void	ft_skip(const char **str, int *sign)
{
	while ((**str == ' ') || ((**str >= '\t') && (**str <= '\r')))
		++(*str);
	if ((**str == '+') || (**str == '-'))
	{
		if (**str == '-')
			(*sign) *= -1;
		++(*str);
	}
	while (**str == '0')
		++(*str);
}

static long	ft_find_max_amount(int sign)
{
	if (sign < 0)
		return (-(LONG_MIN / 10));
	return (LONG_MAX / 10);
}

static char	ft_find_max_num(int sign)
{
	if (sign < 0)
		return ((char)((-(LONG_MIN % 10)) + '0'));
	return ((char)((LONG_MAX % 10) + '0'));
}

int	ft_atoi(const char *str)
{
	long		result;
	int			sign;
	long		max_amount;
	char		max_num;

	sign = 1;
	ft_skip(&str, &sign);
	max_amount = ft_find_max_amount(sign);
	max_num = ft_find_max_num(sign);
	result = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		if ((result * sign > max_amount) || \
			((result * sign == max_amount) && (*str > max_num)))
		{
			return (-((1 + sign) / 2));
		}
		result = (result * 10) + (sign * (*str - '0'));
		++str;
	}
	return (result);
}
