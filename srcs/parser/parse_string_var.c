/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 20:08:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/10 00:49:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

t_bool			parse_string_var(t_parser *p)
{
	t_string		var_name;
	char const		*tmp;

	ft_stringini(&var_name);
	ft_parsesubf(p->buff, &var_name, &ft_isword);
	if (var_name.length <= 0)
		ft_stringaddc(p->tmp, '$');
	else
	{
		tmp = get_env(p->msh, var_name.content, NULL);
		if (tmp != NULL)
			ft_stringadd(p->tmp, tmp);
	}
	free(var_name.content);
	return (true);
}
