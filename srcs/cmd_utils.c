/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:50:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/30 22:21:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <unistd.h>

void			cmd_init(t_cmd *cmd)
{
	ft_arrayini(&(cmd->argv));
	ft_tabini(&(cmd->redirs), sizeof(t_redir));
}

void			redir_kill(t_redir *redir)
{
	if (redir->type == REDIR_PIPE)
		cmd_kill(redir->cmd);
	if (redir->type == REDIR_FILE || redir->type == REDIR_APPEND
		|| redir->type == REDIR_HEREDOC || redir->type == REDIR_IN)
		free(redir->data.content);
	if (redir->type == REDIR_FILE || redir->type == REDIR_APPEND)
		close(redir->fd[0]);
}

void			cmd_kill(t_cmd *cmd)
{
	int				i;

	if (cmd == NULL)
		return ;
	i = -1;
	while (++i < cmd->redirs.length)
		redir_kill(&TG(t_redir, &(cmd->redirs.data), i));
	free(cmd->redirs.data);
	ft_arrayclr(&(cmd->argv), &free);
	free(cmd->argv.data);
}
