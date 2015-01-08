/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:19:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 15:39:48 by jaguillo         ###   ########.fr       */
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

# define DEF_PS1	"%v$ "
# define DEF_PATH	"/bin:/usr/bin"

/*
** cmd.c
*/
void			exec_line(t_sh *sh, const char *line);

/*
** ps1.c
*/
void			print_ps1(t_sh *sh, const char *ps1);

/*
** builtins.c
*/
t_bool			exec_builtin(t_sh *sh, const t_cmd *cmd);
void			builtin_cd(t_sh *sh, const t_cmd *cmd);
void			builtin_exit(t_sh *sh, const t_cmd *cmd);
void			builtin_env(t_sh *sh, const t_cmd *cmd);

/*
** utils.c
*/
char			*get_env(t_sh *sh, const char *key);
void			set_env(t_sh *sh, const char *key, const char *value);
void			exit_err(const char *err);

/*
** ftutils.c
*/
t_bool			ft_strcase(const char *s1, const char *s2);
t_bool			ft_strncase(const char *s1, const char *s2, t_uint n);
t_array			*ft_arraydup(const t_array *array);

/*
** parse_line.c
*/
void			cmd_kill(t_cmd *cmd);
void			parse_line(t_sh *sh, t_tab *cmds, const char *line);

#endif
