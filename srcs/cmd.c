/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 19:23:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/22 19:36:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

t_cmd			cmd_new(void)
{
	t_cmd			*cmd;

	cmd = MAL1(t_cmd);
	ft_arrayini(&(cmd->argv));
	cmd->next_t = NEXT_NOPE;
	cmd->next = NULL;
	return (cmd);
}

void			cmd_destroy(t_cmd *cmd)
{
	if (cmd->next != NULL)
		cmd_destroy(cmd);
	ft_arraykillf(&(cmd->argv));
}
