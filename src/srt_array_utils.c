/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_array_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:04:42 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/21 22:00:07 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_array_size(char **str_array)
{
	int		array_size;

	array_size = 0;
	if (str_array == NULL)
		return (0);
	while (str_array[array_size] != NULL)
	{
		++array_size;
	}
	return (array_size);
}

static void	free_str_array_val(char **str_array)
{
	while (*str_array != NULL)
	{
		free(*str_array);
		++str_array;
	}
}

void	free_str_array(char **str_array)
{
	free_str_array_val(str_array);
	free(str_array);
}

char	**clone_str_array(char **str_array)
{
	int		arr_size;
	char	**res_str_array;

	if (str_array == NULL)
		return (NULL);
	arr_size = 0;
	while (str_array[arr_size] != NULL)
		++arr_size;
	res_str_array = (char **)malloc(sizeof (char *) * (arr_size + 1));
	if (res_str_array != NULL)
	{
		res_str_array[arr_size] = NULL;
		while (--arr_size >= 0)
		{
			res_str_array[arr_size] = ft_strdup(str_array[arr_size]);
			if (res_str_array[arr_size] == NULL)
			{
				free_str_array_val(res_str_array + arr_size + 1);
				free(res_str_array);
				res_str_array = NULL;
			}
		}
	}
	return (res_str_array);
}

char	**comm_to_str_array(t_comm *commands)
{
	size_t	comm_amount;
	char	**result;

	comm_amount = 0;
	while (commands[comm_amount].type == COMMAND)
		++comm_amount;
	result = exit_malloc(sizeof (char *) * (comm_amount + 1));
	result[comm_amount] = NULL;
	while (comm_amount-- > 0)
		result[comm_amount] = ft_strdup(commands[comm_amount].str);
	return (result);
}
