/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:44:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/03 17:14:07 by jaguillo         ###   ########.fr       */
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

static void		print_ps(t_sh *sh, const char *ps)
{
	while (*ps != '\0')
	{
		if ((*ps == '%' || *ps == '\\') && ft_strchr("uwv", ps[1]) != NULL)
		{
			ps++;
			if (*ps == 'u')
				ft_putstr(get_env(sh, "USER="));
			else if (*ps == 'w')
				ft_putstr(get_env(sh, "PWD="));
			else if (*ps == 'v')
				ft_putstr("ft_minishell2");
		}
		else if (*ps == '\\')
			ps += print_unescape(ps + 1);
		else
			ft_putchar(*ps);
		ps++;
	}
}

void			print_ps1(t_sh *sh)
{
	const char		*ps1 = get_env(sh, "PS1=");

	if (ps1 == NULL)
		print_ps(sh, DEF_PS1);
	else
		print_ps(sh, ps1);
}

void			print_ps2(t_sh *sh)
{
	const char		*ps2 = get_env(sh, "PS2=");

	if (ps2 == NULL)
		print_ps(sh, DEF_PS2);
	else
		print_ps(sh, ps2);
}

void			print_motd(void)
{
	ft_putstr("+===========================================================+\n"
		"|__MMM____MMM______MMMMM___MM__MM___________________________|\n"
		"|__MMMM__MMMM_____MM_______MM__MM___________________________|\n"
		"|__MM__MM__MM______MMMM____MMMMMM___________________________|\n"
		"|__MM______MM_________MM___MM__MM___________________________|\n"
		"|__MM______M\033[31mMini\033[0;0m__MMMMM____MM__MM__"
			"\033[31m2\033[0;0m________________________|\n"
		"+===========================================================+\n");
}
