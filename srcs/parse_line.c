/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:50:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 10:22:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static char		*parse_arg(t_sh *sh, char *line, t_cmd *cmd)
{
	const char		*home = get_env(sh, "HOME=");
	t_bool			escaped;
	char			string;
	t_string		arg;

	ft_stringini(&arg);
	if (home != NULL && *line == '~' && line++)
		ft_stringadd(&arg, home);
	string = '\0';
	while (*line != '\0' && *line != ';')
	{
		escaped = (string != '\'' && *line == '\\' && line++) ? TRUE : FALSE;
		if (!escaped && *line == '\'' && (string == '\'' || string == '\0'))
			string = (string == '\0') ? *line : '\0';
		else if (!escaped && *line == '"' && (string == '"' || string == '\0'))
			string = (string == '\0') ? *line : '\0';
		else if (!escaped && string == '\0' && *line == ' ')
			break ;
		else
			ft_stringaddc(&arg, *line);
		line++;
	}
	if (arg.length > 0)
		ft_arrayadd(&(cmd->argv), arg.content);
	else
		free(arg.content);
	return (line);
}

static void		cmd_init(t_cmd *cmd)
{
	ft_arrayini(&(cmd->argv));
}

void			cmd_kill(t_cmd *cmd)
{
	ft_arrayclr(&(cmd->argv), &free);
}

void			parse_line(t_sh *sh, t_tab *cmds, char *line)
{
	t_cmd			*cmd;

	while (*line != '\0')
	{
		cmd = (t_cmd*)ft_tabadd0(cmds);
		cmd_init(cmd);
		while (*line != '\0' && *line != ';')
		{
			while (ft_isspace(*line))
				line++;
			line = parse_arg(sh, line, cmd);
		}
		while (ft_isspace(*line))
			line++;
	}
}
