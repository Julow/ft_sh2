/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:19:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/04 18:28:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "exec.h"

typedef struct	s_parser
{
	t_msh			*msh;
	t_buff			*buff;
	t_string		*tmp;
}				t_parser;

/*
** Public
*/
t_cmd			*parse_cmd(t_msh *msh, t_sub *line);

/*
** Internal
*/
t_bool			parse_next_cmd(t_parser *p, t_cmd *cmd);

t_bool			parse_redir(t_parser *p, t_cmd *cmd, int fd);
t_bool			parse_heredoc(t_parser *p, t_redir *redir);

t_bool			parse_arg(t_parser *p, t_cmd *cmd, t_bool tmp);
t_bool			parse_arg_numeric(t_parser *p, t_cmd *cmd);

t_bool			parse_error(t_parser *p, char const *msg);
t_bool			parse_error_expect(t_parser *p, char const *expect);

t_bool			is_special(int c);
t_bool			is_redir(int c);
t_bool			is_next(int c);

#endif
