/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_redirect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:00:11 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:00:14 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	s_output(t_comm *command)
{
	int		fd;

	fd = open(command->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		ft_error_ms_str_errno(command->str, errno);
		return (-1);
	}
	else
	{
		dup2(fd, 1);
		close(fd);
	}
	return (0);
}

int	d_output(t_comm *command)
{
	int		fd;

	fd = open(command->str, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	if (fd < 0)
	{
		ft_error_ms_str_errno(command->str, errno);
		return (-1);
	}
	else
	{
		dup2(fd, 1);
		close(fd);
	}
	return (0);
}

int	s_input(t_comm *command)
{
	int		fd;

	fd = open(command->str, O_RDONLY);
	if (fd < 0)
	{
		ft_error_ms_str_errno(command->str, errno);
		return (-1);
	}
	else
	{
		dup2(fd, 0);
		close(fd);
	}
	return (0);
}

int	d_input(t_comm *command)
{
	return (s_input(command));
}

int	redirect(t_comm *command)
{
	if (command->type == APPEND)
		return (d_output(command));
	else if (command->type == OUTPUT)
		return (s_output(command));
	else if (command->type == HEREDOC)
		return (d_input(command));
	else if (command->type == INPUT)
		return (s_input(command));
	return (1);
}
