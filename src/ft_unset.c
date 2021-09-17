/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:58:26 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:58:27 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	del_env_check(char *str)
{
	if (ft_isdigit(*str) == 1)
		return (-1);
	while (*str != '\0')
	{
		if (ft_isalnum(*str) == 0)
			return (-1);
		++str;
	}
	return (0);
}

static char	*find_str_pos_and_arr_size(char **str_array, char *str, int *size)
{
	char	*str_pos;

	str_pos = NULL;
	*size = 0;
	while (*str_array != NULL)
	{
		if ((str_pos == NULL) && (env_name_cmp(*str_array, str) == 0))
			str_pos = *str_array;
		else
			++(*size);
		++str_array;
	}
	return (str_pos);
}

static void	copy_str_arr_exc_str(char **dst_str_arr, char **src_str_arr, \
																	char *str)
{
	while (*src_str_arr != NULL)
	{
		if (*src_str_arr != str)
		{
			*dst_str_arr = *src_str_arr;
			++dst_str_arr;
		}
		++src_str_arr;
	}
	*dst_str_arr = NULL;
}

int	del_str_to_str_array(char ***str_array, char *str)
{
	int		new_arr_size;
	char	*str_p_in_array;
	char	**res_str_array;

	if (*str_array == NULL)
		return (0);
	str_p_in_array = find_str_pos_and_arr_size(*str_array, str, &new_arr_size);
	if (str_p_in_array == NULL)
		return (0);
	res_str_array = (char **)exit_malloc(sizeof(char *) * (new_arr_size + 1));
	copy_str_arr_exc_str(res_str_array, *str_array, str_p_in_array);
	free(str_p_in_array);
	free(*str_array);
	*str_array = res_str_array;
	return (0);
}

int	ft_unset(char ***envpp, char **parp)
{
	while (*parp != NULL)
	{
		if (del_env_check(*parp) != 0)
		{
			ft_err_str(4, "-bash", "export", *parp, "not a valid identifier");
			return (1);
		}
		del_str_to_str_array(envpp, *parp);
		++parp;
	}
	return (0);
}
