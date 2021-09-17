/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_check_position.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:26:14 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/21 18:26:17 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_comm(t_comm *command, int *comm_exist)
{
	if (command->type == LOGIC || command->type == PIPE)
	{
		if (*comm_exist == 0)
		{
			ft_unexp_token(*command->str);
			g_glob.status = 258;
			return (2);
		}
		else
			*comm_exist = 0;
	}
	else if (command->type == BRACKETS && *command->str == '(' && \
			*comm_exist == 1)
	{
		ft_unexp_token(*command->str);
		g_glob.status = 258;
		return (2);
	}
	else
		*comm_exist = 1;
	return (0);
}

int	check_unexp_position(t_comm *commands)
{
	int		comm_exist;
	int		status;

	comm_exist = 0;
	while (commands->str != NULL)
	{
		status = check_comm(commands, &comm_exist);
		if (status != 0)
			return (status);
		++commands;
	}
	return (0);
}
