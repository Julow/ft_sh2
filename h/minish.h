/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 18:45:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/10 17:30:04 by juloo            ###   ########.fr       */
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

# define DEFAULT_PATH	"/bin:/usr/bin"

# define STR(s)			#s
# define STR_VALUE(s)	STR(s)

# define VOID			((void)0)

char const		*get_env(t_msh *sh, char const *key, char const *def);
void			set_env(t_msh *sh, char const *key, char const *value);

int				ft_subnext(t_sub *sub, char c);

t_bool			ft_tabiter(t_tab *tab, t_bool (*f)(), void *data);

#endif
