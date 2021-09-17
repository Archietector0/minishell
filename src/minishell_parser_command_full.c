/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_command_full.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:02:14 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:02:17 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_eow(char c, t_par_flags *flags)
{
	if ((c == '\0') || ((flags->s_qoat == 0 && flags->d_qoat == 0) && \
	(c == ' ' || \
	c == '>' || c == '<' || \
	c == '&' || c == '|' || \
	c == '(' || c == ')')))
		return (1);
	return (0);
}

int	redirect_write(t_word *word, t_par_flags *flags, char *type)
{
	if (*word->start == '<' || *word->start == '>')
	{
		if (*word->start == '<')
			*type = INPUT;
		else
			*type = OUTPUT;
		while (*(word->start + 1) == *word->start)
		{
			if (*word->start == '<')
			{
				flags->heredoc = 1;
				*type = HEREDOC;
			}
			else
				*type = APPEND;
			++word->start;
		}
		++word->start;
		while (*word->start == ' ')
			++word->start;
		return (0);
	}
	return (1);
}

int	special_write(t_word *word, char **result, char *type)
{
	if (*word->start == '&' || *word->start == '|')
	{
		if (*word->start == '|')
			*type = PIPE;
		else
			*type = LOGIC;
		while (*(word->start + 1) == *word->start)
		{
			*((*result)++) = *(word->start++);
			*type = LOGIC;
		}
		*((*result)++) = *(word->start++);
		return (0);
	}
	if (*word->start == '(' || *word->start == ')')
	{
		*type = BRACKETS;
		*((*result)++) = *(word->start++);
		return (0);
	}
	return (1);
}

t_comm	create_new_word(t_word *word)
{
	char		*result;
	t_comm		result_start;
	t_par_flags	flags;

	init_flags(&flags);
	result_start.type = COMMAND;
	result = (char *)exit_malloc(sizeof (char) * (word->word_len + 1));
	result_start.str = result;
	if (special_write(word, &result, &result_start.type) != 0)
	{
		while (qoat_processing(*word->start, &flags) == 0)
			++word->start;
		if (flags.s_qoat == 0 && flags.d_qoat == 0)
			redirect_write(word, &flags, &result_start.type);
		while (is_eow(*word->start, &flags) == 0)
		{
			if (qoat_processing(*word->start, &flags) != 0 && \
				write_env(&result, &word->start, g_glob.envp, &flags) != 0)
				*(result++) = put_char_wild(*(word->start++), &flags);
			else
				++word->start;
		}
	}
	*result = '\0';
	return (result_start);
}

int	full_res(t_comm *res, char *s)
{
	t_word		word;

	while (*s != '\0')
	{
		word.word_len = 0;
		while (*s == ' ')
			++s;
		word.start = s;
		word.word_len = find_word_len(&s);
		if (word.word_len >= 0)
		{
			*res = create_new_word(&word);
			if ((res++)->str == NULL)
				return (-1);
		}
	}
	return (0);
}
