/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 00:22:09 by juloo             #+#    #+#             */
/*   Updated: 2015/05/25 17:28:31 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "msg.h"
#include <unistd.h>
#include <fcntl.h>

static t_bool	exec_redir_right(t_redir *redir)
{
	int				fd_new;
	int				fd_old;

	fd_new = (redir->fd_left < 0) ? 1 : redir->fd_left;
	if (redir->data == NULL)
		fd_old = redir->fd_right;
	else if (redir->redir_t == REDIR_APPEND)
		fd_old = exec_open(redir->data, APPEND_O);
	else
		fd_old = exec_open(redir->data, CREATE_O);
	if (fd_old < 0)
		return (false);
	if (dup2(fd_old, fd_new) < 0)
		return (ft_fdprintf(2, E_DUP2, fd_old), false);
	return (true);
}

static t_bool	exec_redir_left(t_redir *redir)
{
	int				fd_new;
	int				fd_old;

	fd_new = (redir->fd_left < 0) ? 0 : redir->fd_left;
	if (redir->data == NULL)
		fd_old = redir->fd_right;
	else
		fd_old = exec_open(redir->data, READ_O);
	if (fd_old < 0)
		return (false);
	if (dup2(fd_old, fd_new) < 0)
		return (ft_fdprintf(2, E_DUP2, fd_new), false);
	return (true);
}

static t_bool	exec_redir_heredoc(t_redir *redir)
{
	int				fd[2];

	if (redir->data == NULL || pipe(fd) < 0)
		return (false);
	dup2(PIPE_OUT(fd), (redir->fd_left < 0) ? 0 : redir->fd_left);
	write(PIPE_IN(fd), redir->data, ft_strlen(redir->data));
	close(PIPE_IN(fd));
	return (true);
}

static t_bool	exec_redir(t_redir *redir)
{
	if (redir->redir_t == REDIR_RIGHT || redir->redir_t == REDIR_APPEND)
		return (exec_redir_right(redir));
	if (redir->redir_t == REDIR_LEFT)
		return (exec_redir_left(redir));
	if (redir->redir_t == REDIR_HEREDOC)
		return (exec_redir_heredoc(redir));
	return (true);
}

t_bool			exec_redirs(t_msh *sh, t_cmd *cmd)
{
	return (ft_tabiter(&(cmd->redirs), &exec_redir, NULL));
	(void)sh;
}
