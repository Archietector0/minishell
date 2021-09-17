/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:55:47 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:55:49 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "minishell.h"

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

static long long	ft_find_max_amount(int sign)
{
	if (sign < 0)
		return (-(LLONG_MIN / 10));
	return (LLONG_MAX / 10);
}

static char	ft_find_max_num(int sign)
{
	if (sign < 0)
		return ((char)((-(LLONG_MIN % 10)) + '0'));
	return ((char)((LLONG_MAX % 10) + '0'));
}

int	ft_exit_atoi(const char *str, long long *result)
{
	int				sign;
	long long		max_amount;
	char			max_num;

	sign = 1;
	ft_skip(&str, &sign);
	max_amount = ft_find_max_amount(sign);
	max_num = ft_find_max_num(sign);
	*result = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0 || \
			*result * sign > max_amount || \
			((*result * sign == max_amount) && (*str > max_num)))
			return (1);
		*result = (*result * 10) + (sign * (*str - '0'));
		++str;
	}
	return (0);
}
