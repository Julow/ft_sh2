/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 17:36:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/25 00:36:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

inline t_bool	is_special(int c)
{
	if (c == ';' || c == '<' || c == '>' || c == '|' || c == '&')
		return (true);
	return (ft_isspace(c));
}

void			exit_err(const char *err)
{
	ft_putstr_fd(SH ": ", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
