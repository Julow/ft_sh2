/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:59:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 10:58:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static void		exec_cmd(t_sh *sh, const t_cmd *cmd)
{
	int				i;

	if (cmd->argv.length == 0)
		return ;
	if (exec_builtin(sh, cmd))
		return ;
	ft_putstr("exec: ");
	i = -1;
	while (++i < cmd->argv.length)
	{
		ft_putstr(cmd->argv.data[i]);
		ft_putstr("        ");
	}
	ft_putchar('\n');
}

void			exec_line(t_sh *sh, const char *line)
{
	t_tab			cmds;
	int				i;

	ft_tabini(&cmds, sizeof(t_cmd));
	parse_line(sh, &cmds, line);
	i = -1;
	while (++i < cmds.length)
	{
		exec_cmd(sh, &TG(t_cmd, &cmds, i));
		cmd_kill(&TG(t_cmd, &cmds, i));
	}
	free(cmds.data);
}
