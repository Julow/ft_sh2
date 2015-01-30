/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:50:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/30 18:05:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

void			cmd_init(t_cmd *cmd)
{
	ft_arrayini(&(cmd->argv));
	ft_tabini(&(cmd->redirs));
}

void			cmd_kill(t_cmd *cmd)
{
	int				i;

	if (cmd == NULL)
		return ;
	i = -1;
	while (++i < cmd->redirs.length)
	{
		if (cmd->redirs.data[i].type == REDIR_PIPE)
			cmd_kill(cmd->redirs.data[i].cmd);
	}
	free(cmd->redirs.data);
	ft_arrayclr(&(cmd->argv), &free);
	free(cmd->argv.data);
}
