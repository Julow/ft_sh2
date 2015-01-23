/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 17:36:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 18:03:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

inline t_bool	is_special(char c)
{
	if (ft_isspace(c) || c == ';' || c == '<' || c == '>' || c == '|')
		return (true);
	return (false);
}

inline t_bool	ft_buffis(t_buff *buff, char c)
{
	if (BG(buff) == c)
		return (buff->i++, true);
	return (false);
}

void			exit_err(const char *err)
{
	ft_putstr_fd("ft_minishell2: ", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

t_string		ft_parsesubnotf(t_buff *buff, t_bool (*f)(char c))
{
	char			c;
	t_string		sub;

	ft_stringini(&sub);
	c = ft_buffget(buff);
	while (c != '\0')
	{
		if (f((c = ft_buffget(buff))))
			break ;
		ft_stringaddc(&sub, c);
		buff->i++;
	}
	return (sub);
}
