/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_rand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/18 00:03:13 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "msg.h"
#include <time.h>
#include <stdlib.h>

static int		b_rand(char const *arg0, char const *min, char const *max)
{
	srand(clock());
	if (!ft_sisint(min))
		return (ft_fdprintf(2, E_ARG_INT, arg0, min), 1);
	if (!ft_sisint(max))
		return (ft_fdprintf(2, E_ARG_INT, arg0, max), 1);
	ft_printf("%d\n", ft_rand(ft_atoi(min), ft_atoi(max)));
	return (0);
}

int				builtin_rand(t_msh *sh, int argc, char **argv)
{
	if (argc == 3)
		return (b_rand(argv[0], argv[1], argv[2]));
	else if (argc == 2)
		return (b_rand(argv[0], "0", argv[1]));
	else if (argc == 1)
		return (b_rand(argv[0], "0", "1"));
	ft_fdprintf(2, E_ARG_TOO, argv[0]);
	return (1);
	(void)sh;
}
