/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 18:43:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "msg.h"
#include <unistd.h>

int				builtin_sleep(t_msh *sh, int argc, char **argv)
{
	if (argc <= 1)
		return (ft_fdprintf(2, E_ARG_NOT, argv[0]), 1);
	if (!ft_sisint(argv[1]))
	{
		ft_fdprintf(2, E_ARG_INT, argv[0], argv[1]);
		return (1);
	}
	sleep((t_uint)ft_atoi(argv[1]));
	return (0);
	(void)sh;
}
