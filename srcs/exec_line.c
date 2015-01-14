/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:59:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/14 11:44:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
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
	"Abort trap",
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
	"Stopped",
	"Stopped",
	"",
	"",
	"Stopped",
	"Stopped",
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

static void		handle_status(int status)
{
	int				sign;

	if (!WIFSIGNALED(status))
		return ;
	sign = WTERMSIG(status);
	if (sign >= 0 && sign < 32 && g_signals[sign][0] != '\0')
		ft_fdprintf(2, "ft_minishell1: %s: %d\n", g_signals[sign], sign);
}

static void		exec_bin(t_sh *sh, const char *file, const t_cmd *cmd)
{
	pid_t			pid;
	int				status;

	if (access_error(file))
		return ;
	if ((pid = fork()) < 0)
		ft_fdprintf(2, "ft_minishell1: %s: cannot create process\n", file);
	else if (pid == 0)
	{
		cmd->argv.data[cmd->argv.length] = NULL;
		sh->env.data[sh->env.length] = NULL;
		execve(file, (char**)(cmd->argv.data), (char**)(sh->env.data));
		ft_fdprintf(2, "ft_minishell1: %s: cannot execute binary file\n", file);
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		handle_status(status);
	}
}

static void		exec_cmd(t_sh *sh, const t_cmd *cmd)
{
	char			*path;
	char			*tmp;
	int				len;

	if (cmd->argv.length == 0 || exec_builtin(sh, cmd))
		return ;
	if (ft_strrchr(AG(char*, &(cmd->argv), 0), '/') != NULL)
		return (exec_bin(sh, AG(char*, &(cmd->argv), 0), cmd));
	if ((path = get_env(sh, "PATH=")) == NULL)
		set_env(sh, "PATH=", (path = DEF_PATH));
	while (*path != '\0')
	{
		len = ft_strcskipe(path, ":");
		tmp = search_file(SUB(path, len), AG(char*, &(cmd->argv), 0));
		if (tmp != NULL)
		{
			exec_bin(sh, tmp, cmd);
			free(tmp);
			return ;
		}
		path += len + 1;
	}
	ft_fdprintf(2, "ft_minishell1: command not found: %s\n",
		AG(char*, &(cmd->argv), 0));
}

void			exec_line(t_sh *sh, t_buff *line)
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
