/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 18:13:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 23:35:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <unistd.h>

void			builtin_cd(t_sh *sh, const t_cmd *cmd)
{
	char			*dir;

	if (cmd->argv.length >= 2)
		dir = cmd->argv.data[1];
	else if ((dir = get_env(sh, "HOME=")) == NULL)
		ft_putstr_fd("cd: cannot find $HOME variable.\n", 2);
	if (dir != NULL && chdir(dir) != 0)
		ft_fdprintf(2, "cd: no such file or directory: %s\n", dir);
}
