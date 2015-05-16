/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 18:50:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int				builtin_export(t_msh *sh, int argc, char **argv)
{
	return (builtinb_export(sh, argc, argv));
}

int				builtinb_export(t_msh *sh, int argc, char **argv)
{
	int				i;
	int				j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != '\0')
			if (argv[i][j] == '=')
				break ;
		if (argv[i][j] == '\0')
			continue ;
		argv[i][j] = '\0';
		set_env(sh, argv[i], argv[i] + j + 1);
	}
	return (0);
}
