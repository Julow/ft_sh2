/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:55:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 17:49:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <unistd.h>

static t_sh		*init_sh(void)
{
	extern char		**environ;
	t_sh			*sh;

	sh = MAL1(t_sh);
	ft_arrayini(&(sh->env));
	while (*environ != NULL)
		ft_arrayadd(&(sh->env), ft_strdup(*(environ++)));
	return (sh);
}

static void		update_sh(t_sh *sh)
{
	const char		*ps1 = get_env(sh, "PS1=");
	const char		*pwd = getcwd(NULL, 0);
	char			*tmp;

	if (pwd != NULL)
	{
		tmp = get_env(sh, "PWD=");
		if (!ft_strequ(pwd, tmp))
		{
			set_env(sh, "OLDPWD=", tmp);
			set_env(sh, "PWD=", pwd);
		}
	}
	if (ps1 == NULL)
		print_ps1(sh, DEF_PS1);
	else
		print_ps1(sh, ps1);
}

int				main(int argc, char **argv)
{
	char			*line;
	t_sh			*sh;

	print_motd();
	sh = init_sh();
	update_sh(sh);
	while (get_next_line(0, &line) > 0)
	{
		exec_line(sh, line);
		update_sh(sh);
	}
	ft_putstr("exit\n");
	(void)argc;
	(void)argv;
	return (0);
}
