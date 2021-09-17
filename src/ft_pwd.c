/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:58:10 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:58:12 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*temp_pwd;

	temp_pwd = getcwd(NULL, 0);
	if (temp_pwd == NULL)
		return (-1);
	printf("%s\n", temp_pwd);
	free(temp_pwd);
	return (0);
}
