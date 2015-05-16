/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 18:42:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int				builtin_builtin(t_msh *sh, int argc, char **argv)
{
	extern const t_blt	g_builtins[];
	int					i;

	i = -1;
	while (g_builtins[++i].name != NULL)
		PS(g_builtins[i].name), PC('\n');
	FL;
	return (0);
	(void)sh;
	(void)argc;
	(void)argv;
}
