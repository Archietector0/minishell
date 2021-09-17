/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:59:18 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:59:26 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec__or__and(t_comm *command, t_comm *next_command)
{
	if (next_command->type == LOGIC && *next_command->str == '|')
	{
		set_null(next_command);
		exec_all(command);
		if (g_glob.status != 0)
			exec_all(next_command + 1);
		return (0);
	}
	if (next_command->type == LOGIC && *next_command->str == '&')
	{
		set_null(next_command);
		exec_all(command);
		if (g_glob.status == 0)
			exec_all(next_command + 1);
		return (0);
	}
	return (1);
}

void	exec_red_and_comm(t_comm *c)
{
	int	status;

	status = 0;
	while (c->str != NULL && (c->type == INPUT || c->type == OUTPUT || \
			c->type == APPEND || c->type == HEREDOC))
	{
		status = redirect(c);
		if (status != 0)
			break ;
		++c;
	}
	if (status >= 0 && c->str != NULL)
	{
		passive_parent();
		g_glob.status = call_command(c, &g_glob.envp);
		active_parent();
	}
}

int	exec_commands(t_comm *commands)
{
	int		temp_stdin;
	int		temp_stdout;
	t_comm	*extend_comm;

	temp_stdin = dup(0);
	temp_stdout = dup(1);
	extend_comm = NULL;
	if (extend_wildcard(commands, &extend_comm) == 0)
	{
		if (extend_comm != NULL)
		{
			exec_red_and_comm(extend_comm);
			free_result(extend_comm);
		}
		else
			exec_red_and_comm(commands);
	}
	dup2(temp_stdin, 0);
	close(temp_stdin);
	dup2(temp_stdout, 1);
	close(temp_stdout);
	if (g_glob.status != 0)
		return (1);
	return (0);
}

t_comm	*find_next_comms_block(t_comm *commands)
{
	int	brackets_deep;

	brackets_deep = 0;
	while (commands->str != NULL && !(brackets_deep == 0 && \
	(commands->type == LOGIC || commands->type == PIPE || \
	(commands->type == BRACKETS && *commands->str == ')'))))
	{
		if (commands->type == BRACKETS)
		{
			if (*commands->str == '(')
				++brackets_deep;
			else
				--brackets_deep;
		}
		++commands;
	}
	return (commands);
}

int	exec_all(t_comm *commands)
{
	t_comm	*next_comm;

	if (commands->str == NULL)
	{
		return (0);
	}
	next_comm = find_next_comms_block(commands);
	if (exec__or__and(commands, next_comm) != 0 && \
	exec_pipe(commands, next_comm) != 0)
	{
		if (commands->type == BRACKETS && *commands->str == '(')
			exec_all(commands + 1);
		else
			exec_commands(commands);
	}
	return (0);
}
