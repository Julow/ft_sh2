/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:19:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/23 18:10:53 by jaguillo         ###   ########.fr       */
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
	parse = (t_parser){msh, &buff, &tmp_string, {0}};
	cmd = cmd_new();
	TRY(parse.bp)
		parse_next_cmd(&parse, cmd);
	CATCH
	{
		cmd_destroy(cmd);
		return (NULL);
	}
	return (cmd);
}
