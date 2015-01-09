/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:59:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 09:56:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

static char		*search_file(const char *path, int len, const char *name)
{
	DIR				*dir;
	struct dirent	*ent;
	t_string		file;

	ft_stringini(&file);
	ft_stringaddl(&file, path, len);
	dir = opendir(file.content);
	if (dir == NULL)
		return (NULL);
	while ((ent = readdir(dir)) != NULL)
		if (ft_strcase(ent->d_name, name))
		{
			ft_stringaddc(&file, '/');
			ft_stringadd(&file, ent->d_name);
			return (closedir(dir), file.content);
		}
	return (free(file.content), closedir(dir), NULL);
}

static void		exec_bin(t_sh *sh, const char *file, const t_cmd *cmd)
{
	pid_t			pid;
	struct stat		stat;

	if (lstat(file, &stat) < 0)
	{
		ft_putstr_fd("ft_minishell1: no such file or directory: ", 2);
		ft_putendl_fd(file, 2);
		return ;
	}
	if ((pid = fork()) < 0)
		ft_putstr_fd("ft_minishell1: fork: cannot create process.\n", 2);
	else if (pid == 0)
	{
		execve(file, (char**)(cmd->argv.data), (char**)(sh->env.data));
		ft_putstr_fd("ft_minishell1: cannot call '", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("'\n", 2);
		exit(0);
	}
	else
		waitpid(pid, NULL, 0);
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
		tmp = search_file(path, len, AG(char*, &(cmd->argv), 0));
		if (tmp != NULL)
		{
			exec_bin(sh, tmp, cmd);
			free(tmp);
			return ;
		}
		path += len + 1;
	}
	ft_putstr_fd("ft_minishell1: command not found: ", 2);
	ft_putstr_fd(AG(char*, &(cmd->argv), 0), 2);
	ft_putchar_fd('\n', 2);
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
