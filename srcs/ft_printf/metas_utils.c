/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metas_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 00:46:48 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 00:47:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

int				end_meta(const char *format)
{
	int				i;

	i = 0;
	while (format[i] != '\0' && format[i] != '}')
		i++;
	return (i);
}
