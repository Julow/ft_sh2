/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:19:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 13:41:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

t_builtin		g_builtins[] = {
	{"cd", &builtin_cd},
	{"exit", &builtin_exit},
	{"env", &builtin_env},
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
