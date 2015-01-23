/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 20:44:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 18:31:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int				builtin_unsetenv(t_sh *sh, const t_cmd *cmd)
{
	int				i;

	i = 0;
	if (cmd->argv.length <= 1)
		return (ft_fdprintf(2, "unsetenv: not enought argument\n"
			"usage: unsetenv [name ...]\n"), 1);
	while (++i < cmd->argv.length)
	{
		set_env(sh, cmd->argv.data[i], NULL);
		ft_printf("unsetenv: %s\n", cmd->argv.data[i]);
	}
	return (0);
}
