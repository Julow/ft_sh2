/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/01 23:27:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <unistd.h>

t_sh			*init_sh(void)
{
	extern char		**environ;
	t_sh			*sh;

	sh = MAL1(t_sh);
	ft_arrayini(&(sh->env));
	while (*environ != NULL)
		ft_arrayadd(&(sh->env), ft_strdup(*(environ++)));
	return (sh);
}

void			update_sh(t_sh *sh)
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
