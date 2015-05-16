/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_nofork.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 17:57:06 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 19:04:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

const t_blt		g_builtinsb[] = {
	{"cd", &builtinb_cd},
	{"unsetenv", &builtinb_unsetenv},
	{"setenv", &builtinb_setenv},
	{"export", &builtinb_export},
	{"chdir", &builtinb_cd},
	{"exit", &builtinb_exit},
	{NULL, NULL}
};

void			exec_builtin_nofork(t_msh *sh, t_cmd *cmd)
{
	int				i;

	i = -1;
	while (g_builtinsb[++i].name != NULL)
		if (ft_strequ(g_builtinsb[i].name, cmd->argv.data[0]))
		{
			g_builtinsb[i].f(sh, cmd->argv.length, (char**)cmd->argv.data);
			break ;
		}
}
