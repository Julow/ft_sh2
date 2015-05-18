/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 18:45:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/18 22:18:12 by juloo            ###   ########.fr       */
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
*/

/*
** ========================================================================== **
** Features
** ----
** == Builtins
**  env [-i] [VAR=... [...]] [cmd]  Eval 'cmd' (printenv) with a modified env
**  setenv <name> <value>           Set a variable in the env
**  unsetenv <name> [...]           Unset a variable from the env
**  cd [-|path]                     Change directory
**  chdir [-|path]                  Alias for 'cd'
**  help                            Print this
**  export [VAR=... [...]]          Export variables to the env
**  echo [text [...]]               Echo text
**  exit [status]                   Exit the shell
**  eval [cmd ...]                  Eval 'cmd'
**  false                           Return false
**  true                            Return true
**  pwd                             Print current working directory
**  printenv [name [...]]           Print the env variables
**  builtin                         Print builtins list
**  return [status]                 Return 'status'
**  sleep <sec>                     Sleep
**  sortw [-|file [...]]            Apply ordalphlong to the files or stdin
**  rand [[min] max]                Print a rand int between 'min' and 'max'
** == Args
**  [-i] [-v|-c "cmd"|"file"] [VAR=data [...]]
**  -v                              Print version and quit
**  -c "cmd"                        Execute 'cmd' and quit
**  "file"                          Execute each line of 'file' and quit
**  VAR=data						Add 'VAR=data' to the env variables
**  -i								Clear env variables
** ----
*/

typedef struct	s_msh
{
	t_array			env;
	int				flags;
	int				last_status;
}				t_msh;

typedef enum	e_error
{
	OK = 0,
	E_RIGHT,
	E_ISDIR,
	E_NOEXISTS
}				t_error;

# define DEFAULT_PATH	"/bin:/usr/bin"

# define STR(s)			#s
# define STR_VALUE(s)	STR(s)

# define VOID			((void)0)

char const		*get_env(t_msh *sh, char const *key, char const *def);
void			set_env(t_msh *sh, char const *key, char const *value);
void			export_env(t_msh *sh, char const *var);
void			unset_env(t_msh *sh, char const *key);

t_error			ft_access(char const *file, t_bool exec);

int				ft_subnext(t_sub *sub, char c);
int				ft_subnextf(t_sub *sub, t_bool (*f)(int c));

int				ft_countwords(char const *str);

t_bool			ft_tabiter(t_tab *tab, t_bool (*f)(), void *data);

#endif
