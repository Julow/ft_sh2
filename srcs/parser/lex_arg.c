/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:04:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/04 21:35:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

t_bool			lex_home(t_sh *sh, t_buff *line, t_string *arg)
{
	char			*tmp;

	if (!ft_buffis(line, '~'))
		return (false);
	if ((BG(line) == '/' || !BI(*line)) && (tmp = get_env(sh, "HOME=")) != NULL)
	{
		ft_stringadd(arg, tmp);
		return (true);
	}
	ft_stringaddc(arg, '~');
	return (true);
}

static t_bool	lex_var_argv(t_sh *sh, t_buff *line, t_string *arg)
{
	int				i;

	i = ft_readbuff(line) - '0';
	if (sh->argc > i)
		ft_stringadd(arg, sh->argv[i]);
	return (true);
}

t_bool			lex_var(t_sh *sh, t_buff *line, t_string *arg)
{
	char			*tmp;
	t_string		var;

	if (!ft_buffis(line, '$'))
		return (false);
	if (ft_buffis(line, '?'))
	{
		ft_stringaddi(arg, sh->last_ret);
		return (true);
	}
	if (ft_isdigit(BG(line)))
		return (lex_var_argv(sh, line, arg));
	var = ft_parsesubf(line, &ft_isword);
	ft_stringaddc(&var, '=');
	if (var.length > 1 && (tmp = get_env(sh, var.content)) != NULL)
		ft_stringadd(arg, tmp);
	else if (var.length <= 1)
		ft_stringaddc(arg, '$');
	free(var.content);
	return (true);
}
