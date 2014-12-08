/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:55:35 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/03 13:55:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static void		update_sh(t_sh *sh)
{
	if (sh->pwd != NULL)
		free(sh->pwd);
	sh->pwd = getcwd(NULL, 0);
	if (sh->pwd == NULL)
		exit_err("Cannot get the current pwd.");
	ft_putstr(sh->pwd);
	ft_putstr(" $> ");
}

int				main(int argc, char **argv)
{
	char			*line;
	t_sh			*sh;

	sh = MAL1(t_sh);
	sh->pwd = NULL;
	update_sh(sh);
	while (get_next_line(0, &line) >= 0)
	{
		parse_line(sh, line);
		free(line);
		update_sh(sh);
	}
	(void)argc;
	(void)argv;
	return (0);
}
