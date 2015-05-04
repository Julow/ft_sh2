/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 18:45:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/04 19:29:39 by jaguillo         ###   ########.fr       */
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
** "$
** '$
** \$
** {,}
** {...}
** ~
** ----
** env
** setenv
** unsetenv
** cd
** chdir
** help
** export
** echo
** exit
** eval
** false
** true
** pwd
** printenv [arg]
** builtin
** return
** sleep
** sortw
** rand
** ----
** [-v] [file [$1 ...]]
** [-c "cmd" [$0 $1 ...]]
** ----
*/

typedef struct	s_msh
{
	t_array			env;
	int				last_status;
}				t_msh;

# define SH				"ft_msh2"

# define DEF_REDIR_FD	0

#endif
