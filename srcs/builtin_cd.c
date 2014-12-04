/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 18:13:50 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/04 18:13:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <unistd.h>

void			builtin_cd(t_sh *sh, t_cmd *cmd)
{
	if (cmd->argc >= 2)
		chdir(cmd->argv[1]);
	else if (cmd->argc == 1)
		chdir("~");
	if (cmd->argc > 2)
		ft_putstr_fd("cd: Warning: Too many arguments.", 2);
	(void)sh;
}
