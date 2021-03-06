/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/15 23:38:10 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <unistd.h>
#include <stdlib.h>

int				builtin_pwd(t_msh *sh, int argc, char **argv)
{
	char			*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		return (1);
	PS(path);
	NL;
	free(path);
	return (0);
	(void)sh;
	(void)argc;
	(void)argv;
}
