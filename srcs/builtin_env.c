/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:21:05 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/29 15:21:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

static void		print_env(t_array *env)
{
	int				i;

	i = -1;
	while (++i < env->length)
		ft_putendl(env->data[i]);
}

static void		illegal_option(char o)
{
	ft_putstr_fd("env: illegal option -- ", 2);
	ft_putchar_fd(o, 2);
	ft_putstr_fd("\nusage: env [-i] [name=value ...] ", 2);
	ft_putstr_fd("[utility [argument ...]]\n", 2);
}

void			builtin_env(t_sh *sh, t_cmd *cmd)
{
	int				i;
	t_array			*env;

	env = ft_arraydup(sh->env);
	i = 0;
	if (cmd->argc > 1 && cmd->argv[1][0] == '-')
	{
		while (cmd->argv[1][++i] != '\0')
			if (cmd->argv[1][i] == 'i')
				ft_arrayclr(env)
			else
				return (illegal_option, void);
		i = 1;
	}
	while (++i < cmd->argc && ft_strchr(cmd->argv[i], '='))
		ft_arrayadd(env, cmd->argv[i]);
	print_env(env);
	ft_arraykil(env, NULL);
}
