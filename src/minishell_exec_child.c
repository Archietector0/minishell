/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:27:59 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/21 18:28:01 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	call_execve_child(char *exe_path, char **commands, \
							char **envp, int *status)
{
	active_child();
	*status = execve(exe_path, commands, envp);
	exit(*status);
}

void	call_execve_parent(char *exe_path, int *status)
{
	waitpid(0, status, 0);
	active_parent();
	free(exe_path);
	if (WIFEXITED(*status) != 0)
		*status = WEXITSTATUS(status);
}
