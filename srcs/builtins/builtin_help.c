/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/18 00:31:02 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "msg.h"

int				builtin_help(t_msh *sh, int argc, char **argv)
{
	PS(SH
	"\n"
	"env [-i] [VAR=... [...]] [cmd]  Eval 'cmd' (printenv) with a modified env"
	"\nsetenv <name> <value>           Set a variable in the env"
	"\nunsetenv <name> [...]           Unset a variable from the env"
	"\ncd [-|path]                     Change directory"
	"\nchdir [-|path]                  Alias for 'cd'"
	"\nhelp                            Print this"
	"\nexport [VAR=... [...]]          Export variables to the env"
	"\necho [text [...]]               Echo text"
	"\nexit [status]                   Exit the shell"
	"\neval [cmd ...]                  Eval 'cmd'"
	"\nfalse                           Return false"
	"\ntrue                            Return true"
	"\npwd                             Print current working directory"
	"\nprintenv [name [...]]           Print the env variables"
	"\nbuiltin                         Print builtins list"
	"\nreturn [status]                 Return 'status'"
	"\nsleep <sec>                     Sleep"
	"\nsortw [-|file [...]]            Apply ordalphlong to the files or stdin"
	"\nrand [[min] max]                Print a rand int between 'min' and 'max'"
	"");
	NL;
	return (0);
	(void)sh;
	(void)argc;
	(void)argv;
}
