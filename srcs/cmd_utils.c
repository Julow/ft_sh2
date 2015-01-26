/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:50:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/26 23:31:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

void			cmd_init(t_cmd *cmd)
{
	ft_arrayini(&(cmd->argv));
	cmd->redir = (t_redir){-1, REDIR_NONE, false, NULL};
}

void			cmd_kill(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	cmd_kill(cmd->redir.next);
	ft_arrayclr(&(cmd->argv), &free);
	free(cmd->argv.data);
}
