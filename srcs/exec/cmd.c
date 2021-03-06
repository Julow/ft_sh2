/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 19:23:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/05 13:30:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdlib.h>

t_cmd			*cmd_new(void)
{
	t_cmd			*cmd;

	cmd = MAL1(t_cmd);
	ft_arrayini(&(cmd->argv));
	ft_tabini(&(cmd->redirs), sizeof(t_redir));
	cmd->next_t = NEXT_NOPE;
	cmd->next = NULL;
	return (cmd);
}

void			cmd_destroy(t_cmd *cmd)
{
	ft_arrayclr(&(cmd->argv), &free);
	free(cmd->argv.data);
	free(cmd->redirs.data);
	if (cmd->next != NULL)
		cmd_destroy(cmd->next);
	free(cmd);
}
