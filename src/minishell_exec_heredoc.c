/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_heredoc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:59:38 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:59:41 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_heredoc_file_name(int heredoc_counter)
{
	char	*result;
	char	*heredoc_counter_str;
	int		heredoc_mem_len;

	heredoc_counter_str = ft_itoa(heredoc_counter);
	heredoc_mem_len = ft_strlen(HEREDOC_FILE_NAME) \
								+ ft_num_amount(heredoc_counter) + 1;
	result = (char *)exit_malloc(sizeof(char) * \
	(heredoc_mem_len));
	ft_strlcpy(result, HEREDOC_FILE_NAME, heredoc_mem_len);
	ft_strlcat(result, heredoc_counter_str, heredoc_mem_len);
	free(heredoc_counter_str);
	return (result);
}

int	write_heredoc(t_comm *command, int heredoc_counter)
{
	int		fd;
	char	*line;
	char	*heredoc_file_name;

	heredoc_file_name = get_heredoc_file_name(heredoc_counter);
	fd = open(heredoc_file_name, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		ft_err_str(3, "minishell", "can't create file", HEREDOC_FILE_NAME);
		return (-1);
	}
	line = readline(">");
	while (ft_strcmp(line, command->str) != 0)
	{
		ft_putstr_fd(line, fd);
		ft_putchar_fd('\n', fd);
		free(line);
		line = readline(">");
	}
	free(line);
	free(command->str);
	command->str = heredoc_file_name;
	close(fd);
	return (0);
}
