/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:21:05 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 13:41:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

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

static void		env_exec(t_sh sh, const t_cmd *cmd, int i)
{
	t_string		line;

	ft_stringini(&line);
	while (i < cmd->argv.length)
	{
		ft_stringadd(&line, cmd->argv.data[i]);
		ft_stringaddc(&line, ' ');
		i++;
	}
	exec_line(&sh, line.content);
	free(line.content);
}

void			builtin_env(t_sh *sh, const t_cmd *cmd)
{
	int				i;
	t_array			*env;

	env = ft_arraydup(&(sh->env));
	i = 0;
	if (cmd->argv.length > 1 && AG(char*, &(cmd->argv), 1)[0] == '-')
	{
		while (AG(char*, &(cmd->argv), 1)[++i] != '\0')
			if (AG(char*, &(cmd->argv), 1)[i] == 'i')
				ft_arrayclr(env, NULL);
			else
				return (illegal_option(AG(char*, &(cmd->argv), 1)[i]));
		i = 1;
	}
	while (++i < cmd->argv.length && ft_strchr(AG(char*, &(cmd->argv), i), '='))
		ft_arrayadd(env, AG(char*, &(cmd->argv), i));
	if (i < cmd->argv.length)
		env_exec((t_sh){*env}, cmd, i);
	else
		print_env(env);
	ft_arraykil(env, NULL);
}
