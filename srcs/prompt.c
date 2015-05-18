/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 23:03:40 by juloo             #+#    #+#             */
/*   Updated: 2015/05/18 23:28:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

static void		print_escape(char const *e)
{
	if (*e == '\n')
		PC('\n');
	else if (*e == '$')
		PC('$');
	else
		PC('\\'), PC(*e);
}

static int		print_var(t_msh *sh, char const *ps1, t_string *var)
{
	int				i;

	ft_stringclr(var);
	i = 0;
	while (ft_isword(ps1[i]))
		i++;
	if (i <= 0)
		return (PC('$'), 0);
	ft_stringaddl(var, ps1, i);
	PS(get_env(sh, var->content, ""));
	return (i);
}

void			print_prompt(t_msh *sh)
{
	const char		*prompt = get_env(sh, "PS1", DEFAULT_PS1);
	t_string		var;
	int				i;

	ft_stringini(&var);
	i = -1;
	while (prompt[++i] != '\0')
	{
		if (prompt[i] == '\\')
			print_escape(prompt + (++i));
		else if (prompt[i] == '$')
			i += print_var(sh, prompt + i + 1, &var);
		else
			PC(prompt[i]);
	}
	free(var.content);
	FL;
}
