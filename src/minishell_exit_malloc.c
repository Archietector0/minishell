/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exit_malloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:00:26 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:00:29 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*exit_malloc(unsigned int size)
{
	void	*result;

	result = malloc(size);
	while (size > 0)
		*((char *)result + --size) = 0;
	if (result == NULL)
		exit(1);
	return (result);
}
