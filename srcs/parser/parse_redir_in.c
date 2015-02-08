/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 16:45:24 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/08 16:39:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static t_bool	parse_heredoc(t_sh *sh, t_buff *line, t_cmd *cmd, int fd)
{
	t_buff			tmp;
	t_redir			*redir;
	t_string		stop;

	redir = ft_tabadd0(&(cmd->redirs));
	ft_bzero(redir, sizeof(t_redir)); // to remove
	ft_stringini(&(redir->data));
	redir->fd[0] = (fd == -1) ? 0 : fd;
	redir->type = REDIR_HEREDOC;
	ft_parsespace(line);
	stop = ft_parsesubnf(line, &is_special);
	ft_parsespace(line);
	print_ps2(sh);
	while (get_next_line(0, &tmp) > 0)
	{
		if (ft_strequ(tmp.data, stop.content))
			break ;
		ft_stringaddl(&(redir->data), tmp.data, tmp.length);
		ft_stringaddc(&(redir->data), '\n');
		print_ps2(sh);
	}
	free(stop.content);
	return (true);
}

t_bool			parse_redir_in(t_sh *sh, t_buff *line, t_cmd *cmd, int fd)
{
	t_redir			*tmp;

	if (BIS(line, '<'))
		return (parse_heredoc(sh, line, cmd, fd));
	tmp = ft_tabadd0(&(cmd->redirs));
	ft_bzero(tmp, sizeof(t_redir)); // to remove
	tmp->fd[0] = (fd == -1) ? 0 : fd;
	tmp->type = REDIR_IN;
	ft_parsespace(line);
	tmp->data = ft_parsesubnf(line, &is_special);
	return (true);
}
