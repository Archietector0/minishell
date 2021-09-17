/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_wildcard.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:03:25 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:03:27 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wildcard_cmp(const char *pattern, const char *str)
{
	while (*pattern != WILDCARD_REPLACE && *pattern == *str && *pattern != '\0')
	{
		++pattern;
		++str;
	}
	if (*pattern == '\0')
		return (0);
	if (*pattern == WILDCARD_REPLACE)
	{
		while (1)
		{
			if (wildcard_cmp(pattern + 1, str) == 0)
				return (0);
			if (*str == '\0')
				break ;
			++str;
		}
	}
	return (1);
}

int	wildcard_var_amnt(char **file_list, t_comm *pattern)
{
	int	wildcard_amnt;
	int	hidden_flag;

	wildcard_amnt = 0;
	if (*pattern->str == '.')
		hidden_flag = 1;
	else
		hidden_flag = 0;
	while (*file_list != NULL)
	{
		if ((hidden_flag == 1 || **file_list != '.') && \
		wildcard_cmp(pattern->str, *file_list) == 0)
			++wildcard_amnt;
		++file_list;
	}
	return (wildcard_amnt);
}

int	is_wildcard(t_comm *command)
{
	if (ft_strchr(command->str, WILDCARD_REPLACE) == NULL)
		return (0);
	return (1);
}

int	wildcard_full_amnt(char **file_list, t_comm *comm, int *var_amt)
{
	int		status;

	while (comm->str != NULL)
	{
		if (is_wildcard(comm) == 1)
		{
			if (comm->type == INPUT)
				status = wildcard_redirect_amnt(file_list, comm, var_amt);
			else if (comm->type == OUTPUT)
				status = wildcard_redirect_amnt(file_list, comm, var_amt);
			else if (comm->type == APPEND)
				status = wildcard_redirect_amnt(file_list, comm, var_amt);
			else if (comm->type == HEREDOC)
				status = wildcard_heredoc_amnt(var_amt);
			else
				status = wildcard_comm_amnt(file_list, comm, var_amt);
			if (status != 0)
				return (1);
		}
		else
			++*var_amt;
		++comm;
	}
	return (0);
}

int	extend_wildcard(t_comm *comm, t_comm **extend_comm)
{
	char	**file_list;
	t_comm	*new_arr;
	int		new_arr_size;

	file_list = get_file_list();
	new_arr_size = 0;
	new_arr = comm;
	if (wildcard_full_amnt(file_list, comm, &new_arr_size) == 1)
	{
		*extend_comm = NULL;
		return (1);
	}
	if (new_arr_size != size_of_comm_arr(comm))
		new_arr = exit_malloc(sizeof(t_comm) * (new_arr_size + 1));
	write_wildcard_extend(new_arr, comm, file_list);
	free_str_array(file_list);
	if (new_arr == comm)
	{
		*extend_comm = NULL;
		return (0);
	}
	*extend_comm = new_arr;
	return (0);
}
