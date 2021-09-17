/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:57:40 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 16:02:16 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_set_num(char *result, int n, int num_amount)
{
	int		def;

	result += num_amount - 1;
	while (num_amount > 0)
	{
		def = n % 10;
		n = n / 10;
		if (def < 0)
			def = -def;
		*result = '0' + def;
		--num_amount;
		--result;
	}
}

char	*ft_itoa(int n)
{
	int		is_neg_fl;
	char	*result;
	int		num_amount;

	if (n < 0)
		is_neg_fl = 1;
	else
		is_neg_fl = 0;
	num_amount = ft_num_amount(n);
	result = (char *)malloc(sizeof(char) * (num_amount + is_neg_fl + 1));
	if (result == NULL)
		return (NULL);
	if (is_neg_fl == 1)
	{
		*result = '-';
		ft_set_num(result + 1, n, num_amount);
	}
	else
		ft_set_num(result, n, num_amount);
	result[is_neg_fl + num_amount] = '\0';
	return (result);
}
