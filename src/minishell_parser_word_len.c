/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_word_len.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:04:14 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:04:17 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_len(char **str, t_par_flags *flags)
{
	int		redir_len;

	redir_len = 0;
	if (**str == '<' || **str == '>')
	{
		++redir_len;
		flags->word = 1;
		while (*(*str + 1) == **str)
		{
			++redir_len;
			++*str;
		}
		if (**str == '<' && redir_len > 1)
			flags->heredoc = 1;
		++*str;
		while (**str == ' ')
			++*str;
		return (0);
	}
	return (1);
}

int	special_len(char **str, int *word_len)
{
	if (**str == '&' || **str == '|')
	{
		++*word_len;
		while (*(*str + 1) == **str)
		{
			++*word_len;
			++*str;
		}
		++*str;
		return (0);
	}
	if (**str == '(' || **str == ')')
	{
		++*word_len;
		++*str;
		return (0);
	}
	return (1);
}

int	find_word_len(char **str)
{
	int			word_len;
	t_par_flags	flags;

	init_flags(&flags);
	word_len = 0;
	if (special_len(str, &word_len) == 0)
		return (word_len);
	while (qoat_processing(**str, &flags) == 0)
	{
		flags.word = 1;
		++*str;
	}
	if (flags.s_qoat == 0 && flags.d_qoat == 0)
		redirect_len(str, &flags);
	while (is_eow(**str, &flags) == 0)
	{
		if (qoat_processing(**str, &flags) != 0 && \
			env_var_processing(str, g_glob.envp, &word_len, &flags) != 0)
			++word_len;
		++*str;
	}
	if (word_len > 0 || flags.word == 1)
		return (word_len);
	return (-1);
}
