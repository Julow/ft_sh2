/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 19:15:10 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/05 15:30:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_bool	parse_string_char(t_parser *p, char *quote)
{
	if (BIS(p->buff, '\\'))
		return (parse_string_escape(p, *quote));
	else if (*quote != '\0' && BIS(p->buff, *quote))
		*quote = '\0';
	else if (*quote == '\0' && (BG(p->buff) == '\'' || BG(p->buff) == '"'))
		*quote = BR(p->buff);
	else if (*quote != '\'' && BIS(p->buff, '$'))
		return (parse_string_var(p));
	else
		ft_stringaddc(p->tmp, BR(p->buff));
	return (true);
}

t_bool			parse_string(t_parser *p, char quote)
{
	while (!BEOF(p->buff))
		if (quote == '\0' && is_special(BG(p->buff)))
			break ;
		else if (!parse_string_char(p, &quote))
			return (false);
	if (quote != '\0')
		return (parse_string_newline(p, quote));
	return (true);
}
