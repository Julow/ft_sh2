/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 23:34:02 by juloo             #+#    #+#             */
/*   Updated: 2015/05/14 17:07:13 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <sys/stat.h>

t_error			ft_access(char const *file, t_bool exec)
{
	struct stat		stat;

	if (lstat(file, &stat) < 0)
		return (E_NOEXISTS);
	if (S_ISDIR(stat.st_mode))
		return (E_ISDIR);
	if (exec && !(stat.st_mode & (1 << (9 - 3))))
		return (E_RIGHT);
	return (OK);
}
