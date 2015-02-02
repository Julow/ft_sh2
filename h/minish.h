/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:19:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/02 12:17:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include "libft.h"

typedef struct	s_redir
{
	int				fd[2];
	int				type;
	t_string		data;
	struct s_cmd	*cmd;
}				t_redir;

typedef struct	s_cmd
{
	t_array			argv;
	t_tab			redirs;
}				t_cmd;

typedef struct	s_sh
{
	t_array			env;
	int				last_ret;
}				t_sh;

typedef struct	s_builtin
{
	char			*name;
	int				(*func)(t_sh *sh, const t_cmd *cmd);
}				t_builtin;

typedef struct	s_sub
{
	char			*str;
	int				pos;
	int				length;
}				t_sub;

# define SUB(s,i,l)		((t_sub){(s), (i), (l)})

# define DEF_PS1		"%v$ "
# define DEF_PS2		"> "
# define DEF_PATH		"/bin:/usr/bin"

# define ACCESS_OK		0
# define ACCESS_NO		1
# define ACCESS_DIR		2
# define ACCESS_RIGHT	3

# define BG				ft_buffget
# define BI(b)			((b).i < (b).length)

# define REDIR_NONE		0
# define REDIR_IN		1
# define REDIR_PIPE		2
# define REDIR_FILE		3
# define REDIR_APPEND	4
# define REDIR_HEREDOC	5
# define REDIR_COLON	6

/*
** sh.c
*/
t_sh			*init_sh(void);
void			update_sh(t_sh *sh);
void			start_sh(t_sh *sh);

/*
** cmd.c
*/
void			exec_line(t_sh *sh, t_buff *line);

/*
** ft_access.c
*/
t_bool			access_error(const char *file);
int				ft_access(const char *file);

/*
** ps1.c
*/
void			print_ps1(t_sh *sh);
void			print_ps2(t_sh *sh);
void			print_motd(void);

/*
** builtin*
*/
t_bool			exec_builtin(t_sh *sh, const t_cmd *cmd);
int				builtin_cd(t_sh *sh, const t_cmd *cmd);
int				builtin_exit(t_sh *sh, const t_cmd *cmd);
int				builtin_env(t_sh *sh, const t_cmd *cmd);
int				builtin_setenv(t_sh *sh, const t_cmd *cmd);
int				builtin_unsetenv(t_sh *sh, const t_cmd *cmd);
int				builtin_printenv(t_sh *sh, const t_cmd *cmd);
int				builtin_help(t_sh *sh, const t_cmd *cmd);
int				builtin_echo(t_sh *sh, const t_cmd *cmd);
int				builtin_eval(t_sh *sh, const t_cmd *cmd);
int				builtin_pwd(t_sh *sh, const t_cmd *cmd);
int				builtin_true(t_sh *sh, const t_cmd *cmd);
int				builtin_false(t_sh *sh, const t_cmd *cmd);

/*
** utils.c
*/
inline t_bool	is_special(char c);
inline t_bool	ft_buffis(t_buff *buff, char c);
void			exit_err(const char *err);
t_string		ft_parsesubnf(t_buff *buff, t_bool (*f)(char c));

/*
** env_utils.c
*/
char			*get_env(t_sh *sh, const char *key);
void			set_env_line(t_sh *sh, const char *line);
void			set_env(t_sh *sh, const char *key, const char *value);

/*
** cmd_utils.c
*/
void			cmd_init(t_cmd *cmd);
void			cmd_kill(t_cmd *cmd);

/*
** path.c
*/
char			*search_path(t_sh *sh, const char *cmd);

/*
** parse_line.c
*/
t_cmd			*parse_line(t_sh *sh, t_buff *line);

/*
** parse_arg.c
*/
void			parse_arg(t_sh *sh, t_buff *line, t_cmd *cmd);

/*
** heredoc.c
*/
void			parse_heredoc(t_sh *sh, t_buff *line, t_cmd *cmd);

/*
** parse_redir.c
*/
void			parse_redir(t_sh *sh, t_buff *line, t_cmd *cmd);

#endif
