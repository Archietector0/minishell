/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_ret_val.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:03:05 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:03:06 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	write_ret(char **dst, char **src)
{
	char	*ret_str;
	char	*temp_str;

	if (*(*src + 1) == '?')
	{
		ret_str = ft_itoa(g_glob.status);
		temp_str = ret_str;
		++*src;
		while (*ret_str != '\0')
		{
			**dst = *ret_str;
			++*dst;
			++ret_str;
		}
		free(temp_str);
		return (0);
	}
	return (1);
}

int	ret_len_processing(char **s, int *word_len)
{
	if (*(*s + 1) == '?')
	{
		*word_len += ft_num_amount(g_glob.status);
		return (0);
	}
	return (1);
}
