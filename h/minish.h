/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 18:45:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/21 20:12:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include "libft.h"

/*
** ========================================================================== **
** Base
*/

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
	NEXT_PIPE
}				t_next_type;

typedef struct	s_cmd
{
	char			*name;
	t_array			argv;
	t_next_type		next_t;
	struct s_cmd	*next;
}				t_cmd;

typedef struct	s_builtin
{
	char			*name;
	int				(*f)(t_sh *sh, const t_cmd *cmd);
}				t_builtin;

#endif
