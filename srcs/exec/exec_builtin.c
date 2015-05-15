/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 22:52:02 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 00:10:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <stdlib.h>

const t_builtin	g_builtins[] = {
	{"echo", &builtin_echo},
	{"false", &builtin_false},
	{"true", &builtin_true},
	{"return", &builtin_return},
	{"sleep", &builtin_sleep},
	{"sortw", &builtin_sortw},
	{"raise", &builtin_raise},
	{"rand", &builtin_rand},
	{"builtin", &builtin_builtin},
	{"printenv", &builtin_printenv},
	{"pwd", &builtin_pwd},
	{"eval", &builtin_eval},
	{"exit", &builtin_exit},
	{"export", &builtin_export},
	{"help", &builtin_help},
	{"chdir", &builtin_chdir},
	{"cd", &builtin_cd},
	{"unsetenv", &builtin_unsetenv},
	{"setenv", &builtin_setenv},
	{"env", &builtin_env},
	{NULL, NULL}
};

void			exec_builtin(t_msh *sh, t_cmd *cmd)
{
	int				i;

	i = -1;
	while (g_builtins[++i].name != NULL)
		if (ft_strequ(g_builtins[i].name, cmd->argv.data[0]))
			exit(g_builtins[i].f(sh, cmd->argv.length, (char**)cmd->argv.data));
}
