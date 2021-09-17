/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_add_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:57:32 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:57:34 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_env(char *old_env, char *new_enc, int type)
{
	char	*res_env;

	res_env = NULL;
	if (type == 0)
		res_env = ft_strdup(new_enc);
	else if (old_env != NULL)
	{
		while (*new_enc != '=')
			++new_enc;
		res_env = ft_strjoin(old_env, ++new_enc);
	}
	else
	{
		res_env = (char *)exit_malloc(sizeof(char) * ft_strlen(new_enc));
		old_env = res_env;
		while (*new_enc != '+')
			*(old_env++) = *(new_enc++);
		while (*(++new_enc) != '\0')
			*(old_env++) = *new_enc;
		*old_env = '\0';
	}
	return (res_env);
}

char	**init_bigger_srt_array_and_arr_size(char ***str_array, int *arr_size)
{
	char	**res_str_array;

	*arr_size = 0;
	if (*str_array == NULL)
		res_str_array = (char **)exit_malloc(sizeof(char *) * 2);
	else
	{
		while ((*str_array)[*arr_size] != NULL)
			++(*arr_size);
		res_str_array = (char **)exit_malloc(sizeof(char *) * (*arr_size + 2));
	}
	return (res_str_array);
}

int	add_new_str_to_str_array(char ***str_array, char *str, int type)
{
	int		arr_size;
	char	**res_str_array;

	res_str_array = init_bigger_srt_array_and_arr_size(str_array, &arr_size);
	res_str_array[arr_size] = replace_env(NULL, str, type);
	res_str_array[arr_size + 1] = NULL;
	while (arr_size > 0)
	{
		--arr_size;
		res_str_array[arr_size] = (*str_array)[arr_size];
	}
	free(*str_array);
	*str_array = res_str_array;
	return (0);
}

int	set_env_value(char ***envp, char *str_var, int type)
{
	int		counter;
	char	*temp_env;

	counter = 0;
	if (*envp != NULL)
	{
		while ((*envp)[counter] != NULL)
		{
			if (env_name_cmp((*envp)[counter], str_var) == 0)
			{
				temp_env = (*envp)[counter];
				(*envp)[counter] = replace_env((*envp)[counter], str_var, type);
				free(temp_env);
				return (0);
			}
			++counter;
		}
	}
	add_new_str_to_str_array(envp, str_var, type);
	return (0);
}
