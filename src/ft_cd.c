/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:54:31 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:54:38 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_str(char **envp, char *env_name)
{
	while (*envp != NULL)
	{
		if (env_name_cmp(env_name, *envp) == 0)
			break ;
		++envp;
	}
	return (*envp);
}

int	set_pwd(char ***envpp, char *str)
{
	int		size;
	char	*temp_new_env;

	size = ft_strlen(str);
	size += ft_strlen(PWD_VAR) + 2;
	temp_new_env = (char *)exit_malloc(sizeof (char) * (size));
	ft_strlcpy(temp_new_env, PWD_VAR, size);
	ft_strlcat(temp_new_env, "=", size);
	ft_strlcat(temp_new_env, str, size);
	set_env_value(envpp, temp_new_env, 0);
	free(temp_new_env);
	return (0);
}

int	set_old_pwd(char ***envpp)
{
	int		size;
	char	*temp_curr_env;
	char	*temp_new_env;

	temp_curr_env = get_env_value(*envpp, PWD_VAR);
	if (temp_curr_env != NULL)
	{
		size = ft_strlen(temp_curr_env);
		size += ft_strlen(OLDPWD_VAR) + 2;
		temp_new_env = (char *)exit_malloc(sizeof (char) * (size));
		ft_strlcpy(temp_new_env, OLDPWD_VAR, size);
		ft_strlcat(temp_new_env, "=", size);
		ft_strlcat(temp_new_env, temp_curr_env, size);
		set_env_value(envpp, temp_new_env, 0);
		free(temp_new_env);
	}
	return (0);
}

int	ft_cd(char ***envpp, char **parp)
{
	char	*temp_str;

	if (*parp == NULL)
	{
		ft_err_str(3, "bash", "cd", "not enough arguments");
		return (1);
	}
	if (*(parp + 1) != NULL)
	{
		ft_err_str(3, "bash", "cd", "too many arguments");
		return (1);
	}
	if (chdir(*parp) != 0)
	{
		ft_err_str(3, "bash", "cd", strerror(errno));
		return (1);
	}
	temp_str = getcwd(NULL, 0);
	set_old_pwd(envpp);
	set_pwd(envpp, temp_str);
	free(temp_str);
	return (0);
}
