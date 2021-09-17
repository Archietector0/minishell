/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_wildcard_amnt.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:03:41 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:03:44 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wildcard_redirect_amnt(char **file_list, t_comm *comm, int *full_amnt)
{
	int		var_amnt;

	var_amnt = wildcard_var_amnt(file_list, comm);
	if (var_amnt == 0)
	{
		*full_amnt += 1;
		return (0);
	}
	else if (var_amnt > 1)
	{
		rm_replacement(comm->str);
		ft_err_str(3, "-minishell", comm->str, "ambiguous redirect");
		g_glob.status = 1;
		return (-1);
	}
	*full_amnt += var_amnt;
	return (0);
}

int	wildcard_heredoc_amnt(int *full_amnt)
{
	++*full_amnt;
	return (0);
}

int	wildcard_comm_amnt(char **file_list, t_comm *comm, int *full_amnt)
{
	int		var_amnt;

	var_amnt = wildcard_var_amnt(file_list, comm);
	if (var_amnt == 0)
		var_amnt = 1;
	*full_amnt += var_amnt;
	return (0);
}
