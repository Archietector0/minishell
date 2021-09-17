/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:57:46 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:57:48 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_first_str(char **str_array)
{
	char	*temp_str;

	temp_str = *str_array;
	while (*(str_array++) != NULL)
	{
		if (*str_array == NULL)
			break ;
		if (env_name_cmp(temp_str, *str_array) > 0)
			temp_str = *str_array;
	}
	return (temp_str);
}

char	*find_next_str(char **str_array, char *curr_str)
{
	char	*temp_str;

	temp_str = *str_array;
	while (*str_array != NULL)
	{
		if ((env_name_cmp(*str_array, curr_str) > 0) && \
			((env_name_cmp(*str_array, temp_str) < 0) || \
			(env_name_cmp(temp_str, curr_str) <= 0)))
			temp_str = *str_array;
		++str_array;
	}
	return (temp_str);
}

void	print_env_str_as_export(char *str)
{
	write(1, "declare -x ", 11);
	while (*str != '=' && *str != '\0')
		write(1, str++, 1);
	if (*str != '\0')
	{
		write(1, str++, 1);
		write(1, "\"", 1);
		while (*str != '\0')
			write(1, str++, 1);
		write(1, "\"", 1);
	}
	write(1, "\n", 1);
}

void	print_str_arr_as_export(char **str_array)
{
	int		arr_size;
	char	*curr_str;

	if (str_array != NULL)
	{
		arr_size = 0;
		while (str_array[arr_size] != NULL)
			++arr_size;
		curr_str = find_first_str(str_array);
		while (arr_size > 0)
		{
			print_env_str_as_export(curr_str);
			curr_str = find_next_str(str_array, curr_str);
			--arr_size;
		}
	}
}
