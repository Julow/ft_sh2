/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 19:35:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 18:31:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int				builtin_setenv(t_sh *sh, const t_cmd *cmd)
{
	int				i;

	i = 0;
	if (cmd->argv.length <= 1)
		return (ft_fdprintf(2, "setenv: not enought argument\n"
			"usage: setenv [name[=value] ...]\n"), 1);
	while (++i < cmd->argv.length)
	{
		set_env_line(sh, cmd->argv.data[i]);
		ft_printf("setenv: %s\n", cmd->argv.data[i]);
	}
	return (0);
}
