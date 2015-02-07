/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:52:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/07 15:48:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static void		path_error(int error, const char *cmd)
{
	if (error == ACCESS_NO)
		ft_fdprintf(2, SH ": %s: Command not found\n", cmd);
	else if (error == ACCESS_DIR)
		ft_fdprintf(2, SH ": %s: Is a directory\n", cmd);
	else if (error == ACCESS_RIGHT)
		ft_fdprintf(2, SH ": %s: Permission denied\n", cmd);
}

static t_bool	lex_path(t_sh *sh, char **cmd)
{
	const char		*path = get_env_def(sh, "PATH=", DEF_PATH);
	int				len;
	int				access;
	int				first_error;
	t_string		tmp;

	ft_stringini(&tmp);
	first_error = ACCESS_NO;
	while (*path != '\0')
	{
		len = ft_strcskipe(path, ":");
		ft_stringclr(&tmp);
		ft_stringaddl(&tmp, path, len);
		ft_stringaddc(&tmp, '/');
		ft_stringadd(&tmp, *cmd);
		if ((access = ft_access(tmp.content)) == ACCESS_OK)
			return (free(*cmd), (*cmd = tmp.content), true);
		if (first_error == ACCESS_NO)
			first_error = access;
		path += len + 1;
	}
	return (free(tmp.content), path_error(first_error, *cmd), false);
}

t_bool			lex_cmd(t_sh *sh, t_cmd *cmd)
{
	if (cmd->argv.length <= 0)
		return (false);
	if (ft_strchr(cmd->argv.data[0], '/') != NULL)
		return (!access_error(cmd->argv.data[0]));
	if (is_builtin(cmd->argv.data[0]))
		return ((cmd->builtin = true), true);
	return (lex_path(sh, (char**)&(cmd->argv.data[0])));
}
