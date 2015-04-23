/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 13:07:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/23 13:38:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void			parse_arg(t_parser *p, t_cmd *cmd, t_bool tmp)
{
	if (!tmp)
		ft_stringclr(p->tmp);
	ft_parsesubnf(p->buff, p->tmp, &ft_isspace);
	ft_arrayadd(&(cmd->argv), ft_strndup(p->tmp->data, p->tmp->length));
}
