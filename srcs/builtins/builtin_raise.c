/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_raise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 00:08:09 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 00:10:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <signal.h>

int				builtin_raise(t_msh *sh, int argc, char **argv)
{
	if (argc > 1)
	{
		if (!ft_sisint(argv[1]))
		{
			ft_fdprintf(2, "%s: Error: '%s' is not a valid int\n",
				argv[0], argv[1]);
			return (1);
		}
		raise(ft_atoi(argv[1]));
	}
	return (0);
	(void)sh;
}
