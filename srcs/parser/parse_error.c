/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 22:07:08 by juloo             #+#    #+#             */
/*   Updated: 2015/04/24 00:27:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void			parse_error(t_parser *p, char const *msg)
{
	ft_fdprintf(2, "%s", msg);
	ft_throw(p->bp);
}

void			parse_error_expect(t_parser *p, char const *expect)
{
	char			c;

	ft_parsespace(p->buff);
	c = BG(p->buff);
	ft_fdprintf(2, SH ": syntax error: Expect %s before %.*r\n", expect, 1, &c);
	ft_throw(p->bp);
}
