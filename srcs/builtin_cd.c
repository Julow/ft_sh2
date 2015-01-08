/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 18:13:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 10:28:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <unistd.h>

void			builtin_cd(t_sh *sh, t_cmd *cmd)
{
	char			*dir;

	if (cmd->argv.length >= 2)
		dir = cmd->argv.data[1];
	else if ((dir = get_env(sh, "HOME=")) == NULL)
		ft_putstr_fd("cd: cannot find $HOME variable.\n", 2);
	if (dir != NULL && chdir(dir) != 0)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(dir, 2);
	}
}
