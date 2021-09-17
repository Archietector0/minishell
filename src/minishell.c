/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:58:37 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:58:39 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_only_spaces(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		++str;
	if (*str == '\0')
		return (1);
	return (0);
}

char	*get_correct_line(char *line)
{
	char	*t_line;

	t_line = readline(g_glob.prompt);
	while (t_line == NULL || *t_line == '\0' || is_only_spaces(t_line) == 1)
	{
		if (t_line == NULL)
		{
			write(1, "\033[A", 3);
			ft_putstr_fd(g_glob.prompt, 1);
			ft_putstr_fd("exit\n", 1);
			exit(g_glob.status);
		}
		else
			free(t_line);
		t_line = readline(g_glob.prompt);
	}
	if (line != NULL)
	{
		if (ft_strcmp(line, t_line) != 0)
			add_history(t_line);
		free (line);
	}
	else
		add_history(t_line);
	return (t_line);
}

void	start_init(char **envp)
{
	g_glob.envp = clone_str_array(envp);
	g_glob.status = 0;
	set_shlvl();
	active_parent();
}

int	first_exec_all(t_comm *comm)
{
	int		heredoc_counter;
	t_comm	*temp_comm;
	int		status;

	heredoc_counter = 0;
	temp_comm = comm;
	while (temp_comm->str != NULL)
	{
		if (temp_comm->type == HEREDOC)
			write_heredoc(temp_comm, ++heredoc_counter);
		++temp_comm;
	}
	status = exec_all(comm);
	while (heredoc_counter > 0)
	{
		if (comm->type == HEREDOC)
			unlink(comm->str);
		++comm;
		--heredoc_counter;
	}
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_comm	*commands;

	(void)argc;
	(void)argv;
	start_init(envp);
	line = NULL;
	while (g_glob.status >= 0)
	{
		set_prompt();
		line = get_correct_line(line);
		commands = parser(line);
		if (commands != NULL)
		{
			first_exec_all(commands);
			free_result(commands);
		}
	}
	free_str_array(g_glob.envp);
	return (0);
}
