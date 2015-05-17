/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_eval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:06:49 by juloo             #+#    #+#             */
/*   Updated: 2015/05/17 23:42:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int				builtin_eval(t_msh *sh, int argc, char **argv)
{
	int				i;

	PS("eval");
	i = 0;
	while (++i < argc)
	{
		PC(' ');
		PS(argv[i]);
	}
	NL;
	return (0);
	(void)sh;
}
