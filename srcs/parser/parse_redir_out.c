/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 21:37:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/08 16:26:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <fcntl.h>

t_bool			parse_redir_out(t_sh *sh, t_buff *line, t_cmd *cmd, int fd)
{
	t_redir			*tmp;

	tmp = ft_tabadd0(&(cmd->redirs));
	ft_bzero(tmp, sizeof(t_redir)); // to remove
	tmp->fd[0] = (fd == -1) ? 1 : fd;
	tmp->type = (BIS(line, '>')) ? REDIR_APPEND : REDIR_OUT;
	ft_parsespace(line);
	tmp->data = ft_parsesubnf(line, &is_special);
	(void)sh;
	return (true);
}
