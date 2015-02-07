/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:19:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/07 15:38:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <sys/stat.h>
#include <unistd.h>

t_bool			access_error(const char *file)
{
	int				error;

	error = ft_access(file);
	if (error == 0)
		return (false);
	else if (error == ACCESS_NO)
		ft_fdprintf(2, SH ": %s: No such file or directory\n", file);
	else if (error == ACCESS_DIR)
		ft_fdprintf(2, SH ": %s: Is a directory\n", file);
	else if (error == ACCESS_RIGHT)
		ft_fdprintf(2, SH ": %s: Permission denied\n", file);
	else
		ft_fdprintf(2, SH ": %s: Cannot access\n", file);
	return (true);
}

int				ft_access(const char *file)
{
	struct stat		stat;

	if (lstat(file, &stat) < 0)
		return (ACCESS_NO);
	if (S_ISDIR(stat.st_mode))
		return (ACCESS_DIR);
	if (!(stat.st_mode & (1 << (9 - 3))))
		return (ACCESS_RIGHT);
	return (ACCESS_OK);
}
