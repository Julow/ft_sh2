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

int				main(int argc, char **argv)
{
	char			buff;

	ft_putstr("$> ");
	while (read(0, &buff, 1) > 0)
	{
		ft_putchar('\n');
		ft_putchar(buff);
		ft_putchar('\n');
	}
	return (0);
}
