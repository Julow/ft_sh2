/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_newline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 20:09:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/04 20:21:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool			parse_string_newline(t_parser *p, char quote)
{
	t_sub			line;

	if (quote == '\0')
		ft_printf("\\> ");
	else
	{
		ft_printf("%c> ", quote);
		ft_stringaddc(p->tmp, '\n');
	}
	if (get_next_line(0, &line) <= 0 || line.length <= 0)
		return (parse_error_expect(p, "end of string"));
	*(p->buff) = SBUFF(line.str, line.length);
	return (parse_string(p, quote));
}
