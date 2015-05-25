/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 16:59:09 by juloo             #+#    #+#             */
/*   Updated: 2015/05/25 17:20:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "msg.h"
#include <sys/stat.h>
#include <fcntl.h>

int				exec_open(char const *file, int flags)
{
	struct stat		stat;
	int				fd;

	fd = -1;
	if (lstat(file, &stat) < 0)
	{
		if (!(flags & O_CREAT))
			return (ft_fdprintf(2, E_FILE, file, M_NOEXISTS), -1);
		if ((fd = open(file, flags, MODE_O)) < 0)
			return (ft_fdprintf(2, E_FILE, file, M_CREATE), -1);
	}
	else if (S_ISDIR(stat.st_mode))
		return (ft_fdprintf(2, E_FILE, file, M_ISDIR), -1);
	else if ((fd = open(file, flags)) < 0)
		return (ft_fdprintf(2, E_FILE, file, M_RIGHT), -1);
	return (fd);
}
