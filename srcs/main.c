/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:55:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 09:58:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <unistd.h>

static t_sh		*init_sh()
{
	extern char		**environ;
	t_sh			*sh;

	sh = MAL1(t_sh);
	sh->pwd = NULL;
	ft_arrayini(&(sh->env));
	while (*environ != NULL)
		ft_arrayadd(&(sh->env), *(environ++));
	return (sh);
}

static void		update_sh(t_sh *sh)
{
	if (sh->pwd != NULL)
		free(sh->pwd);
	sh->pwd = getcwd(NULL, 0);
	if (sh->pwd == NULL)
		ft_putstr("(null)");
	else
		ft_putstr(sh->pwd);
	ft_putstr(" $> ");
}

int				main(int argc, char **argv)
{
	char			*line;
	t_sh			*sh;

	sh = init_sh();
	update_sh(sh);
	while (get_next_line(0, &line) >= 0)
	{
		exec_line(sh, line);
		update_sh(sh);
	}
	ft_putstr("exit\n");
	(void)argc;
	(void)argv;
	return (0);
}
