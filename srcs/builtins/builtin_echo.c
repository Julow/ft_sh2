/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:31:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 18:40:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int				builtin_echo(t_sh *sh, const t_cmd *cmd)
{
	int				i;
	t_bool			flag_n;

	i = 1;
	if (i < cmd->argv.length && ft_strequ(cmd->argv.data[i], "-n") && ++i)
		flag_n = true;
	else
		flag_n = false;
	while (i < cmd->argv.length)
	{
		ft_putstr(cmd->argv.data[i]);
		i++;
		if (i < cmd->argv.length)
			ft_putchar(' ');
	}
	if (!flag_n)
		ft_putchar('\n');
	(void)sh;
	return (0);
}
