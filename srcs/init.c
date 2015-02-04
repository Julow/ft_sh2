/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:46 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/04 20:24:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <unistd.h>

static void		update_shlvl(t_sh *sh)
{
	const char		*shlvl = get_env(sh, "SHLVL=");
	char			*lvl;

	if (shlvl == NULL)
	{
		set_env(sh, "SHLVL=", "1");
		return ;
	}
	lvl = ft_itoa(ft_atoi(shlvl) + 1);
	if (lvl == NULL)
		return ;
	set_env(sh, "SHLVL=", lvl);
	free(lvl);
}

static void		update_sh(t_sh *sh)
{
	char			*pwd;
	char			*tmp;

	if ((pwd = getcwd(NULL, 0)) != NULL)
	{
		tmp = get_env(sh, "PWD=");
		if (!ft_strequ(pwd, tmp))
		{
			set_env(sh, "OLDPWD=", tmp);
			set_env(sh, "PWD=", pwd);
		}
		free(pwd);
	}
	print_ps1(sh);
}

t_sh			*init_sh(int argc, char **argv)
{
	extern char		**environ;
	t_sh			*sh;

	sh = MAL1(t_sh);
	sh->argc = argc;
	sh->argv = argv;
	ft_arrayini(&(sh->env));
	while (*environ != NULL)
		ft_arrayadd(&(sh->env), ft_strdup(*(environ++)));
	update_shlvl(sh);
	return (sh);
}

void			start_sh(t_sh *sh)
{
	t_buff			line;

	update_sh(sh);
	while (get_next_line(0, &line) > 0)
	{
		exec_line(sh, &line);
		update_sh(sh);
	}
}
