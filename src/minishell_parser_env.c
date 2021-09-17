/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:02:30 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:02:32 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_end_of_env(char c)
{
	if (c == '\0' || ft_isalnum(c) == 0)
		return (1);
	return (0);
}

int	write_env(char **dst, char **src, char **envp, t_par_flags *flags)
{
	char	*temp_p;
	char	temp_char;

	if (flags->s_qoat == 1 || **src != '$' || flags->heredoc == 1)
		return (1);
	if (write_ret(dst, src) == 0)
		return (0);
	temp_p = ++(*src);
	while (is_end_of_env(*(*src + 1)) == 0)
		++*src;
	temp_char = *(*src + 1);
	*(*src + 1) = '\0';
	temp_p = get_env_value(envp, temp_p);
	if (temp_p != NULL)
	{
		while (*temp_p != '\0')
		{
			**dst = *temp_p;
			++*dst;
			++temp_p;
		}
	}
	*(*src + 1) = temp_char;
	return (0);
}

int	get_env_len(char **envp, char *env_name)
{
	char	*env;

	while (*envp != NULL)
	{
		if (env_name_cmp(*envp, env_name) == 0)
		{
			env = *envp;
			while (*env != '=')
			{
				if (*env++ == '\0')
					return (0);
			}
			return (ft_strlen(++env));
		}
		++envp;
	}
	return (0);
}

char	*get_env_value(char **envp, char *env_name)
{
	char	*env;

	while (*envp != NULL)
	{
		if (env_name_cmp(*envp, env_name) == 0)
		{
			env = *envp;
			while (*env != '=')
			{
				if (*(env++) == '\0')
					return (NULL);
			}
			return (++env);
		}
		++envp;
	}
	return (NULL);
}

int	env_var_processing(char **s, char **envp, int *word_len, t_par_flags *flags)
{
	char	*env_name_start;
	char	temp_char;

	if (flags->s_qoat == 0 && flags->d_qoat == 0 && \
		**s == '$' && flags->heredoc == 0)
	{
		if (ft_isdigit(*(*s + 1)) == 1 || ret_len_processing(s, word_len) == 0)
		{
			++*s;
			return (0);
		}
		env_name_start = *s + 1;
		while (is_end_of_env(*(*s + 1)) == 0)
			++*s;
		temp_char = *(*s + 1);
		*(*s + 1) = '\0';
		*word_len += get_env_len(envp, env_name_start);
		*(*s + 1) = temp_char;
		return (0);
	}
	return (1);
}
