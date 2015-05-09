/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 17:50:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/10 00:35:11 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

static t_bool	exec_next(t_msh *sh, t_cmd *cmd, t_bool status)
{
	t_next_type		t;

	if ((t = cmd->next_t) == NEXT_NOPE)
		return (true);
	cmd = cmd->next;
	if (t == NEXT_AND)
		return ((status) ? exec_cmd(sh, cmd) : exec_next(sh, cmd, status));
	else if (t == NEXT_OR)
		return ((status) ? exec_next(sh, cmd, !status) : exec_cmd(sh, cmd));
	return (exec_cmd(sh, cmd));
}

t_bool			exec_cmd(t_msh *sh, t_cmd *cmd)
{
	pid_t			pid;
	int				status;
	char			*cmd_name;

	if ((pid = fork()) < 0)
		return (ft_fdprintf(2, SH ": Cannot fork\n"), false);
	else if (pid == 0)
	{
		if (!exec_redirs(sh, cmd))
			exit(127);
		if ((cmd_name = search_cmd(sh, cmd)) == NULL)
			exit(1);
		execve(cmd_name, (char**)cmd->argv.data, (char**)sh->env.data);
		ft_fdprintf(2, SH ": %s: Cannot exec\n", cmd->argv.data[0]);
		exit(127);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		return (exec_status_signal(sh, cmd, status));
	return (exec_next(sh, cmd, RSTATUS(status)));
}
