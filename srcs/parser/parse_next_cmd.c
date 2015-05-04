/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_next_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:38:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/04 18:50:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_cmd	*parse_next(t_parser *p, t_cmd *cmd)
{
	if (BIS(p->buff, '|'))
	{
		if (BIS(p->buff, '|'))
			cmd->next_t = NEXT_OR;
		else
			cmd->next_t = NEXT_PIPE;
	}
	else if (BIS(p->buff, '&'))
	{
		if (!BIS(p->buff, '&'))
			return (parse_error_expect(p, "'&'"), NULL);
		cmd->next_t = NEXT_AND;
	}
	else if (BIS(p->buff, ';'))
		cmd->next_t = NEXT_COLON;
	else
		return (NULL);
	cmd->next = cmd_new();
	return (cmd->next);
}

t_bool			parse_next_cmd(t_parser *p, t_cmd *cmd)
{
	while (!BEOF(p->buff))
	{
		ft_parsespace(p->buff);
		if (ft_isdigit(BG(p->buff)))
		{
			if (!parse_arg_numeric(p, cmd))
				return (false);
		}
		else if (is_redir(BG(p->buff)))
		{
			if (!parse_redir(p, cmd, DEF_REDIR_FD))
				return (false);
		}
		else if (is_next(BG(p->buff)))
		{
			if ((cmd = parse_next(p, cmd)) == NULL)
				return (false);
		}
		else if (!parse_arg(p, cmd, false))
			return (false);
		ft_parsespace(p->buff);
	}
	return (true);
}
