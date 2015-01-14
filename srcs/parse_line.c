/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:50:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/14 11:37:28 by jaguillo         ###   ########.fr       */
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
	t_bool			escaped;
	char			str;
	t_string		arg;

	ft_stringini(&arg);
	str = '\0';
	while (line->i < line->length && ft_buffget(line) != ';')
	{
		escaped = (str != '\'' && ft_buffget(line) == '\\' && ++line->i) ? TRUE : FALSE;
		if (!escaped && ft_buffget(line) == '\'' && (str == '\'' || str == '\0'))
			str = (str == '\0') ? ft_buffget(line) : '\0';
		else if (!escaped && ft_buffget(line) == '"' && (str == '"' || str == '\0'))
			str = (str == '\0') ? ft_buffget(line) : '\0';
		else if (!escaped && str == '\0' && ft_buffget(line) == ' ')
			break ;
		else
			ft_stringaddc(&arg, ft_buffget(line));
		line->i++;
	}
	resolve_home(sh, &arg);
	if (arg.length > 0)
		ft_arrayadd(&(cmd->argv), arg.content);
	else
		free(arg.content);
}

void			parse_line(t_sh *sh, t_tab *cmds, t_buff *line)
{
	t_cmd			*cmd;

	while (line->i < line->length)
	{
		cmd = (t_cmd*)ft_tabadd0(cmds);
		cmd_init(cmd);
		while (line->i < line->length && ft_buffget(line) != ';')
		{
			ft_parsespace(line);
			parse_arg(sh, line, cmd);
			ft_parsespace(line);
		}
		ft_parse(line, ";");
	}
}
