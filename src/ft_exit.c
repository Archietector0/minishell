/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:55:28 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:55:31 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **parp)
{
	long long	ret_val;

	if (*parp == NULL)
		exit (g_glob.status);
	if (ft_exit_atoi(*parp, &ret_val) != 0)
	{
		ft_err_str(4, "bash", "exit", *parp, "numeric argument required");
		exit (-1);
	}
	if (*(parp + 1) != NULL)
	{
		ft_err_str(3, "bash", "exit", "too many arguments");
		return (1);
	}
	exit ((unsigned char)ret_val);
}
