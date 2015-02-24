/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:50:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/25 00:12:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <unistd.h>

void			cmd_init(t_cmd *cmd)
{
	ft_bzero(cmd, sizeof(t_cmd));
	ft_arrayini(&(cmd->argv));
	ft_tabini(&(cmd->redirs), sizeof(t_redir));
}

void			redir_kill(t_redir *redir)
{
	free(redir->data.content);
}

void			cmd_kill(t_cmd *cmd)
{
	int				i;

	if (cmd == NULL)
		return ;
	i = -1;
	while (++i < cmd->redirs.length)
		redir_kill(TG(t_redir, cmd->redirs.data, i));
	free(cmd->redirs.data);
	ft_arrayclr(&(cmd->argv), &free);
	free(cmd->argv.data);
	if (cmd->next.cmd != NULL)
		cmd_kill(cmd->next.cmd);
	free(cmd);
}
