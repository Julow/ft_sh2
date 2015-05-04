/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 13:05:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/04 18:33:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_bool	parse_redir_file(t_parser *p, t_redir *redir)
{
	int				fd;

	ft_parsespace(p->buff);
	if (BIS(p->buff, '&'))
	{
		if (!ft_parseint(p->buff, &fd))
			return (parse_error_expect(p, "fd"));
		redir->fd[1] = fd;
		return (true);
	}
	ft_stringclr(p->tmp);
	if (!ft_parsesubf(p->buff, p->tmp, &ft_isword)) // TODO parse quotes + vars
		return (parse_error_expect(p, "file name"));
	redir->data = ft_strndup(p->tmp->content, p->tmp->length);
	return (true);
}

t_bool			parse_redir(t_parser *p, t_cmd *cmd, int fd)
{
	t_redir			*redir;

	redir = ft_tabadd0(&(cmd->redirs));
	*redir = (t_redir){{fd, DEF_REDIR_FD}, NULL, REDIR_NOPE};
	if (BIS(p->buff, '>'))
	{
		if (BIS(p->buff, '>'))
			redir->redir_t = REDIR_APPEND;
		else
			redir->redir_t = REDIR_RIGHT;
	}
	else if (BIS(p->buff, '<'))
	{
		if (BIS(p->buff, '<'))
			return (parse_heredoc(p, redir));
		else
			redir->redir_t = REDIR_LEFT;
	}
	return (parse_redir_file(p, redir));
}
