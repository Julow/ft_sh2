/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:28:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/03 17:35:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <signal.h>

static t_sh		*save_sh(t_sh *sh)
{
	static t_sh		*save;

	if (sh != NULL)
		save = sh;
	return (save);
}

static void		signals_handler(int sign)
{
	t_sh			*sh;

	(void)sign;
	sh = save_sh(NULL);
	ft_putchar('\n');
	print_ps1(sh);
	sh->last_ret = 1;
}

void			handle_signals(t_sh *sh)
{
	save_sh(sh);
	signal(SIGINT, &signals_handler);
}
