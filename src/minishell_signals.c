/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 14:49:31 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 14:49:34 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	active_parent(void)
{
	signal(SIGINT, my_sig_int_holder);
	signal(SIGQUIT, SIG_IGN);
}

void	ignore_all(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	active_child(void)
{
	signal(SIGINT, child_exit);
	signal(SIGQUIT, SIG_IGN);
}

void	passive_parent(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
