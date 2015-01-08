/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 17:36:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 10:57:35 by jaguillo         ###   ########.fr       */
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

t_array			*ft_arraydup(const t_array *array)
{
	t_array			*dup;

	dup = ft_arraynew();
	ft_arrayext(dup, array->length);
	ft_memcpy(dup->data, array->data, array->length * sizeof(void*));
	dup->length = array->length;
	return (dup);
}
