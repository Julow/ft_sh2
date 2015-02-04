/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:32:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/04 21:53:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <fcntl.h>

void			parse_fd(t_sh *sh, t_buff *line, t_redir *redir, int oflags)
{
	ft_parsespace(line);
	if (ft_buffis(line, '&'))
	{
		redir->fd[1] = ft_parseint(line);
	}
	else
	{
		redir->data = ft_parsesubnf(line, &is_special);
		redir->fd[1] = open(redir->data.content, oflags, REDIR_O_MODE);
		// TODO: ft_access errors
	}
	(void)sh;
}
