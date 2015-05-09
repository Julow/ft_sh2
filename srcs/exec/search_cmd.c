/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 00:29:15 by juloo             #+#    #+#             */
/*   Updated: 2015/05/10 00:55:06 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char			*search_cmd(t_msh *sh, t_cmd *cmd)
{
	const char		*path = get_env(sh, "PATH", DEFAULT_PATH);
	t_string		tmp;
	t_sub			sub;

	if (ft_strchr(cmd->argv.data[0], '/') != NULL)
		return (cmd->argv.data[0]);
	ft_stringini(&tmp);
	sub = SUB((char*)path, 0);
	while (ft_subnext(&sub, ':') > 0)
	{
		ft_stringclr(&tmp);
		ft_stringaddl(&tmp, sub.str, sub.length);
		ft_stringaddc(&tmp, '/');
		ft_stringadd(&tmp, cmd->argv.data[0]);
		ft_printf("Testing '%s'\n", tmp.content);
	}
	return (NULL);
}
