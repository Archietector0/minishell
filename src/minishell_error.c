/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:59:05 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:59:07 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_err_str(int str_amt, ...)
{
	va_list	argptr;

	va_start(argptr, str_amt);
	while (str_amt-- > 1)
	{
		ft_putstr_fd((char *)va_arg(argptr, char *), 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd((char *)va_arg(argptr, char *), 2);
	ft_putstr_fd("\n", 2);
	va_end(argptr);
}

void	ft_error_ms_str_errno(char *file_name, int ft_errno)
{
	ft_putstr_fd("-minishell: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(ft_errno), 2);
	ft_putstr_fd("\n", 2);
}

void	ft_unexp_token(char c)
{
	ft_putstr_fd("-minishell: syntax error near unexpected token `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
}
