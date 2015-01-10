/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:44:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 20:45:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

const char		*g_escaped[] = {
	"033", "\033",
	"33", "\033",
	"e", "\033",
	"n", "\n",
	"t", "\t",
	NULL
};

static t_bool	isps1(char c)
{
	if (c == 'u' || c == 'w' || c == 'v')
		return (TRUE);
	return (FALSE);
}

static int		print_unescape(const char *escaped)
{
	int				i;
	int				tmp;

	i = -2;
	while (g_escaped[(i += 2)] != NULL)
	{
		tmp = ft_strlen(g_escaped[i]);
		if (ft_strnequ(escaped, g_escaped[i], tmp))
		{
			ft_putstr(g_escaped[i + 1]);
			return (tmp);
		}
	}
	return (0);
}

void			print_ps1(t_sh *sh, const char *ps1)
{
	while (*ps1 != '\0')
	{
		if ((*ps1 == '%' || *ps1 == '\\') && isps1(ps1[1]))
		{
			ps1++;
			if (*ps1 == 'u')
				ft_putstr(get_env(sh, "USER="));
			else if (*ps1 == 'w')
				ft_putstr(get_env(sh, "PWD="));
			else if (*ps1 == 'v')
				ft_putstr("ft_minishell1");
		}
		else if (*ps1 == '\\')
			ps1 += print_unescape(ps1 + 1);
		else
			ft_putchar(*ps1);
		ps1++;
	}
}

void			print_motd(void)
{
	ft_putstr("+===========================================================+\n"
		"|__MMM____MMM______MMMMM___MM__MM___________________________|\n"
		"|__MMMM__MMMM_____MM_______MM__MM___________________________|\n"
		"|__MM__MM__MM______MMMM____MMMMMM___________________________|\n"
		"|__MM______MM_________MM___MM__MM___________________________|\n"
		"|__MM______M\033[31mMini\033[0;0m__MMMMM____MM__MM__"
			"\033[31m1\033[0;0m________________________|\n"
		"+===========================================================+\n");
}
