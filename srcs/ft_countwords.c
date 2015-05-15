/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 00:02:08 by juloo             #+#    #+#             */
/*   Updated: 2015/05/16 00:13:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int				ft_countwords(char const *str)
{
	int				count;

	while (ft_iswhite(*str))
		str++;
	count = 0;
	while (*str != '\0')
	{
		count++;
		while (!ft_iswhite(*str) && *str != '\0')
			str++;
		while (ft_iswhite(*str))
			str++;
	}
	return (count);
}
