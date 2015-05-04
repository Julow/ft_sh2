/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 19:20:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/04 18:34:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool			parse_arg_numeric(t_parser *p, t_cmd *cmd)
{
	int				n;

	ft_parseint(p->buff, &n);
	if (is_redir(BG(p->buff)))
		return (parse_redir(p, cmd, 0));
	ft_stringclr(p->tmp);
	ft_stringaddi(p->tmp, n);
	return (parse_arg(p, cmd, true));
}
