/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:50:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/05 17:32:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static t_bool	parse_redir(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	while (BI(line))
	{
		if (BIS(line, '<'))
		{
			if (!parse_redir_in(sh, line, cmd))
				return (false);
		}
		else if (BG(line) == '>')
		{
			if (!parse_redir_out(sh, line, cmd))
				return (false);
		}
		else if (BG(line) == '|')
			return (parse_redir_pipe(sh, line, cmd));
		else if (BG(line) == ';')
			return (parse_redir_colon(sh, line, cmd));
		else
			return (ft_printf(SH ": undefined operator '%c'\n",
				BG(line)), false);
		ft_parsespace(line);
	}
	return (true);
}

t_cmd			*parse_line(t_sh *sh, t_buff *line)
{
	t_cmd			*cmd;

	cmd = MAL1(t_cmd);
	cmd_init(cmd);
	while (BI(line))
	{
		ft_parsespace(line);
		if (is_special(BG(line)))
		{
			parse_redir(sh, line, cmd);
			break ;
		}
		parse_arg(sh, line, cmd);
		ft_parsespace(line);
	}
	return (cmd);
}
