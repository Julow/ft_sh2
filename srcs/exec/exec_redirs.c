/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 00:22:09 by juloo             #+#    #+#             */
/*   Updated: 2015/05/10 00:22:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

#define IT_TAB(t,v,i,b)		t*v;for(int i=0;i<b.length&&(v=(t*)(b.data+i));++i)

t_bool			exec_redirs(t_msh *sh, t_cmd *cmd)
{
	IT_TAB(t_redir, var, index, cmd->redirs)
		ft_printf("Redir #%d = %s\n", index, var->data);
	(void)sh;
	return (true);
}
