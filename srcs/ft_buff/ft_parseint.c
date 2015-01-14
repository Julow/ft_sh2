/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 21:07:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_parseint(t_buff *buff)
{
	int				nb;
	t_bool			negatif;

	negatif = FALSE;
	nb = 0;
	if ((ft_buffget(buff) == '-' && (negatif = TRUE))
		|| ft_buffget(buff) == '+')
		buff->i++;
	while (ft_isdigit(ft_buffget(buff)))
		nb = nb * 10 + (ft_readbuff(buff) - '0');
	return (negatif ? -nb : nb);
}
