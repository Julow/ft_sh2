/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 17:36:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 13:42:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

void			exit_err(const char *err)
{
	ft_putstr_fd("ft_minishell1: ", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

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
