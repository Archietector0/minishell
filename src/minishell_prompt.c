/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:04:34 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:04:36 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_prompt(void)
{
	char	*t_user;
	char	*t_host;
	size_t	len;

	if (g_glob.prompt != NULL)
		free(g_glob.prompt);
	t_user = get_env_value(g_glob.envp, "USER");
	if (t_user == NULL)
	{
		t_user = get_env_value(g_glob.envp, "LOGNAME");
		if (t_user == NULL)
			t_user = "noname";
	}
	t_host = get_env_value(g_glob.envp, "NAME");
	if (t_host == NULL)
		t_host = "nohost";
	len = ft_strlen(t_user) + ft_strlen(t_host) + 4;
	g_glob.prompt = (char *) exit_malloc(len);
	ft_strlcat(g_glob.prompt, t_user, len);
	ft_strlcat(g_glob.prompt, "@", len);
	ft_strlcat(g_glob.prompt, t_host, len);
	ft_strlcat(g_glob.prompt, ": ", len);
}
