/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:19:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/23 13:38:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minish.h"

typedef struct	s_parser
{
	t_msh			*msh;
	t_buff			*buff;
	t_string		*tmp;
	t_bp			bp;
}				t_parser;

/*
** Public
*/
t_cmd			*parse_cmd(t_msh *msh, t_sub *line);

/*
** Internal
*/
void			parse_next_cmd(t_parser *p, t_cmd *cmd);
void			parse_redir(t_parser *p, t_cmd *cmd);
void			parse_arg(t_parser *p, t_cmd *cmd, t_bool tmp)

/*
** Utils
*/
t_bool			is_separator(char c);
t_bool			is_redir(char c);
t_bool			is_next(char c);

#endif
