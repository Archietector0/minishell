/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:07:39 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:01:17 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	put_char_wild(char c, t_par_flags *flags)
{
	if (c == WILDCARD && flags->d_qoat == 0 && flags->s_qoat == 0)
		return (WILDCARD_REPLACE);
	return (c);
}

void	init_flags(t_par_flags *flags)
{
	flags->word = 0;
	flags->s_qoat = 0;
	flags->d_qoat = 0;
	flags->heredoc = 0;
	flags->redirect = 0;
}

void	free_result(t_comm *result)
{
	t_comm	*result_start;

	result_start = result;
	while (result->type != '\0')
	{
		if (result->str != NULL)
		{
			free(result->str);
			result->str = NULL;
		}
		++result;
	}
	free(result_start);
}

void	set_null(t_comm *comm)
{
	comm->str = NULL;
	comm->type = '\0';
}

t_comm	*parser(char *s)
{
	t_comm	*result;
	int		word_amount;

	if (s == NULL)
		return (NULL);
	word_amount = find_word_amount(s);
	if (word_amount < 0)
		return (NULL);
	result = (t_comm *)exit_malloc(sizeof(t_comm) * (word_amount + 1));
	if (full_res(result, s) != 0 || check_commands(result) != 0)
	{
		free_result(result);
		return (NULL);
	}
	return (result);
}
