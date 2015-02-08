/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 12:13:24 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/08 16:30:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static t_bool	prompt_next(t_sh *sh, t_buff *line, t_string *arg, char str)
{
	print_ps2(sh);
	if (get_next_line(0, line) <= 0)
		return (false);
	parse_string(sh, line, arg, str);
	return (true);
}

void			parse_string(t_sh *sh, t_buff *line, t_string *arg, char str)
{
	t_bool			esc;

	esc = false;
	while (BI(line))
	{
		esc = (str != '\'' && BIS(line, '\\')) ? true : false;
		if (!esc && BG(line) == '\'' && (str == '\'' || str == '\0'))
			str = (str == '\0') ? BG(line) : '\0';
		else if (!esc && BG(line) == '"' && (str == '"' || str == '\0'))
			str = (str == '\0') ? BG(line) : '\0';
		else if (!esc && str == '\0' && is_special(BG(line)))
			break ;
		else if (!esc && BG(line) == '~' && str == '\0' && arg->length == 0
			&& lex_home(sh, line, arg))
			continue ;
		else if (!esc && BG(line) == '$' && lex_var(sh, line, arg))
			continue ;
		else
			ft_stringaddc(arg, BG(line));
		line->i++;
	}
	if (((esc && !BG(line)) || str != '\0') && prompt_next(sh, line, arg, str))
		ft_stringaddc(arg, '\n');
}

void			parse_arg(t_sh *sh, t_buff *line, t_cmd *cmd)
{
	t_string		arg;

	ft_stringini(&arg);
	parse_string(sh, line, &arg, '\0');
	if (arg.length > 0)
		ft_arrayadd(&(cmd->argv), arg.content);
	else
		free(arg.content);
}
