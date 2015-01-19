/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_printenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:29:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/19 10:35:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void			builtin_printenv(t_sh *sh, const t_cmd *cmd)
{
	int				i;

	i = -1;
	while (++i < sh->env.length)
		ft_putendl(sh->env.data[i]);
	(void)cmd;
}