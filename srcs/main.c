/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:55:35 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/03 13:55:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include "get_next_line.h"

int				main(int argc, char **argv)
{
	char			*line;

	ft_putstr("$> ");
	while (get_next_line(0, &line) >= 0)
	{
		ft_putstr(line);
		free(line);
		ft_putstr("\n$> ");
	}
	(void)argc;
	(void)argv;
	return (0);
}
