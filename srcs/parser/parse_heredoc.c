/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 22:22:57 by juloo             #+#    #+#             */
/*   Updated: 2015/05/04 18:35:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool			parse_heredoc(t_parser *p, t_redir *redir)
{
	char			*label;
	t_sub			line;

	ft_parsespace(p->buff);
	redir->redir_t = REDIR_HEREDOC;
	ft_stringclr(p->tmp);
	if (!ft_parsesubnf(p->buff, p->tmp, &is_special))
		return (parse_error_expect(p, "heredoc label"));
	label = ft_strndup(p->tmp->content, p->tmp->length);
	ft_stringclr(p->tmp);
	while (true)
	{
		ft_printf("%r> ", label);
		if (get_next_line(0, &line) <= 0)
		{
			NL;
			break ;
		}
		if (ft_strequ(label, line.str))
			break ;
		ft_stringaddl(p->tmp, line.str, line.length);
		ft_stringaddc(p->tmp, '\n');
	}
	redir->data = ft_strndup(p->tmp->content, p->tmp->length);
	return (true);
}
