/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 17:49:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/05 13:55:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minish.h"

/*
** Types
*/
typedef enum	e_next_type
{
	NEXT_COLON,
	NEXT_AND,
	NEXT_OR,
	NEXT_PIPE,
	NEXT_NOPE
}				t_next_type;

typedef enum	e_redir_type
{
	REDIR_LEFT,
	REDIR_HEREDOC,
	REDIR_RIGHT,
	REDIR_APPEND,
	REDIR_NOPE
}				t_redir_type;

typedef struct	s_redir
{
	int				fd[2];
	char			*data;
	t_redir_type	redir_t;
}				t_redir;

typedef struct	s_cmd
{
	t_array			argv;
	t_tab			redirs;
	t_next_type		next_t;
	struct s_cmd	*next;
}				t_cmd;

typedef struct	s_builtin
{
	char			*name;
	int				(*f)(t_msh *sh, const t_cmd *cmd);
}				t_builtin;

/*
** Public
*/
void			exec_line(t_msh *sh, t_sub *line);

/*
** Internal
*/
void			exec_cmd(t_msh *sh, t_cmd *cmd);

/*
** Utils
*/
t_cmd			*cmd_new(void);
void			cmd_destroy(t_cmd *cmd);

#endif
