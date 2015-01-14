/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:19:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/14 11:44:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include "libft.h"

typedef struct	s_cmd
{
	t_array			argv;
}				t_cmd;

typedef struct	s_sh
{
	t_array			env;
}				t_sh;

typedef struct	s_builtin
{
	char			*name;
	void			(*func)(t_sh *sh, const t_cmd *cmd);
}				t_builtin;

/*
** struct s_sub (t_sub) represent a substring
** 'str' do not point to the original malloc'd pointer (can't be free)
** 'str' is not NULL terminated
** 'str' can't be modified
*/
typedef struct	s_sub
{
	const char		*str;
	int				length;
}				t_sub;

# define SUB(s,l)		((t_sub){(s), (l)})

# define DEF_PS1		"%v$ "
# define DEF_PATH		"/bin:/usr/bin"

# define ACCESS_NO		1
# define ACCESS_DIR		2
# define ACCESS_RIGHT	3

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
void			print_ps1(t_sh *sh, const char *ps1);
void			print_motd(void);

/*
** builtin*
*/
t_bool			exec_builtin(t_sh *sh, const t_cmd *cmd);
void			builtin_cd(t_sh *sh, const t_cmd *cmd);
void			builtin_exit(t_sh *sh, const t_cmd *cmd);
void			builtin_env(t_sh *sh, const t_cmd *cmd);
void			builtin_setenv(t_sh *sh, const t_cmd *cmd);
void			builtin_unsetenv(t_sh *sh, const t_cmd *cmd);
void			builtin_help(t_sh *sh, const t_cmd *cmd);

/*
** utils.c
*/
void			exit_err(const char *err);

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
** search_file.c
*/
char			*search_file(t_sub sub, const char *name);

/*
** parse_line.c
*/
void			parse_line(t_sh *sh, t_tab *cmds, t_buff *line);

#endif
