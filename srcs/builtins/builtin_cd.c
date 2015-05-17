/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/17 23:11:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "msg.h"
#include <stdlib.h>
#include <unistd.h>

static int		cd_err(char const *err, char **argv, t_bool print)
{
	if (print)
		ft_fdprintf(2, err, argv[0], argv[1]);
	return (1);
}

static int		cd(t_msh *sh, int argc, char **argv, t_bool print)
{
	char const		*dir;
	char			*pwd;

	if (argc > 1)
	{
		dir = argv[1];
		if (ft_strequ(dir, "-") && (dir = get_env(sh, "OLDPWD", NULL)) == NULL)
			return (cd_err(E_CD_OLDPWD, argv, print));
	}
	else if ((dir = get_env(sh, "HOME", NULL)) == NULL)
		return (cd_err(E_CD_HOME, argv, print));
	if ((pwd = getcwd(NULL, 0)) == NULL)
		return (cd_err(E_CD_ERR, argv, print));
	if (chdir(dir) != 0)
		return (free(pwd), cd_err(E_CD_FAIL, argv, print));
	set_env(sh, "OLDPWD", pwd);
	free(pwd);
	if ((pwd = getcwd(NULL, 0)) == NULL)
		return (cd_err(E_CD_ERR, argv, print));
	set_env(sh, "PWD", pwd);
	free(pwd);
	return (0);
}

int				builtin_cd(t_msh *sh, int argc, char **argv)
{
	return (cd(sh, argc, argv, true));
}

int				builtinb_cd(t_msh *sh, int argc, char **argv)
{
	return (cd(sh, argc, argv, false));
}
