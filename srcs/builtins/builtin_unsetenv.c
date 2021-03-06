/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 18:33:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int				builtin_unsetenv(t_msh *sh, int argc, char **argv)
{
	return (builtinb_unsetenv(sh, argc, argv));
}

int				builtinb_unsetenv(t_msh *sh, int argc, char **argv)
{
	int				i;

	i = 0;
	while (++i < argc)
		unset_env(sh, argv[i]);
	return (0);
}
