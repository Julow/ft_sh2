/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_next_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:38:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/22 19:44:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		parse_next(t_parser *p, t_cmd *cmd)
{
	if (BIS(p->buff, '|'))
	{
		if (BIS(p->buff, '|'))
			cmd->next_t = NEXT_OR;
		else
			cmd->next_t = NEXT_PIPE;
	}
	else if (BIS(p->buff, '&'))
		cmd->next_t = NEXT_AND;
	else
		cmd->next_t = NEXT_COLON;
	cmd->next = cmd_new();
	parse_next_cmd(p, cmd->next);
}

void			parse_next_cmd(t_parser *p, t_cmd *cmd)
{
	while (!BEOF(p->buff))
	{
		ft_parsespace(p->buff);
		if (ft_isdigit(BG(p->buff)))
			parse_arg_numeric(p, cmd);
		else if (is_redir(BG(p->buff)))
			parse_redir(p, cmd);
		else if (is_next(BG(p->buff)))
			return (parse_next(p, cmd));
	}
}
