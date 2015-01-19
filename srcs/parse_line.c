/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:50:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/19 17:32:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>
#include <fcntl.h>

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
	while (line->i < line->length)
	{
		esc = (str != '\'' && BG(line) == '\\' && ++line->i) ? TRUE : FALSE;
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

static void		parse_redir(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_string		file;

	if (ft_buffis(line, '<'))
	{
		cmd->redir.type = (ft_buffis(line, '<')) ? REDIR_IN2 : REDIR_IN;
		// TODO
	}
	else if (ft_buffis(line, '>'))
	{
		cmd->redir.type = (ft_buffis(line, '>')) ? REDIR_OUT2 : REDIR_OUT;
/* TODO
		ft_parsespace(line);
		file = ft_parsesubnotf(line, &is_special);
		cmd->redir.fd = open(file.content,
			(cmd->redir.type == REDIR_OUT) ? );
*/
	}
	else
		return ;
}

static void		parse_cmd(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	cmd_init(cmd);
	while (line->i < line->length)
	{
		ft_parsespace(line);
		if (is_special(BG(line)))
		{
			if (ft_buffis(line, '|') && cmd->pipe = MAL1(t_cmd) != NULL)
				parse_cmd(sh, line, cmd->pipe);
			else if (BG(line) == '<' || BG(line) == '>')
				parse_redir(sh, line, cmd);
			return ;
		}
		parse_arg(sh, line, cmd);
		ft_parsespace(line);
	}
}

void			parse_line(t_sh *sh, t_tab *cmds, t_buff *line)
{
	t_cmd			*cmd;

	while (line->i < line->length)
	{
		cmd = (t_cmd*)ft_tabadd0(cmds);
		parse_cmd(sh, line, cmd);
		ft_parse(line, ";");
	}
}
