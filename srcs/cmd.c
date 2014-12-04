/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:59:06 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/03 14:59:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void			parse_line(t_sh *sh, char *line)
{
	char			**cmds;
	t_cmd			cmd;
	int				i;

	cmds = ft_strsplit(line, ';');
	i = -1;
	while (cmds[++i] != NULL)
	{
		cmd.argv = ft_strsplit(cmds[i], ' ');
		cmd.argc = ft_tablen((void**)cmd.argv);
		if (cmd.argc > 0)
		{
			if (!exec_builtin(sh, &cmd))
				exec_cmd(sh, &cmd);
		}
		ft_tabkil((void**)cmd.argv);
	}
}

void			exec_cmd(t_sh *sh, t_cmd *cmd)
{
	int				i;

	ft_putendl(cmd->argv[0]);
	i = 0;
	while (++i < cmd->argc)
	{
		ft_putstr(cmd->argv[i]);
		ft_putchar(((i + 1) < cmd->argc) ? ',' : '\n');
	}
	/*
	** find cmd->argv[0] execve
	*/
	(void)sh;
}
