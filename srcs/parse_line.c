/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:50:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/30 22:25:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static void		resolve_home(t_sh *sh, t_string *arg)
{
	const char		*home = get_env(sh, "HOME=");

	if (home != NULL && arg->content[0] == '~' &&
		(arg->content[1] == '/' || arg->content[1] == '\0'))
	{
		ft_stringrem(arg, 0, 1);
		ft_stringins(arg, home, 0);
	}
}

static void		parse_arg(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_bool			esc;
	char			str;
	t_string		arg;

	ft_stringini(&arg);
	str = '\0';
	while (BI(*line))
	{
		esc = (str != '\'' && BG(line) == '\\' && ++line->i) ? true : false;
		if (!esc && BG(line) == '\'' && (str == '\'' || str == '\0'))
			str = (str == '\0') ? BG(line) : '\0';
		else if (!esc && BG(line) == '"' && (str == '"' || str == '\0'))
			str = (str == '\0') ? BG(line) : '\0';
		else if (!esc && str == '\0' && is_special(BG(line)))
			break ;
		else
			ft_stringaddc(&arg, BG(line));
		line->i++;
	}
	resolve_home(sh, &arg);
	if (arg.length > 0)
		ft_arrayadd(&(cmd->argv), arg.content);
	else
		free(arg.content);
}

t_cmd			*parse_line(t_sh *sh, t_buff *line)
{
	t_cmd			*cmd;

	cmd = MAL1(t_cmd);
	cmd_init(cmd);
	while (BI(*line))
	{
		ft_parsespace(line);
		if (is_special(BG(line)))
		{
			parse_redir(sh, line, cmd);
			break ;
		}
		parse_arg(sh, line, cmd);
		ft_parsespace(line);
	}
	return (cmd);
}
