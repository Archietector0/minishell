/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:54:52 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:54:55 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **parp)
{
	int		n_flag;

	n_flag = 0;
	while ((*parp != NULL) && (ft_strcmp("-n", *parp) == 0))
	{
		n_flag = 1;
		++parp;
	}
	if (*parp != NULL)
		printf("%s", *(parp++));
	while (*parp != NULL)
		printf(" %s", *(parp++));
	if (n_flag == 0)
		printf("\n");
	return (0);
}
