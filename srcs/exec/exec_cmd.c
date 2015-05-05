/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 17:50:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/05 16:44:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdlib.h>
#include <unistd.h>

static t_bool	exec_pipe(t_msh *sh, t_cmd *cmd)
{
	int				fds[2];

	if (pipe(fds) < 0)
		return (ft_fdprintf(2, SH ": Cannot pipe\n"), false);
	if (!exec_cmd(sh, cmd->next, PIPE_OUT(fds)))
		return (false);
	dup2(PIPE_IN(fds), 0);
	return (true);
}

t_bool			exec_cmd(t_msh *sh, t_cmd *cmd, int output)
{
	pid_t			pid;
	int				status;

	if ((pid = fork()) < 0)
		return (ft_fdprintf(2, SH ": Cannot fork\n"), false);
	else if (pid == 0)
	{
		if (cmd->next_t == NEXT_PIPE && !exec_pipe(sh, cmd))
			exit(1);
		if (output >= 0)
			dup2(1, output);
		execve((char*)cmd->argv.data[0], (char**)cmd->argv.data, (char**)sh->env.data);
		ft_fdprintf(2, SH ": %s: Cannot exec\n", cmd->argv.data[0]);
		exit(127);
	}
	status = 0;
	if (output < 0)
		waitpid(pid, &status, 0);
	ft_printf(SH ": Process %s end: %d\n", cmd->argv.data[0], status);
	// && || ;
	return (true);
}
