/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 21:37:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/03 18:39:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <fcntl.h>

static void		parse_redir_colon(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_redir			*tmp;

	if (ft_buffis(line, ';'))
	{
		tmp = ft_tabadd0(&(cmd->redirs));
		ft_bzero(tmp, sizeof(t_redir)); // to remove
		tmp->type = REDIR_COLON;
		tmp->cmd = parse_line(sh, line);
	}
}

static void		parse_redir_pipe(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_redir			*tmp;

	if (ft_buffis(line, '|'))
	{
		tmp = ft_tabadd0(&(cmd->redirs));
		ft_bzero(tmp, sizeof(t_redir)); // to remove
		tmp->type = REDIR_PIPE;
		tmp->cmd = parse_line(sh, line);
	}
}

static void		parse_redir_in(t_sh *sh, t_buff *line, t_cmd *cmd)
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
			parse_fd(sh, line, tmp, O_RDONLY);
		}
	}
}

static void		parse_redir_out(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_redir			*tmp;

	if (ft_buffis(line, '>'))
	{
		tmp = ft_tabadd0(&(cmd->redirs));
		ft_bzero(tmp, sizeof(t_redir)); // to remove
		tmp->type = (ft_buffis(line, '>')) ? REDIR_APPEND : REDIR_FILE;
		ft_parsespace(line);
		parse_fd(sh, line, tmp, O_WRONLY | O_CREAT
			| (tmp->type == REDIR_APPEND) ? O_APPEND : O_TRUNC);
	}
}

void			parse_redir(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	while (BI(*line))
	{
		if (BG(line) == '<')
			parse_redir_in(sh, line, cmd);
		else if (BG(line) == '>')
			parse_redir_out(sh, line, cmd);
		else if (BG(line) == '|')
			parse_redir_pipe(sh, line, cmd);
		else if (BG(line) == ';')
			parse_redir_colon(sh, line, cmd);
		else
			return ; // TODO: syntax error
		ft_parsespace(line);
	}
}
