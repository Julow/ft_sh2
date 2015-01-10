/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:55:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 14:07:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int				main(int argc, char **argv)
{
	t_sh			*sh;

	print_motd();
	sh = init_sh();
	start_sh(sh);
	ft_putstr("exit\n");
	kill_sh(sh);
	(void)argc;
	(void)argv;
	return (0);
}
