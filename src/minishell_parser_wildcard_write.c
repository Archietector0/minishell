/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_wildcard_write.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:03:56 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:03:59 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm_replacement(char *str)
{
	while (*str != '\0')
	{
		if (*str == WILDCARD_REPLACE)
			*str = WILDCARD;
		++str;
	}
}

int	size_of_comm_arr(t_comm *comm)
{
	int		size;

	size = 0;
	while (comm->str != NULL)
	{
		++size;
		++comm;
	}
	return (size);
}

void	write_wildcard_to_arr(t_comm **arr, t_comm *comm, char **file_list)
{
	int		var_amnt;

	var_amnt = wildcard_var_amnt(file_list, comm);
	if (var_amnt == 0)
	{
		rm_replacement(comm->str);
		if ((*arr) != comm)
		{
			(*arr)->str = ft_strdup(comm->str);
			(*arr)->type = comm->type;
		}
		++*arr;
		return ;
	}
	while (var_amnt-- > 0)
	{
		if (*comm->str != '.')
			while (**file_list == '.')
				++file_list;
		while (wildcard_cmp(comm->str, *file_list) != 0)
			++file_list;
		(*arr)->str = ft_strdup(*file_list++);
		((*arr)++)->type = comm->type;
	}
}

void	write_wildcard_extend(t_comm *new_arr, t_comm *comm, char **file_list)
{
	while (comm->str != NULL)
	{
		if (is_wildcard(comm) == 1 && comm->type != HEREDOC)
			write_wildcard_to_arr(&new_arr, comm, file_list);
		else if (new_arr != comm)
		{
			new_arr->str = ft_strdup(comm->str);
			new_arr->type = comm->type;
			++new_arr;
		}
		else
			++new_arr;
		++comm;
	}
	set_null(new_arr);
}
