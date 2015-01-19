/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:50:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/19 17:18:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

void			cmd_init(t_cmd *cmd)
{
	ft_arrayini(&(cmd->argv));
	cmd->pipe = NULL;
	cmd->redir = (t_redir){-1, REDIR_NONE};
}

void			cmd_kill(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	cmd_kill(cmd->pipe);
	ft_arrayclr(&(cmd->argv), &free);
	free(cmd->argv.data);
}
