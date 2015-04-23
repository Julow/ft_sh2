/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 20:12:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/23 18:13:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include "exec.h"

static void		msh_init(t_msh *sh)
{
	extern char		**environ;

	ft_arrayini(&(sh->env));
	while (*environ != NULL)
		ft_arrayadd(&(sh->env), ft_strdup(*(environ++)));
	sh->last_status = 0;
}

int				main(void)
{
	t_sub			line;
	t_msh			sh;

	msh_init(&sh);
	while (true)
	{
		ft_printf("lol> ");
		if (get_next_line(0, &line) <= 0)
			break ;
		exec_line(&sh, &line);
	}
	ft_printf("exit%{nl}");
	return (0);
}
