/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_get_file_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:00:40 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:00:43 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_list_size(void)
{
	char			*curr_dir;
	int				file_counter;
	DIR				*dir_p;
	struct dirent	*temp;

	curr_dir = getcwd(NULL, 0);
	dir_p = opendir(curr_dir);
	free(curr_dir);
	temp = readdir(dir_p);
	file_counter = 0;
	while (temp != NULL)
	{
		++file_counter;
		temp = readdir(dir_p);
	}
	closedir(dir_p);
	return (file_counter);
}

void	full_file_list(char **str_arr)
{
	char			*curr_dir;
	DIR				*dir_p;
	struct dirent	*temp;

	curr_dir = getcwd(NULL, 0);
	dir_p = opendir(curr_dir);
	free(curr_dir);
	temp = readdir(dir_p);
	while (temp != NULL)
	{
		*str_arr++ = ft_strdup(temp->d_name);
		temp = readdir(dir_p);
	}
	closedir(dir_p);
}

char	**get_file_list(void)
{
	char	**result;

	result = (char **)exit_malloc(sizeof (char *) * (file_list_size() + 1));
	full_file_list(result);
	return (result);
}
