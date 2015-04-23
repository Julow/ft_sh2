/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 17:41:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/23 18:07:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void			exec_line(t_msh *sh, t_sub *line)
{
	t_cmd			*cmd;

	if ((cmd = parse_cmd(sh, line)) == NULL)
		return ;
	exec_cmd(sh, cmd);
	cmd_destroy(cmd);
}
