/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 19:18:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/22 19:39:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool			is_separator(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == ';' || c == '&')
		return (true);
	return (false);
}

t_bool			is_redir(char c)
{
	if (c == '<' || c == '>')
		return (true);
	return (false);
}

t_bool			is_next(char c)
{
	if (c == ';' || c == '&' || c == '|')
		return (true);
	return (false);
}
