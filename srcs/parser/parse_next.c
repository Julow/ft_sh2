/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:40:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/06 17:16:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

t_bool			parse_next_colon(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	cmd->next.type = NEXT_COLON;
	cmd->next.cmd = parse_line(sh, line);
	return ((cmd->next.cmd == NULL) ? false : true);
}

t_bool			parse_next_pipe(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	cmd->next.type = (BIS(line, '|')) ? NEXT_OR : NEXT_PIPE;
	cmd->next.cmd = parse_line(sh, line);
	return ((cmd->next.cmd == NULL) ? false : true);
}

t_bool			parse_next_and(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	if (BIS(line, '&'))
	{
		cmd->next.type = NEXT_AND;
		cmd->next.cmd = parse_line(sh, line);
		return ((cmd->next.cmd == NULL) ? false : true);
	}
	cmd->async = true;
	ft_parsespace(line);
	BIS(line, ';');
	ft_parsespace(line);
	if (is_special(BG(line)))
		return (ft_fdprintf(2, SH
			": syntax error near unexpected token `%c'\n", BG(line)), false);
	return (parse_next_colon(sh, line, cmd));
}
