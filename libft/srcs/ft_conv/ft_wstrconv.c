/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:37:41 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/27 15:33:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_wstrconv(char *buff, wchar_t *wstr)
{
	int				i;
	int				len;

	len = 0;
	i = -1;
	while (wstr[++i] != 0)
		len += ft_widetoa(buff + len, wstr[i]);
	return (len);
}
