/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:48:41 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 14:49:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

char			*get_env(t_sh *sh, const char *key)
{
	const int		len = ft_strlen(key);
	int				i;

	i = -1;
	while (++i < sh->env.length)
	{
		if (ft_strnequ(AG(char*, &(sh->env), i), key, len))
			return (AG(char*, &(sh->env), i) + len);
	}
	return (NULL);
}

void			set_env_line(t_sh *sh, const char *line)
{
	const int		keylen = ft_strcskipe(line, "=");
	const int		valuelen = ft_strlen(line) - keylen;
	char			*tmp;
	int				i;

	i = -1;
	while (++i < sh->env.length)
		if (ft_strnequ(AG(char*, &(sh->env), i), line, keylen))
		{
			free(AG(char*, &(sh->env), i));
			ft_arrayrem(&(sh->env), i);
		}
	tmp = MAL(char, keylen + valuelen + 2);
	ft_memcpy(tmp, line, keylen);
	tmp[keylen] = '=';
	if (valuelen == 0)
		ft_memcpy(tmp + keylen + 1, line + keylen, valuelen + 1);
	else
		ft_memcpy(tmp + keylen, line + keylen, valuelen + 1);
	ft_arrayadd(&(sh->env), tmp);
}

void			set_env(t_sh *sh, const char *key, const char *value)
{
	const int		keylen = ft_strlen(key);
	const int		valuelen = ft_strlen(value);
	void			*tmp;
	int				i;

	i = -1;
	while (++i < sh->env.length)
		if (ft_strnequ(AG(char*, &(sh->env), i), key, keylen))
		{
			free(AG(char*, &(sh->env), i));
			ft_arrayrem(&(sh->env), i);
		}
	if (value == NULL)
		return ;
	tmp = MAL(char, keylen + valuelen + 1);
	ft_memcpy(tmp, key, keylen);
	ft_memcpy(tmp + keylen, value, valuelen + 1);
	ft_arrayadd(&(sh->env), tmp);
}
