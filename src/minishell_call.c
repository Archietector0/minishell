/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:58:50 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:58:52 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_val(char **envp, char *env_name)
{
	char	*result;
	int		env_name_len;

	result = NULL;
	env_name_len = ft_strlen(env_name);
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, env_name, env_name_len) == 0)
		{
			result = *envp;
			if (new_env_check(result) == 0)
				result += env_name_len + 1;
			else
				return (NULL);
			return (result);
		}
		++envp;
	}
	return (result);
}

static int	add_exe_name(char **pathp, char *exe_name)
{
	char	*exe_str;
	size_t	exe_len;
	size_t	new_path_len;

	if (pathp == NULL || exe_name == NULL)
		return (-1);
	exe_len = ft_strlen(exe_name);
	while (*pathp != NULL)
	{
		new_path_len = ft_strlen(*pathp) + exe_len + 2;
		exe_str = (char *)exit_malloc(sizeof (char) * (new_path_len));
		ft_strlcpy(exe_str, *pathp, new_path_len);
		ft_strlcat(exe_str, "/", new_path_len);
		ft_strlcat(exe_str, exe_name, new_path_len);
		free(*pathp);
		*pathp = exe_str;
		++pathp;
	}
	return (0);
}

static char	*find_exe_path(char **envp, char *exe_name)
{
	char		**path_arr;
	char		**temp_path_arr;
	struct stat	exe;
	char		*result;

	result = NULL;
	if (exe_name[0] == '/' || (exe_name[0] == '.' && exe_name[1] == '/'))
	{
		if (stat(exe_name, &exe) == 0)
			result = ft_strdup(exe_name);
	}
	else
	{
		path_arr = ft_split(find_env_val(envp, PATH_VAR), ':');
		if (path_arr == NULL)
			return (NULL);
		add_exe_name(path_arr, exe_name);
		temp_path_arr = path_arr;
		while (*temp_path_arr != NULL)
			if (stat(*(temp_path_arr++), &exe) == 0)
				result = ft_strdup(*(temp_path_arr - 1));
		free_str_array(path_arr);
	}
	return (result);
}

static int	call_execve(char **commands, char **envp)
{
	char	*exe_path;
	int		status;
	pid_t	pid;

	exe_path = find_exe_path(envp, *commands);
	if (exe_path == NULL)
	{
		ft_err_str(3, "-minishell", *commands, "No such file or directory");
		return (127);
	}
	pid = fork();
	passive_parent();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		call_execve_child(exe_path, commands, envp, &status);
	else
		call_execve_parent(exe_path, &status);
	return (status);
}

int	call_command(t_comm *t_commands, char ***envp)
{
	int		status;
	char	**commands;

	commands = comm_to_str_array(t_commands);
	if (commands[0] == NULL)
		status = 0;
	else if (ft_strcmp("export", commands[0]) == 0)
		status = ft_export(envp, commands + 1);
	else if (ft_strcmp("unset", commands[0]) == 0)
		status = ft_unset(envp, commands + 1);
	else if (ft_strcmp("env", commands[0]) == 0)
		status = ft_env(*envp);
	else if (ft_strcmp("pwd", commands[0]) == 0)
		status = ft_pwd();
	else if (ft_strcmp("echo", commands[0]) == 0)
		status = ft_echo(commands + 1);
	else if (ft_strcmp("cd", commands[0]) == 0)
		status = ft_cd(envp, commands + 1);
	else if (ft_strcmp("exit", commands[0]) == 0)
		status = ft_exit(commands + 1);
	else
		status = call_execve(commands, *envp);
	free_str_array(commands);
	g_glob.status = status;
	return (status);
}
