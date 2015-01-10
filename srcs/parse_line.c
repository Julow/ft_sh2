/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:50:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 14:50:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static int		parse_arg(t_sh *sh, const char *line, t_cmd *cmd)
{
	const char		*home = get_env(sh, "HOME=");
	t_bool			escaped;
	char			str;
	int				i;
	t_string		arg;

	i = 0;
	ft_stringini(&arg);
	if (home != NULL && line[i] == '~' && ++i)
		ft_stringadd(&arg, home);
	str = '\0';
	while (line[i] != '\0' && line[i] != ';')
	{
		escaped = (str != '\'' && line[i] == '\\' && ++i) ? TRUE : FALSE;
		if (!escaped && line[i] == '\'' && (str == '\'' || str == '\0'))
			str = (str == '\0') ? line[i] : '\0';
		else if (!escaped && line[i] == '"' && (str == '"' || str == '\0'))
			str = (str == '\0') ? line[i] : '\0';
		else if (!escaped && str == '\0' && line[i] == ' ')
			break ;
		else
			ft_stringaddc(&arg, line[i]);
		i++;
	}
	if (arg.length > 0)
		return (ft_arrayadd(&(cmd->argv), arg.content), i);
	return (free(arg.content), i);
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
			while (ft_isspace(*line))
				line++;
		}
		if (*line == ';')
			line++;
	}
}
