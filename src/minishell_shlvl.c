/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_shlvl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:26:31 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/21 18:26:35 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_shlvl(void)
{
	char	*temp_val;
	char	*result;
	int		temp_lvl;
	int		size;

	temp_lvl = 0;
	temp_val = get_env_value(g_glob.envp, SHLVL_VAR);
	if (temp_val != NULL)
		temp_lvl = ft_atoi(temp_val);
	++temp_lvl;
	temp_val = ft_itoa(temp_lvl);
	size = ft_strlen(temp_val);
	size += ft_strlen(SHLVL_VAR) + 2;
	result = (char *)exit_malloc(sizeof (char) * (size));
	ft_strlcpy(result, SHLVL_VAR, size);
	ft_strlcat(result, "=", size);
	ft_strlcat(result, temp_val, size);
	free (temp_val);
	set_env_value(&g_glob.envp, result, 0);
	free (result);
}
