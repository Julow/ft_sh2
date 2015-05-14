/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 00:29:15 by juloo             #+#    #+#             */
/*   Updated: 2015/05/14 17:13:45 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "msg.h"
#include <stdlib.h>

static void		search_error(char const *file, t_error e)
{
	if (e == E_RIGHT)
		ft_fdprintf(2, W_PATH_E, file, M_RIGHT);
	else if (e == E_ISDIR)
		ft_fdprintf(2, W_PATH_E, file, M_ISDIR);
	else if (e != E_NOEXISTS)
		ft_fdprintf(2, W_PATH_E, file, M_ERR);
}

char			*search_cmd(t_msh *sh, t_cmd *cmd)
{
	const char		*path = get_env(sh, "PATH", DEFAULT_PATH);
	t_string		tmp;
	t_sub			sub;
	t_error			accss;

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
		if ((accss = ft_access(tmp.content, true)) == OK)
			return (tmp.content);
		search_error(tmp.content, accss);
	}
	free(tmp.content);
	ft_fdprintf(2, E_PATH_NO, cmd->argv.data[0]);
	return (NULL);
}
