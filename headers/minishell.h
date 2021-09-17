/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:05:21 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 13:05:28 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdarg.h>
# include <string.h>
# include <dirent.h>
# include <signal.h>
# include "libft.h"
# define PWD_VAR "PWD"
# define OLDPWD_VAR "OLDPWD"
# define PATH_VAR "PATH"
# define SHLVL_VAR "SHLVL"
# define COMMAND 'c'
# define INPUT 'i'
# define OUTPUT 'o'
# define APPEND 'a'
# define HEREDOC 'h'
# define LOGIC 'l'
# define PIPE 'p'
# define BRACKETS 'b'
# define WILDCARD '*'
# define WILDCARD_REPLACE -126
# define HEREDOC_FILE_NAME ".heredoc"

typedef struct s_par_flags
{
	int	word;
	int	d_qoat;
	int	s_qoat;
	int	heredoc;
	int	parenthesis;
	int	redirect;
}				t_par_flags;

typedef struct s_word
{
	char	*start;
	int		word_len;
}				t_word;

typedef struct s_global
{
	char	**envp;
	int		status;
	char	*prompt;
}				t_global;

typedef struct s_comm
{
	char	*str;
	char	type;
}				t_comm;

t_global	g_glob;

char	**clone_str_array(char **str_array);
int		ft_env(char **envp);
int		ft_export(char ***envp, char **parp);
int		env_name_cmp(const char *s1, const char *s2);
void	print_str_arr_as_export(char **str_array);
void	free_str_array(char **str_array);
int		set_env_value(char ***envp, char *str_var, int type);
int		ft_unset(char ***envp, char **parp);
int		ft_pwd(void);
int		ft_echo(char **parp);
int		ft_cd(char ***envp, char **parp);
int		ft_exit(char **parp);
int		ft_exit_atoi(const char *str, long long *result);
t_comm	*parser(char *s);
void	free_result(t_comm *result);
void	init_flags(t_par_flags *flags);
int		is_eow(char c, t_par_flags *flags);
int		qoat_processing(char c, t_par_flags *flags);
int		find_word_amount(char const *s);
int		full_res(t_comm *res, char *s);
int		find_word_len(char **str);
int		env_var_processing(char **s, char **envp, \
											int *word_len, t_par_flags *flags);
int		ret_len_processing(char **s, int *word_len);
int		write_ret(char **dst, char **src);
char	*get_env_value(char **envp, char *env_name);
int		write_env(char **dst, char **src, char **envp, t_par_flags *flags);
void	write_word(char *dst, char *src, char **envp);
int		check_commands(t_comm *commands);
int		exec_all(t_comm *commands);
int		call_command(t_comm *commands, char ***envp);
int		exec_pipe(t_comm *commands, t_comm *next_comm);
int		exec_commands(t_comm *commands);
char	**comm_to_str_array(t_comm *commands);
int		redirect(t_comm *command);
int		d_input(t_comm *command);
int		s_input(t_comm *command);
int		new_env_check(char *str);
void	ft_err_str(int str_amt, ...);
void	ft_error_ms_str_errno(char *filename, int ft_errno);
void	ft_unexp_token(char c);
void	*exit_malloc(unsigned int size);
void	set_prompt(void);
void	set_null(t_comm *comm);
char	**get_file_list(void);
int		extend_wildcard(t_comm *comm, t_comm **extend_comm);
int		wildcard_var_amnt(char **file_list, t_comm *pattern);
int		size_of_comm_arr(t_comm *comm);
int		is_wildcard(t_comm *command);
int		wildcard_cmp(const char *pattern, const char *str);
void	write_wildcard_extend(t_comm *new_arr, t_comm *comm, char **file_list);
int		wildcard_redirect_amnt(char **file_list, t_comm *comm, int *full_amnt);
int		wildcard_heredoc_amnt(int *full_amnt);
int		wildcard_comm_amnt(char **file_list, t_comm *comm, int *full_amnt);
int		write_heredoc(t_comm *command, int heredoc_counter);
void	print_comms(t_comm *commands);
int		fork_call_commands(t_comm *t_commands);
void	active_parent(void);
void	passive_parent(void);
void	active_child(void);
char	put_char_wild(char c, t_par_flags *flags);
void	rm_replacement(char *str);
void	set_shlvl(void);
void	ignore_all(void);
int		check_unexp_position(t_comm *commands);
void	call_execve_child(char *exe_path, char **commands, \
							char **envp, int *status);
void	my_sig_int_holder(int signal);
void	child_exit(int signal);
void	call_execve_parent(char *exe_path, int *status);

#endif
