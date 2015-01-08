/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:44:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 11:06:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <unistd.h>

void			print_ps1(t_sh *sh, const char *ps1)
{
	while (*ps1 != '\0')
	{
		if (*ps1 == '%')
		{
			ps1++;
			if (*ps1 == 'u')
				ft_putstr(get_env(sh, "USER="));
			else if (*ps1 == 'w')
				ft_putstr(getcwd(NULL, 0));
			else if (*ps1 == 'v')
				ft_putstr("ft_minishell1");
			else
				ft_putlstr(ps1 - 1, 2);
		}
		else
			ft_putchar(*ps1);
		ps1++;
	}
}
