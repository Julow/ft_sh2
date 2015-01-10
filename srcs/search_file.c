/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:52:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 14:53:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <dirent.h>
#include <stdlib.h>

char			*search_file(const char *path, int len, const char *name)
{
	DIR				*dir;
	struct dirent	*ent;
	t_string		file;

	ft_stringini(&file);
	ft_stringaddl(&file, path, len);
	dir = opendir(file.content);
	if (dir == NULL)
		return (NULL);
	while ((ent = readdir(dir)) != NULL)
		if (ft_strcase(ent->d_name, name))
		{
			ft_stringaddc(&file, '/');
			ft_stringadd(&file, ent->d_name);
			return (closedir(dir), file.content);
		}
	return (free(file.content), closedir(dir), NULL);
}
