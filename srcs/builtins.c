/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:19:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 18:40:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

/*
** TODO:
** false
** true
** builtin
** return
** sleep
** wait
** printenv(arg)
*/

const t_builtin	g_builtins[] = {
	{"cd", &builtin_cd},
	{"chdir", &builtin_cd},
	{"exit", &builtin_exit},
	{"env", &builtin_env},
	{"setenv", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"printenv", &builtin_printenv},
	{"help", &builtin_help},
	{"echo", &builtin_echo},
	{"eval", &builtin_eval},
	{"pwd", &builtin_pwd},
	{NULL, NULL}
};

t_bool			exec_builtin(t_sh *sh, const t_cmd *cmd)
{
	int				i;

	i = -1;
	while (g_builtins[++i].name != NULL)
	{
		if (ft_strcase(g_builtins[i].name, cmd->argv.data[0]))
		{
			sh->last_ret = g_builtins[i].func(sh, cmd);
			return (true);
		}
	}
	return (false);
}
