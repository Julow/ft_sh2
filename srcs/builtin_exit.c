/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 19:39:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 09:43:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

void			builtin_exit(t_sh *sh, t_cmd *cmd)
{
	char			error;

	error = 0;
	if (cmd->argv.length > 1)
		error = ft_atoi(cmd->argv.data[1]);
	ft_putstr("exit\n");
	exit(error);
	(void)sh;
}
