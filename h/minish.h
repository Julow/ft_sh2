/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 18:45:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/23 13:17:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include "libft.h"

/*
** ========================================================================== **
** TODO
** ----
** |
** < file
** <<
** > file
** >> file
** ;
** &&
** ||
** 0< file
** <&1
** 0<&1
** 0<<
** 0> file
** &> file
** >&0
** 1>&0
** 0>> file
** &>> file
** ----
** ""
** ''
** ""''
** ----
*/

/*
** ========================================================================== **
** Base
*/

typedef char	t_bp[64];

# define BP		((t_bp){[0 ... 63] = 0})

typedef struct	s_msh
{
	t_array			env;
	int				last_status;
}				t_msh;

/*
** ========================================================================== **
** Cmd
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
	int				(*f)(t_sh *sh, const t_cmd *cmd);
}				t_builtin;

t_cmd			cmd_new(void);
void			cmd_destroy(t_cmd *cmd);

#endif
