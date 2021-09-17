/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:07:39 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 15:48:16 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_word_amount(char const *s, char c)
{
	size_t	word_amount;
	int		new_word_flag;

	word_amount = 0;
	new_word_flag = 1;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (new_word_flag == 1)
			{
				new_word_flag = 0;
				++word_amount;
			}
		}
		else
			new_word_flag = 1;
		++s;
	}
	return (word_amount);
}

static void	ft_result_init(char **result, size_t word_amount)
{
	while (word_amount + 1 > 0)
	{
		*result = NULL;
		--word_amount;
		++result;
	}
}

static int	ft_full_res(char **res, size_t w_amount, char const *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (w_amount > 0)
	{
		while (*s == c)
			++s;
		while ((*s != c) && (*s != '\0'))
		{
			++word_len;
			++s;
		}
		*res = ft_substr(s - word_len, 0, word_len);
		if (*res == NULL)
			return (1);
		++res;
		word_len = 0;
		--w_amount;
	}
	return (0);
}

static void	ft_free_result(char **result, size_t word_amount)
{
	while (word_amount > 0)
	{
		if (*result != NULL)
			free(*result);
		++result;
		--word_amount;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_amount;

	if (s == NULL)
		return (NULL);
	word_amount = ft_word_amount(s, c);
	result = (char **)malloc(sizeof(char *) * (word_amount + 1));
	if (result == NULL)
		return (NULL);
	ft_result_init(result, word_amount);
	if (ft_full_res(result, word_amount, s, c) != 0)
	{
		ft_free_result(result, word_amount);
		return (NULL);
	}
	return (result);
}
