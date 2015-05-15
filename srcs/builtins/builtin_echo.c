/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:00:12 by juloo             #+#    #+#             */
/*   Updated: 2015/05/15 23:07:51 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int				builtin_echo(t_msh *sh, int argc, char **argv)
{
	int				i;

	i = 0;
	while (++i < argc)
	{
		if (i > 1)
			PC(' ');
		PS(argv[i]);
	}
	NL;
	return (0);
	(void)sh;
}
