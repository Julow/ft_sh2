/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 13:07:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/04 20:12:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool			parse_arg(t_parser *p, t_cmd *cmd, t_bool tmp)
{
	if (!tmp)
		ft_stringclr(p->tmp);
	parse_string(p, '\0');
	ft_arrayadd(&(cmd->argv), ft_strndup(p->tmp->content, p->tmp->length));
	return (true);
}
