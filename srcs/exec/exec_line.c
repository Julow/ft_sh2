/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:59:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/08 16:36:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/*
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
		ft_fdprintf(2, "ft_minishell2: %s: %d\n", g_signals[sign], sign);
}

static void		exec_bin(t_sh *sh, const char *file, const t_cmd *cmd)
{
	pid_t			pid;
	int				status;

	if (access_error(file))
		return ;
	if ((pid = fork()) < 0)
		ft_fdprintf(2, "ft_minishell2: %s: cannot create process\n", file);
	else if (pid == 0)
	{
		cmd->argv.data[cmd->argv.length] = NULL;
		sh->env.data[sh->env.length] = NULL;
		execve(file, (char**)(cmd->argv.data), (char**)(sh->env.data));
		ft_fdprintf(2, "ft_minishell2: %s: cannot execute binary file\n", file);
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
	char			*tmp;

	if (cmd->argv.length == 0 || exec_builtin(sh, cmd))
		return ;
	if (ft_strrchr(AG(char*, &(cmd->argv), 0), '/') != NULL)
		return (exec_bin(sh, AG(char*, &(cmd->argv), 0), cmd));
	tmp = search_path(sh, cmd->argv.data[0]);
	if (tmp != NULL)
	{
		exec_bin(sh, tmp, cmd);
		free(tmp);
		return ;
	}
	ft_fdprintf(2, "ft_minishell2: command not found: %s\n",
		AG(char*, &(cmd->argv), 0));
}
*/

static void		print_cmd(t_sh *sh, t_cmd *cmd)
{
	int				i;
	t_redir			*tmp;

	if (lex_cmd(sh, cmd))
	{
		i = -1;
		if (cmd->builtin)
			ft_printf("{green}builtin %s{eoc} ", AG(char*, &(cmd->argv), ++i));
		while (++i < cmd->argv.length)
			ft_printf("{dark}\"{eoc}%s{dark}\"{eoc} ", AG(char*, &(cmd->argv), i));
		i = -1;
		while (++i < cmd->redirs.length)
		{
			tmp = &TG(t_redir, &(cmd->redirs), i);
			if (tmp->type == REDIR_IN)
				ft_printf("{green}%d< {dark}%s{eoc} ", tmp->fd[0], tmp->data.content);
			else if (tmp->type == REDIR_OUT)
				ft_printf("{green}%d> {dark}%s{eoc} ", tmp->fd[0], tmp->data.content);
			else if (tmp->type == REDIR_APPEND)
				ft_printf("{green}%d>> {dark}%s{eoc} ", tmp->fd[0], tmp->data.content);
			else if (tmp->type == REDIR_HEREDOC)
				ft_printf("{green}%d<< {dark}\"{eoc}%s{dark}\"{eoc} ", tmp->fd[0], tmp->data.content);
			else
				ft_printf("{orange}lol{eoc} ");
		}
		if (cmd->async)
			ft_printf("{green}&{eoc} ");
	}
	else
		cmd->ret = 1;
	if (cmd->next.type != NEXT_NONE && cmd->next.cmd != NULL)
	{
		if (cmd->next.type == NEXT_PIPE)
			ft_printf("{green}|{eoc} ");
		else if (cmd->next.type == NEXT_COLON)
			ft_printf("{green};{eoc} ");
		else if (cmd->next.type == NEXT_AND)
			ft_printf("{green}&&{eoc} ");
		else if (cmd->next.type == NEXT_OR)
			ft_printf("{green}||{eoc} ");
		else
			ft_printf("{green}??{eoc} ");
		print_cmd(sh, cmd->next.cmd);
	}
}

void			exec_line(t_sh *sh, t_buff *line)
{
	t_cmd			*cmd;

	cmd = parse_line(sh, line);
	if (cmd == NULL)
		return ;
//	exec_cmd(sh, cmd);
	print_cmd(sh, cmd);
	ft_printf("\n");
	cmd_kill(cmd);
}
