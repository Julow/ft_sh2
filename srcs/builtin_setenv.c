/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 19:35:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 20:33:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void			builtin_setenv(t_sh *sh, const t_cmd *cmd)
{
	int				i;

	i = 0;
	if (cmd->argv.length > 1)
		while (++i < cmd->argv.length)
		{
			set_env_line(sh, cmd->argv.data[i]);
			ft_printf("setenv: %s\n", cmd->argv.data[i]);
		}
	else
		ft_fdprintf(2, "setenv: not enought argument\n"
			"usage: setenv [name[=value] ...]\n");
}
