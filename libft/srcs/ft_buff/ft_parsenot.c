/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsenot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:04:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/13 15:32:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_parsenot(t_buff *buff, const char *parse)
{
	char			c;

	c = '\0';
	while (c != '\0')
	{
		if (ft_strchr(parse, (c = ft_buffget(buff))) != NULL && c != '\0')
			break ;
		buff->i++;
	}
}
