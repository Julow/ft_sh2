/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 21:37:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/05 17:28:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <fcntl.h>

t_bool			parse_redir_colon(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_redir			*tmp;

	if (BIS(line, ';'))
	{
		tmp = ft_tabadd0(&(cmd->redirs));
		ft_bzero(tmp, sizeof(t_redir)); // to remove
		tmp->type = REDIR_COLON;
		tmp->cmd = parse_line(sh, line);
	}
	return (true);
}

t_bool			parse_redir_pipe(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_redir			*tmp;

	if (BIS(line, '|'))
	{
		tmp = ft_tabadd0(&(cmd->redirs));
		ft_bzero(tmp, sizeof(t_redir)); // to remove
		tmp->type = REDIR_PIPE;
		tmp->cmd = parse_line(sh, line);
	}
	return (true);
}

t_bool			parse_redir_out(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_redir			*tmp;

	if (BIS(line, '>'))
	{
		tmp = ft_tabadd0(&(cmd->redirs));
		ft_bzero(tmp, sizeof(t_redir)); // to remove
		tmp->type = (BIS(line, '>')) ? REDIR_APPEND : REDIR_OUT;
		ft_parsespace(line);
/* TODO
		if (tmp->type == REDIR_APPEND)
			parse_fd(sh, line, tmp, REDIR_APPEND_O);
		else
			parse_fd(sh, line, tmp, REDIR_OUT_O);
*/
	}
	(void)sh;
	return (true);
}
