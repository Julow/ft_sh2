/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 16:59:09 by juloo             #+#    #+#             */
/*   Updated: 2015/05/18 21:52:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "msg.h"
#include <fcntl.h>

int				exec_open(char const *str, int flags)
{
	t_error			accss;
	int				fd;

	accss = ft_access(str, false);
	if (accss == OK)
	{
		fd = open(str, flags, MODE_O);
		if (fd >= 0)
			return (fd);
	}
	if (accss == E_RIGHT)
		ft_fdprintf(2, E_FILE, str, M_RIGHT);
	else if (accss == E_ISDIR)
		ft_fdprintf(2, E_FILE, str, M_ISDIR);
	else if (accss == E_NOEXISTS)
		ft_fdprintf(2, E_FILE, str, M_NOEXISTS);
	else
		ft_fdprintf(2, E_FILE, str, M_ERR);
	return (-1);
}
