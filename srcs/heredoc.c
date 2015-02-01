/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 17:55:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/01 23:34:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

void			parse_heredoc(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_buff			tmp;
	t_redir			*redir;
	t_string		stop;

	redir = ft_tabadd0(&(cmd->redirs));
	ft_bzero(redir, sizeof(t_redir)); // to remove
	ft_stringini(&(redir->data));
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
}
