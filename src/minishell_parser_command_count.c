/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_command_count.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:01:56 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:01:58 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	qoat_processing(const char c, t_par_flags *flags)
{
	if (c == '\"' && flags->s_qoat == 0)
	{
		if (flags->d_qoat == 0)
			flags->d_qoat = 1;
		else
			flags->d_qoat = 0;
		return (0);
	}
	if (c == '\'' && flags->d_qoat == 0)
	{
		if (flags->s_qoat == 0)
			flags->s_qoat = 1;
		else
			flags->s_qoat = 0;
		return (0);
	}
	return (1);
}

int	redirect_skip(char const **s, t_par_flags *flags)
{
	int		counter;

	if (**s == '>' || **s == '<')
	{
		counter = 1;
		flags->word = 1;
		while (**s == *(*s + 1))
		{
			++counter;
			++*s;
		}
		if (counter > 2)
		{
			ft_unexp_token(**s);
			g_glob.status = 258;
			return (-1);
		}
		++*s;
		while (**s == ' ')
			++*s;
		return (0);
	}
	return (1);
}

int	is_special(char const **s, int *word_amount)
{
	if (**s == '|' || **s == '&')
	{
		++*word_amount;
		while (**s == *(*s + 1))
			++*s;
		++*s;
		return (1);
	}
	if (**s == '(' || **s == ')')
	{
		++*word_amount;
		++*s;
		return (1);
	}
	return (0);
}

int	word_processing(const char **s, t_par_flags *flags, int *word_amount)
{
	int		status;

	status = is_special(s, word_amount);
	if (status != 0)
		return (status);
	while (qoat_processing(**s, flags) == 0)
	{
		flags->word = 1;
		++*s;
	}
	if (flags->s_qoat == 0 && flags->d_qoat == 0)
		status = redirect_skip(s, flags);
	if (status < 0)
		return (status);
	while (is_eow(**s, flags) == 0)
	{
		qoat_processing(**s, flags);
		flags->word = 1;
		++*s;
	}
	if (flags->word == 1)
		++*word_amount;
	return (0);
}

int	find_word_amount(char const *s)
{
	int			word_amount;
	t_par_flags	flags;

	init_flags(&flags);
	word_amount = 0;
	while (1)
	{
		flags.word = 0;
		while (*s == ' ')
			++s;
		if (word_processing(&s, &flags, &word_amount) < 0)
			return (-1);
		if (*s == '\0')
			break ;
	}
	return (word_amount);
}
