/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:57:12 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/03 17:23:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int				builtin_help(t_sh *sh, const t_cmd *cmd)
{
	ft_putstr("\nBuiltins:\n");
	ft_putstr("\tcd [dir]\n\t\tChange working directory\n");
	ft_putstr("\tenv [-i] [name=value ...] [utility [argument ...]]\n"
		"\t\tPrint the env or exec a command with a modified env\n");
	ft_putstr("\texit [code]\n\t\tExit the shell\n");
	ft_putstr("\thelp\n\t\tShow this message\n");
	ft_putstr("\tsetenv [name[=value] ...]\n"
		"\t\tSet or change a env variable\n");
	ft_putstr("\tunsetenv [name ...]\n"
		"\t\tRemove a env variable\n");
	(void)sh;
	(void)cmd;
	return (0);
}
