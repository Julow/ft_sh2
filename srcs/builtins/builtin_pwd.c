/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:56:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 18:09:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <unistd.h>
#include <stdlib.h>

void			builtin_pwd(t_sh *sh, const t_cmd *cmd)
{
	const char		*pwd = getcwd(NULL, 0);

	if (cmd->argv.length > 1)
		ft_putstr_fd("pwd: too many arguments", 2);
	else if (pwd == NULL)
		ft_putstr_fd("pwd: cannot find pwd.\n", 2);
	else
	{
		ft_putendl(pwd);
		free(pwd);
	}
	(void)sh;
}
