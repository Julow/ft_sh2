/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 12:13:24 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/02 13:26:13 by jaguillo         ###   ########.fr       */
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

static void		parse_string(t_buff *line, t_string *arg, char *str)
{
	t_bool			esc;

	while (BI(*line))
	{
		esc = (*str != '\'' && BG(line) == '\\' && ++line->i) ? true : false;
		if (!esc && BG(line) == '\'' && (*str == '\'' || *str == '\0'))
			*str = (*str == '\0') ? BG(line) : '\0';
		else if (!esc && BG(line) == '"' && (*str == '"' || *str == '\0'))
			*str = (*str == '\0') ? BG(line) : '\0';
		else if (!esc && *str == '\0' && is_special(BG(line)))
			break ;
		else
			ft_stringaddc(arg, BG(line));
		line->i++;
	}
}

void			parse_arg(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	char			str;
	t_string		arg;
	t_buff			buff;

	ft_stringini(&arg);
	str = '\0';
	parse_string(line, &arg, &str);
	while (str != '\0')
	{
		print_ps2(sh);
		if (get_next_line(0, &buff) <= 0)
			break ;
		parse_string(&buff, &arg, &str);
		ft_stringaddc(&arg, '\n');
	}
	resolve_home(sh, &arg);
	if (arg.length > 0)
		ft_arrayadd(&(cmd->argv), arg.content);
	else
		free(arg.content);
}
