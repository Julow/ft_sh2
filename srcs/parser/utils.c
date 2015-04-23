/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 19:18:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/23 22:41:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool			is_special(int c)
{
	if (c == '|' || c == '>' || c == '<' || c == ';' || c == '&')
		return (true);
	return (ft_iswhite(c));
}

t_bool			is_redir(int c)
{
	if (c == '<' || c == '>')
		return (true);
	return (false);
}

t_bool			is_next(int c)
{
	if (c == ';' || c == '&' || c == '|')
		return (true);
	return (false);
}
