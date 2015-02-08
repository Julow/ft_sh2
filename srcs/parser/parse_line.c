/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:50:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/08 16:34:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static t_bool	parse_special(t_sh *sh, t_buff *line, t_cmd *cmd, int fd)
{
	if (BIS(line, '|'))
		return (parse_next_pipe(sh, line, cmd));
	else if (BIS(line, ';'))
		return (parse_next_colon(sh, line, cmd));
	else if (BIS(line, '<'))
		return (parse_redir_in(sh, line, cmd, fd));
	else if (BIS(line, '>'))
		return (parse_redir_out(sh, line, cmd, fd));
	else if (BIS(line, '&'))
		return (parse_next_and(sh, line, cmd));
	return (ft_fdprintf(2, SH ": undefined operator '%c'\n", BG(line)), false);
}

static t_bool	parse_int(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_string		arg;

	arg = ft_parsesubf(line, ft_isdigit);
	if (BG(line) == '>' || BG(line) == '<')
	{
		if (arg.length > 3)
			return (ft_fdprintf(2, SH ": %s: Bad fd\n", arg.content),
				free(arg.content), false);
		arg.length = ft_atoi(arg.content);
		free(arg.content);
		return (parse_special(sh, line, cmd, arg.length));
	}
	parse_string(sh, line, &arg, '\0');
	ft_arrayadd(&(cmd->argv), arg.content);
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
			if (!parse_special(sh, line, cmd, -1))
				return (cmd_kill(cmd), NULL);
		}
		else if (ft_isdigit(BG(line)))
		{
			if (!parse_int(sh, line, cmd))
				return (cmd_kill(cmd), NULL);
		}
		else
			parse_arg(sh, line, cmd);
	}
	return (cmd);
}
