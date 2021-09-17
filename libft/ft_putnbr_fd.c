/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:39:12 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 16:46:19 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_putnbr_p(int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_p(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

static void	ft_putnbr_n(int n, int fd)
{
	ft_putchar_fd('-', fd);
	if (n < -9)
	{
		ft_putnbr_p(-(n / 10), fd);
		ft_putchar_fd(-(n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(-n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putnbr_n(n, fd);
	else
		ft_putnbr_p(n, fd);
}
