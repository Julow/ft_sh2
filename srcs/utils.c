/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 17:36:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/14 11:37:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"
#include <stdlib.h>

void			exit_err(const char *err)
{
	ft_putstr_fd("ft_minishell1: ", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
