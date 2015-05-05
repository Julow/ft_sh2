/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesubn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 15:22:41 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/05 15:23:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				ft_parsesubn(t_buff *buff, t_string *dst, const char *parse)
{
	char			c;
	int				len;

	len = dst->length;
	while (!BEOF(buff))
	{
		c = BG(buff);
		if (ft_strchr(parse, c) != NULL)
			break ;
		ft_stringaddc(dst, c);
		buff->i++;
	}
	return (dst->length - len);
}
