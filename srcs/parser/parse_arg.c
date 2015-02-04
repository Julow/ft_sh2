/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 12:13:24 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/04 20:15:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static t_bool	prompt_next(t_sh *sh, t_buff *line, t_string *arg, char *str)
{
	print_ps2(sh);
	if (get_next_line(0, line) <= 0)
		return (false);
	parse_string(sh, line, arg, str);
	return (true);
}

void			parse_string(t_sh *sh, t_buff *line, t_string *arg, char *str)
{
	t_bool			esc;

	esc = false;
	while (BI(*line))
	{
		esc = (*str != '\'' && ft_buffis(line, '\\')) ? true : false;
		if (!BI(*line) && !(esc = false) && !prompt_next(sh, line, arg, str))
			return ;
		if (!esc && BG(line) == '\'' && (*str == '\'' || *str == '\0'))
			*str = (*str == '\0') ? BG(line) : '\0';
		else if (!esc && BG(line) == '"' && (*str == '"' || *str == '\0'))
			*str = (*str == '\0') ? BG(line) : '\0';
		else if (!esc && *str == '\0' && is_special(BG(line)))
			break ;
		else if (!esc && BG(line) == '~' && *str == '\0' && arg->length == 0
			&& lex_home(sh, line, arg))
			continue ;
		else if (!esc && BG(line) == '$' && lex_var(sh, line, arg))
			continue ;
		else
			ft_stringaddc(arg, BG(line));
		line->i++;
	}
}

void			parse_arg(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	char			str;
	t_string		arg;

	ft_stringini(&arg);
	str = '\0';
	parse_string(sh, line, &arg, &str);
	while (str != '\0')
	{
		if (!prompt_next(sh, line, &arg, &str))
			break ;
		ft_stringaddc(&arg, '\n');
	}
	if (arg.length > 0)
		ft_arrayadd(&(cmd->argv), arg.content);
	else
		free(arg.content);
}
