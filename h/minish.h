/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:19:23 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/03 13:19:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include "libft.h"

typedef struct	s_cmd
{
	int				argc;
	char			**argv;
}				t_cmd;

typedef struct	s_sh
{
	char			*pwd;
}				t_sh;

typedef struct	s_builtin
{
	char			*name;
	void			(*func)(t_sh *sh, t_cmd *cmd);
}				t_builtin;

/*
** cmd.c
*/
void			parse_line(t_sh *sh, char *line);
void			exec_cmd(t_sh *sh, t_cmd *cmd);

/*
** builtins.c
*/
t_bool			exec_builtin(t_sh *sh, t_cmd *cmd);
void			builtin_cd(t_sh *sh, t_cmd *cmd);

/*
** utils.c
*/
void			ft_tabkil(void **tab);
void			exit_err(char *err);

#endif
