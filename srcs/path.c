/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:52:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/26 23:35:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

char			*search_path(t_sh *sh, const char *cmd)
{
	char			*path;
	int				len;
	t_string		tmp;

	if ((path = get_env(sh, "PATH=")) == NULL)
		set_env(sh, "PATH=", (path = DEF_PATH));
	ft_stringini(&tmp);
	while (*path != '\0')
	{
		len = ft_strcskipe(path, ":");
		ft_stringclr(&tmp);
		ft_stringaddl(&tmp, path, len);
		ft_stringaddc(&tmp, '/');
		ft_stringadd(&tmp, cmd);
		if (ft_access(tmp.content) == ACCESS_OK)
			return (tmp.content);
		path += len + 1;
	}
	free(tmp.content);
	return (NULL);
}
