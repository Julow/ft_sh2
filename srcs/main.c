/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 20:12:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/18 22:12:03 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include "exec.h"
#include "msg.h"
#include "ft_argv.h"
#include <stdlib.h>
#include <fcntl.h>

static void		msh_init(t_msh *sh)
{
	extern char		**environ;

	ft_arrayini(&(sh->env));
	while (*environ != NULL)
		ft_arrayadd(&(sh->env), ft_strdup(*(environ++)));
	sh->flags = 0;
	sh->last_status = 0;
}

static void		msh_start(t_msh *sh, int fd, t_bool interactif)
{
	t_sub			line;

	if (fd < 0)
		return ;
	while (true)
	{
		if (interactif)
			ft_printf("lol> ");
		if (get_next_line(fd, &line) <= 0)
			break ;
		exec_line(sh, line);
	}
	if (interactif)
		ft_printf("exit%{nl}");
}

static char		*msh_env_args(t_msh *sh, t_args *args)
{
	char			*tmp;
	char			*arg;

	arg = NULL;
	while ((tmp = ft_argvarg(args)) != NULL)
		if (arg == NULL && ft_strchr(tmp, '=') == NULL)
			arg = tmp;
		else
		{
			ft_printf("%s", tmp);
			export_env(sh, tmp);
		}
	return (arg);
}

int				main(int argc, char **argv)
{
	t_msh			sh;
	t_args			args;
	char			*tmp;

	msh_init(&sh);
	args = ARGS(argc, argv);
	while ((tmp = ft_argvopt(&args)) != NULL)
		if (ft_strequ(tmp, "v"))
			return (ft_printf(T_VERSION), 0);
		else if (ft_strequ(tmp, "i"))
			ft_arrayclr(&(sh.env), &free);
		else if (ft_strequ(tmp, "c"))
			if ((tmp = ft_argvarg(&args)) == NULL)
				return (ft_fdprintf(2, E_ARG_ARG, argv[0], "-c"), 2);
			else
				return (msh_env_args(&sh, &args),
					exec_line(&sh, SUB(tmp, ft_strlen(tmp))), 0);
		else
			return (ft_fdprintf(2, E_ARG_OPT, argv[0], *tmp), 2);
	tmp = msh_env_args(&sh, &args);
	if (tmp != NULL)
		msh_start(&sh, exec_open(tmp, READ_O), false);
	else
		msh_start(&sh, 0, true);
	return (0);
}
