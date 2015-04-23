/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 19:20:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/23 22:22:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void			parse_arg_numeric(t_parser *p, t_cmd *cmd)
{
	int				n;

	ft_parseint(p->buff, &n);
	if (is_redir(BG(p->buff)))
		return (parse_redir(p, cmd, 0));
	ft_stringclr(p->tmp);
	ft_stringaddi(p->tmp, n);
	parse_arg(p, cmd, true);
}
