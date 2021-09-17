/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:01:40 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:01:41 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_unexp_token(t_comm *c)
{
	char	*temp;

	while (c->str != NULL)
	{
		temp = c->str;
		if ((c->type == LOGIC) && ((temp[0] == '&' && temp[0] != temp[1]) \
		|| (temp[0] == temp[1] && temp[1] == temp[2])))
		{
			ft_unexp_token(*temp);
			g_glob.status = 258;
			return (1);
		}
		if ((c->type == INPUT || c->type == OUTPUT || \
			c->type == APPEND || c->type == HEREDOC) && *temp == '\0')
		{
			ft_unexp_token(*temp);
			g_glob.status = 258;
			return (1);
		}
		++c;
	}
	return (0);
}

void	sort_commands(t_comm *c)
{
	t_comm	*first_comm_p;
	t_comm	temp_p;

	while (c->str != NULL && (c->type == INPUT || c->type == BRACKETS || \
	c->type == OUTPUT || c->type == APPEND || c->type == HEREDOC))
		++c;
	first_comm_p = c;
	while (c->str != NULL)
	{
		if (c->type == INPUT || c->type == OUTPUT || \
			c->type == APPEND || c->type == HEREDOC)
		{
			temp_p = *c;
			while (c != first_comm_p)
			{
				*c = *(c - 1);
				--c;
			}
			*c = temp_p;
			first_comm_p = c + 1;
		}
		if (c->type == LOGIC || c->type == PIPE || c->type == BRACKETS)
			first_comm_p = c + 1;
		++c;
	}
}

void	print_comms(t_comm *commands)
{
	while (commands->str != NULL)
	{
		printf("%c : %s\n", commands->type, commands->str);
		++commands;
	}
}

int	check_commands(t_comm *commands)
{
	if (check_unexp_token(commands) != 0)
		return (1);
	if (check_unexp_position(commands) != 0)
		return (2);
	sort_commands(commands);
	return (0);
}
