/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:55:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/26 21:46:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <signal.h>

static t_sh		*save_sh(t_sh *sh)
{
	static t_sh		*save;

	if (sh != NULL)
		save = sh;
	return (save);
}

static void		handle_signal(int sign)
{
	t_sh			*sh;

	(void)sign;
	sh = save_sh(NULL);
	ft_putchar('\n');
	update_sh(sh);
	sh->last_ret = 1;
}

static void		update_shlvl(t_sh *sh)
{
	const char		*shlvl = get_env(sh, "SHLVL=");
	char			*lvl;

	if (shlvl == NULL)
	{
		set_env(sh, "SHLVL=", "1");
		return ;
	}
	lvl = ft_itoa(ft_atoi(shlvl) + 1);
	if (lvl == NULL)
		return ;
	set_env(sh, "SHLVL=", lvl);
	free(lvl);
}

int				main(int argc, char **argv)
{
	t_sh			*sh;

	signal(SIGINT, &handle_signal);
	print_motd();
	sh = init_sh();
	save_sh(sh);
	update_shlvl(sh);
	start_sh(sh);
	ft_putstr("exit\n");
	(void)argc;
	(void)argv;
	return (0);
}
