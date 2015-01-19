/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_eval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:41:10 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/19 13:43:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

void			builtin_eval(t_sh *sh, const t_cmd *cmd)
{
	t_string		line;
	t_buff			buff;
	int				i;

	i = 1;
	ft_stringini(&line);
	while (i < cmd->argv.length)
	{
		ft_stringadd(&line, cmd->argv.data[i]);
		ft_stringaddc(&line, ' ');
		i++;
	}
	buff = BUFF(line.content, 0, line.length);
	exec_line(sh, &buff);
	free(line.content);
}
