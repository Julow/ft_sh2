/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:19:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/10 11:50:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

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
		cmd_destroy(cmd);
		cmd = NULL;
	}
	free(tmp_string.content);
	return (cmd);
}
