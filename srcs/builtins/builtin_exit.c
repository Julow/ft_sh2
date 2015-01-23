/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 19:39:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 18:33:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

int				builtin_exit(t_sh *sh, const t_cmd *cmd)
{
	char			error;

	error = 0;
	if (cmd->argv.length > 1)
		error = ft_atoi(cmd->argv.data[1]);
	ft_putstr("exit\n");
	exit(error);
	(void)sh;
	return (0);
}
