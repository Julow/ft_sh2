/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:50:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 11:37:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static int		parse_arg(t_sh *sh, const char *line, t_cmd *cmd)
{
	const char		*home = get_env(sh, "HOME=");
	t_bool			escaped;
	char			string;
	int				i;
	t_string		arg;

	i = 0;
	ft_stringini(&arg);
	if (home != NULL && line[i] == '~' && ++i)
		ft_stringadd(&arg, home);
	string = '\0';
	while (line[i] != '\0' && line[i] != ';')
	{
		escaped = (string != '\'' && line[i] == '\\' && ++i) ? TRUE : FALSE;
		if (!escaped && line[i] == '\'' && (string == '\'' || string == '\0'))
			string = (string == '\0') ? line[i] : '\0';
		else if (!escaped && line[i] == '"' && (string == '"' || string == '\0'))
			string = (string == '\0') ? line[i] : '\0';
		else if (!escaped && string == '\0' && line[i] == ' ')
			break ;
		else
			ft_stringaddc(&arg, line[i]);
		i++;
	}
	if (arg.length > 0)
		return (ft_arrayadd(&(cmd->argv), arg.content), i);
	return (free(arg.content), i);
}

static void		cmd_init(t_cmd *cmd)
{
	ft_arrayini(&(cmd->argv));
}

void			cmd_kill(t_cmd *cmd)
{
	ft_arrayclr(&(cmd->argv), &free);
}

void			parse_line(t_sh *sh, t_tab *cmds, const char *line)
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
			line += parse_arg(sh, line, cmd);
		}
		while (ft_isspace(*line))
			line++;
	}
}
