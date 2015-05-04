/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:19:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/04 18:34:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd			*parse_cmd(t_msh *msh, t_sub *line)
{
	t_parser		parse;
	t_buff			buff;
	t_string		tmp_string;
	t_cmd			*cmd;

	buff = SBUFF(line->str, line->length);
	ft_stringini(&tmp_string);
	parse = (t_parser){msh, &buff, &tmp_string};
	cmd = cmd_new();
	if (!parse_next_cmd(&parse, cmd))
	{
		ft_fdprintf(2, "Error detected while parsing.\n");
		cmd_destroy(cmd);
		return (NULL);
	}
	ft_fdprintf(2, "parsing end\n");
	return (cmd);
}
