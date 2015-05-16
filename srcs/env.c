/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 13:42:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/16 18:48:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static t_bool	key_equal(char const *line, char const *key)
{
	int				i;

	i = 0;
	while (line[i] == key[i] && line[i] != '\0')
		i++;
	if (line[i] == '=' && key[i] == '\0')
		return (true);
	return (false);
}

char const		*get_env(t_msh *sh, char const *key, char const *def)
{
	int				i;

	i = -1;
	while (++i < sh->env.length)
		if (key_equal(AG(char*, &(sh->env), i), key))
			return (AG(char*, &(sh->env), i) + ft_strlen(key) + 1);
	return (def);
}

void			set_env(t_msh *sh, char const *key, char const *value)
{
	const int		key_len = ft_strlen(key);
	const int		value_len = ft_strlen(value);
	int				i;
	char			*line;

	line = MAL(char, key_len + value_len + 2);
	ft_memcpy(line, key, key_len);
	line[key_len] = '=';
	ft_memcpy(line + key_len + 1, value, value_len + 1);
	i = -1;
	while (++i < sh->env.length)
		if (key_equal(AG(char*, &(sh->env), i), key))
		{
			free(sh->env.data[i]);
			sh->env.data[i] = line;
			return ;
		}
	ft_arrayadd(&(sh->env), line);
}

void			unset_env(t_msh *sh, char const *key)
{
	int				i;

	i = -1;
	while (++i < sh->env.length)
		if (key_equal(AG(char*, &(sh->env), i), key))
		{
			free(sh->env.data[i]);
			ft_arrayrem(&(sh->env), i);
			break ;
		}
}
