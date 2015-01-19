/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 20:44:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/14 11:37:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void			builtin_unsetenv(t_sh *sh, const t_cmd *cmd)
{
	int				i;

	i = 0;
	if (cmd->argv.length > 1)
		while (++i < cmd->argv.length)
		{
			set_env(sh, cmd->argv.data[i], NULL);
			ft_printf("unsetenv: %s\n", cmd->argv.data[i]);
		}
	else
		ft_fdprintf(2, "unsetenv: not enought argument\n"
			"usage: unsetenv [name ...]\n");
}
