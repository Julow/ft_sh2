/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 19:08:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "msg.h"
#include <stdlib.h>

int				builtin_exit(t_msh *sh, int argc, char **argv)
{
	int				status;

	if (argc > 1)
	{
		if (ft_sisint(argv[1]))
			status = ft_atoi(argv[1]);
		else
		{
			ft_fdprintf(2, E_ARG_INT, argv[0], argv[1]);
			status = 1;
		}
	}
	else
		status = 0;
	return (0);
	(void)sh;
}

int				builtinb_exit(t_msh *sh, int argc, char **argv)
{
	int				status;

	if (argc > 1)
	{
		if (ft_sisint(argv[1]))
			status = ft_atoi(argv[1]);
		else
			status = 1;
	}
	else
		status = 0;
	exit(status);
	return (0);
	(void)sh;
}
