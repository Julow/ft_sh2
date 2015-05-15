/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 17:49:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/15 23:49:55 by juloo            ###   ########.fr       */
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
	int				fd_left;
	int				fd_right;
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

# define PIPE_IN(p)		(p[1])
# define PIPE_OUT(p)	(p[0])

# define RSTATUS(s)		((WIFEXITED(s) && WEXITSTATUS(s) == 0) ? true : false)

# define READ_O			O_RDONLY
# define CREATE_O		O_WRONLY | O_CREAT | O_TRUNC
# define APPEND_O		O_WRONLY | O_CREAT | O_APPEND
# define MODE_O			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH

/*
** Public
*/
void			exec_line(t_msh *sh, t_sub *line);

/*
** Internal
*/
t_bool			exec_cmd(t_msh *sh, t_cmd *cmd);
void			print_cmd(t_cmd *cmd);

t_bool			exec_redirs(t_msh *sh, t_cmd *cmd);
t_bool			exec_status_signal(t_msh *sh, t_cmd *cmd, int status);

int				exec_open(char const *str, int flags);

char			*search_cmd(t_msh *sh, t_cmd *cmd);

/*
** Utils
*/
t_cmd			*cmd_new(void);
void			cmd_destroy(t_cmd *cmd);

#endif
