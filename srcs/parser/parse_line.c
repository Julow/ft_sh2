/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:50:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/02 13:24:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

t_cmd			*parse_line(t_sh *sh, t_buff *line)
{
	t_cmd			*cmd;

	cmd = MAL1(t_cmd);
	cmd_init(cmd);
	while (BI(*line))
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
