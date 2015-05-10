/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_escape.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 20:08:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/10 20:51:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool			parse_string_escape(t_parser *p, char quote)
{
	if (BEOF(p->buff))
		return (parse_string_newline(p, quote));
	if (BG(p->buff) != '$' && BG(p->buff) != quote
		&& !is_special(BG(p->buff)))
		ft_stringaddc(p->tmp, '\\');
	ft_stringaddc(p->tmp, BR(p->buff));
	return (true);
}
