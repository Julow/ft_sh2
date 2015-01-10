/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:19:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 20:31:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

const t_builtin	g_builtins[] = {
	{"cd", &builtin_cd},
	{"exit", &builtin_exit},
	{"env", &builtin_env},
	{"setenv", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"help", &builtin_help},
	{NULL, NULL}
};

t_bool			exec_builtin(t_sh *sh, const t_cmd *cmd)
{
	int				i;

	i = -1;
	while (g_builtins[++i].name != NULL)
	{
		if (ft_strequ(g_builtins[i].name, cmd->argv.data[0]))
		{
			g_builtins[i].func(sh, cmd);
			return (TRUE);
		}
	}
	return (FALSE);
}
