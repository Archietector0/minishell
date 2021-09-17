/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:56:16 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:56:18 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_name_cmp(const char *s1, const char *s2)
{
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	while ((*t_s1 == *t_s2) && (*t_s1 != '=') && (*t_s1 != '\0'))
	{
		++t_s1;
		++t_s2;
	}
	if ((*t_s1 == *t_s2) || \
	(((*t_s1 == '=') || (*t_s1 == '\0')) && \
	((*t_s2 == '+') || (*t_s2 == '\0') || (*t_s2 == '='))))
	{
		return (0);
	}
	return (*t_s1 - *t_s2);
}

int	new_env_check(char *str)
{
	if (ft_isdigit(*str) == 1)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '+' && *(str + 1) == '=')
			return (1);
		if (*str == '=')
			return (0);
		if (ft_isalnum(*str) == 0)
			return (-1);
		++str;
	}
	return (0);
}

int	ft_export(char ***envp, char **parp)
{
	int		status;

	if (parp == NULL || *parp == NULL)
	{
		print_str_arr_as_export(*envp);
		return (0);
	}
	while (*parp != NULL)
	{
		status = new_env_check(*parp);
		if (status >= 0)
		{
			status = set_env_value(envp, *parp, status);
			if (status != 0)
				return (status);
		}
		else
		{
			g_glob.status = 1;
			ft_err_str(4, "-bash", "export", *parp, "not a valid identifier");
		}
		++parp;
	}
	return (g_glob.status);
}
