/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 22:07:08 by juloo             #+#    #+#             */
/*   Updated: 2015/05/10 01:04:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "msg.h"

t_bool			parse_error(t_parser *p, char const *msg)
{
	ft_fdprintf(2, E_PARSE, msg);
	(void)p;
	return (false);
}

t_bool			parse_error_expect(t_parser *p, char const *expect)
{
	char			c;

	ft_parsespace(p->buff);
	c = BG(p->buff);
	ft_fdprintf(2, E_PARSE_EXP, expect, 1, &c);
	return (false);
}
