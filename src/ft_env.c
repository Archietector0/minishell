/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:55:08 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:55:11 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_check(char *str)
{
	while (*str != '\0')
		if (*str++ == '=')
			return (0);
	return (1);
}

int	ft_env(char **envp)
{
	while (*envp != NULL)
	{
		if (env_check(*envp) == 0)
			printf("%s\n", *envp);
		++envp;
	}
	return (0);
}
