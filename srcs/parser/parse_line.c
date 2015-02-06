/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:50:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/06 17:15:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static t_bool	parse_special(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	if (BIS(line, '|'))
		return (parse_next_pipe(sh, line, cmd));
	else if (BIS(line, ';'))
		return (parse_next_colon(sh, line, cmd));
	else if (BIS(line, '<'))
		return (parse_redir_in(sh, line, cmd));
	else if (BIS(line, '>'))
		return (parse_redir_out(sh, line, cmd));
	else if (BIS(line, '&'))
		return (parse_next_and(sh, line, cmd));
	return (ft_fdprintf(2, SH ": undefined operator '%c'\n", BG(line)), false);
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
			if (!parse_special(sh, line, cmd))
				return (cmd_kill(cmd), NULL);
		}
		else
			parse_arg(sh, line, cmd);
	}
	return (cmd);
}
