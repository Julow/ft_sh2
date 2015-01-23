/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:56:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 18:32:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <unistd.h>
#include <stdlib.h>

int				builtin_pwd(t_sh *sh, const t_cmd *cmd)
{
	const char		*pwd = getcwd(NULL, 0);

	if (cmd->argv.length > 1)
		return (ft_putstr_fd("pwd: too many arguments", 2), 1);
	else if (pwd == NULL)
		return (ft_putstr_fd("pwd: cannot find pwd.\n", 2), 1);
	ft_putendl(pwd);
	free(pwd);
	(void)sh;
	return (0);
}
