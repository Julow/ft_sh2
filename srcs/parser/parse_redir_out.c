/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 21:37:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/06 16:21:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <fcntl.h>

t_bool			parse_redir_out(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_redir			*tmp;

	tmp = ft_tabadd0(&(cmd->redirs));
	ft_bzero(tmp, sizeof(t_redir)); // to remove
	tmp->type = (BIS(line, '>')) ? REDIR_APPEND : REDIR_OUT;
	ft_parsespace(line);
	tmp->data = ft_parsesubnf(line, &is_special);
	(void)sh;
	return (true);
}
