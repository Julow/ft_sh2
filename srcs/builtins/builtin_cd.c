/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 18:43:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "msg.h"
#include <unistd.h>

int				builtin_cd(t_msh *sh, int argc, char **argv)
{
	char const		*dir;

	if (argc > 1)
	{
		dir = argv[1];
		if (ft_strequ(dir, "-") && (dir = get_env(sh, "OLDPWD", NULL)) == NULL)
			return (ft_fdprintf(2, E_CD_OLDPWD, argv[0]), 1);
	}
	else if ((dir = get_env(sh, "HOME", NULL)) == NULL)
		return (ft_fdprintf(2, E_CD_HOME, argv[0]), 1);
	if (chdir(dir) != 0)
		return (ft_fdprintf(2, E_CD_FAIL, argv[0]), 1);
	return (0);
}

int				builtinb_cd(t_msh *sh, int argc, char **argv)
{
	char const		*dir;

	if (argc > 1)
	{
		dir = argv[1];
		if (ft_strequ(dir, "-"))
			dir = get_env(sh, "OLDPWD", NULL);
	}
	else
		dir = get_env(sh, "HOME", NULL);
	if (dir == NULL || chdir(dir) != 0)
		return (1);
	return (0);
}
