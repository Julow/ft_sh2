/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/17 23:41:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "msg.h"
#include <stdlib.h>

static int		parse_args(t_msh *sh, int argc, char **argv)
{
	int				i;
	int				j;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-')
			break ;
		j = 0;
		while (argv[i][++j] != '\0')
			if (argv[i][j] == 'i')
				ft_arrayclr(&(sh->env), &free);
			else
				return (ft_fdprintf(2, E_ARG_OPT, argv[0], argv[i][j]), -1);
	}
	i--;
	while (++i < argc)
		if (ft_strchr(argv[i], '=') != NULL)
			export_env(sh, argv[i]);
		else
			break ;
	return (i);
}

int				builtin_env(t_msh *sh, int argc, char **argv)
{
	int				i;

	if ((i = parse_args(sh, argc, argv)) < 0)
		return (1);
	if (i >= argc)
		return (builtin_printenv(sh, 1, argv));
	argv[i - 1] = argv[0];
	return (builtin_eval(sh, argc - i + 1, argv + i - 1));
}
