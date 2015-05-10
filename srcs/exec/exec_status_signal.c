/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_status_signal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 00:21:14 by juloo             #+#    #+#             */
/*   Updated: 2015/05/10 11:50:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "msg.h"
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

t_bool			exec_status_signal(t_msh *sh, t_cmd *cmd, int status)
{
	int				s;

	s = WTERMSIG(status);
	if (s >= 0 && s < 32)
	{
		P(W_SIGNAL, cmd->argv.data[0]);
		if (g_signals[s][0] == '\0')
			P(W_SIGNAL_NO, s);
		else
			PS(g_signals[s]);
		if (WCOREDUMP(status))
			PS(W_COREDUMP);
		NL;
	}
	return (false);
	(void)sh;
}
