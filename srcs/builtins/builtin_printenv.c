/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_printenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/15 23:30:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int		print_env(t_msh *sh, char **argv)
{
	int				ret;
	char const		*tmp;

	ret = 0;
	while (*(++argv) != NULL)
	{
		tmp = get_env(sh, *argv, NULL);
		if (tmp == NULL)
			ret = 1;
		else
			PS(tmp), NL;
	}
	return (ret);
}

static void		print_env_all(t_msh *sh)
{
	int				i;

	i = -1;
	while (++i < sh->env.length)
		PS(AG(char*, &(sh->env), i)), PC('\n');
	FL;
}

int				builtin_printenv(t_msh *sh, int argc, char **argv)
{
	if (argc > 1)
		return (print_env(sh, argv));
	print_env_all(sh);
	return (0);
}
