/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 22:54:14 by juloo             #+#    #+#             */
/*   Updated: 2015/05/15 23:16:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "exec.h"

/*
** Types
*/
typedef struct	s_builtin
{
	char const		*name;
	int				(*f)(t_msh *sh, int argc, char **argv);
}				t_builtin;

/*
** Public
*/
void			exec_builtin(t_msh *sh, t_cmd *cmd);

/*
** Internal
*/
int				builtin_echo(t_msh *sh, int argc, char **argv);
int				builtin_false(t_msh *sh, int argc, char **argv);
int				builtin_true(t_msh *sh, int argc, char **argv);
int				builtin_return(t_msh *sh, int argc, char **argv);
int				builtin_sleep(t_msh *sh, int argc, char **argv);

// TODO
int				builtin_sortw(t_msh *sh, int argc, char **argv);
int				builtin_rand(t_msh *sh, int argc, char **argv);
int				builtin_builtin(t_msh *sh, int argc, char **argv);
int				builtin_printenv(t_msh *sh, int argc, char **argv);
int				builtin_pwd(t_msh *sh, int argc, char **argv);
int				builtin_eval(t_msh *sh, int argc, char **argv);
int				builtin_exit(t_msh *sh, int argc, char **argv);
int				builtin_export(t_msh *sh, int argc, char **argv);
int				builtin_help(t_msh *sh, int argc, char **argv);
int				builtin_chdir(t_msh *sh, int argc, char **argv);
int				builtin_cd(t_msh *sh, int argc, char **argv);
int				builtin_unsetenv(t_msh *sh, int argc, char **argv);
int				builtin_setenv(t_msh *sh, int argc, char **argv);
int				builtin_env(t_msh *sh, int argc, char **argv);

#endif
