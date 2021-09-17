/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:59:51 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:59:53 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_pipe_first(int *pipe_des, t_comm *commands, t_comm *next_comm)
{
	ignore_all();
	dup2(pipe_des[1], 1);
	close(pipe_des[1]);
	set_null(next_comm);
	g_glob.status = exec_all(commands);
	close(1);
	exit (g_glob.status);
}

void	exec_pipe_second(int *pipe_des, t_comm *next_comm)
{
	ignore_all();
	dup2(pipe_des[0], 0);
	close(pipe_des[0]);
	close(pipe_des[1]);
	g_glob.status = exec_all(next_comm + 1);
	exit (g_glob.status);
}

void	exec_pipe_parent(int *pipe_des, int *status)
{
	close(pipe_des[1]);
	waitpid(0, status, 0);
	waitpid(0, status, 0);
	if (WIFEXITED(*status) != 0)
		*status = WEXITSTATUS(*status);
	active_parent();
}

int	exec_pipe_not_first(int *pipe_des, pid_t *pid, \
						t_comm *next_comm, int *status)
{
	ignore_all();
	*pid = fork();
	if (*pid == -1)
		return (-1);
	if (*pid == 0)
		exec_pipe_second(pipe_des, next_comm);
	else
		exec_pipe_parent(pipe_des, status);
	return (0);
}

int	exec_pipe(t_comm *commands, t_comm *next_comm)
{
	pid_t	pid;
	int		pipe_des[2];
	int		status;

	if (next_comm->type == PIPE)
	{
		status = 0;
		pipe (pipe_des);
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
			exec_pipe_first(pipe_des, commands, next_comm);
		else
			exec_pipe_not_first(pipe_des, &pid, next_comm, &status);
		return (0);
	}
	return (1);
}
