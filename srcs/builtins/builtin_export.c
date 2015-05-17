/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/17 23:40:56 by juloo            ###   ########.fr       */
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

	i = 0;
	while (++i < argc)
		export_env(sh, argv[i]);
	return (0);
}
