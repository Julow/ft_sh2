/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_eval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/17 23:46:01 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "builtin.h"
#include <stdlib.h>

int				builtin_eval(t_msh *sh, int argc, char **argv)
{
	t_string		eval;
	t_sub			tmp;
	int				i;

	ft_stringini(&eval);
	i = 0;
	while (++i < argc)
	{
		if (i > 1)
			ft_stringaddc(&eval, ' ');
		ft_stringadd(&eval, argv[i]);
	}
	tmp = SUB(eval.content, eval.length);
	exec_line(sh, &tmp);
	free(eval.content);
	return (0);
}
