/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 17:50:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/08 23:51:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

const char		*g_signals[] = {
	"",
	"Hangup",
	"",
	"Quit",
	"Illegal instruction",
	"Trace/BPT trap",
	"Abort",
	"EMT trap",
	"Floating point exception",
	"Killed",
	"Bus error",
	"Segmentation fault",
	"Bad system call",
	"",
	"Alarm clock",
	"Terminated",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"Cputime limit exceeded",
	"Filesize limit exceeded",
	"Virtual timer expired",
	"Profiling timer expired",
	"",
	"",
	"User defined signal 1",
	"User defined signal 2",
	NULL
};

static t_bool	exec_error_signal(t_msh *sh, t_cmd *cmd, int status)
{
	int				s;

	s = WTERMSIG(status);
	if (s >= 0 && s < 32)
	{
		P(SH ": %s: ", cmd->argv.data[0]);
		if (g_signals[s][0] == '\0')
			P("Kill by signal %d", s);
		else
			P("%s", g_signals[s], s);
		if (WCOREDUMP(status))
			PS(" (core dump)");
		NL;
	}
	return (false);
	(void)sh;
}

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

	if ((pid = fork()) < 0)
		return (ft_fdprintf(2, SH ": Cannot fork\n"), false);
	else if (pid == 0)
	{
		execve((char*)cmd->argv.data[0], (char**)cmd->argv.data, (char**)sh->env.data);
		ft_fdprintf(2, SH ": %s: Cannot exec\n", cmd->argv.data[0]);
		exit(127);
	}
	waitpid(pid, &status, 0);
	ft_printf(SH ": Process %s end: %d\n", cmd->argv.data[0], status);
	if (WIFSIGNALED(status))
		return (exec_error_signal(sh, cmd, status));
	return (exec_next(sh, cmd, RSTATUS(status)));
}
