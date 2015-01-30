/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 21:37:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/30 21:53:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <fcntl.h>

void			parse_redir_pipe(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_redir			*tmp;

	if (ft_buffis(line, '|'))
	{
		tmp = ft_tabadd0(&(cmd->redirs));
		ft_bzero(tmp, sizeof(t_redir)); // to remove
		tmp->cmd = MAL1(t_cmd);
		parse_cmd(sh, line, tmp->cmd);
	}
}

void			parse_redir_in(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_redir			*tmp;

	if (ft_buffis(line, '<'))
	{
		if (ft_buffis(line, '<'))
			parse_heredoc(sh, line, cmd);
		else
		{
			tmp = ft_tabadd0(&(cmd->redirs));
			ft_bzero(tmp, sizeof(t_redir)); // to remove
			tmp->type = REDIR_IN;
			// TODO
		}
	}
}

void			parse_redir_out(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_redir			*tmp;

	if (ft_buffis(line, '>'))
	{
		tmp = ft_tabadd0(&(cmd->redirs));
		ft_bzero(tmp, sizeof(t_redir)); // to remove
		tmp->type = (ft_buffis(line, '>')) ? REDIR_APPEND : REDIR_FILE;
		ft_parsespace(line);
		tmp->data = ft_parsesubnf(line, &is_special);
		ft_parsespace(line);
		tmp->fd[0] = open(tmp->data.content, O_WRONLY | O_CREAT
			| (tmp->type == REDIR_APPEND) ? O_APPEND : O_TRUNC);
	}
	(void)sh;
}
