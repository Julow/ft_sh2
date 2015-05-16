/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 18:42:06 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "msg.h"

int				builtin_setenv(t_msh *sh, int argc, char **argv)
{
	if (argc > 2)
		set_env(sh, argv[1], argv[2]);
	else if (argc > 1)
		unset_env(sh, argv[1]);
	else
		return (ft_fdprintf(2, E_ARG_NOT, argv[0]), 1);
	return (0);
}

int				builtinb_setenv(t_msh *sh, int argc, char **argv)
{
	if (argc > 2)
		set_env(sh, argv[1], argv[2]);
	else if (argc > 1)
		unset_env(sh, argv[1]);
	else
		return (1);
	return (0);
}
