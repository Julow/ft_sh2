/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 00:41:01 by juloo             #+#    #+#             */
/*   Updated: 2015/05/10 00:45:42 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				ft_subnext(t_sub *sub, char c)
{
	sub->str += sub->length;
	sub->length = 0;
	while (*(sub->str) == c)
		sub->str++;
	while (sub->str[sub->length] != c && sub->str[sub->length] != '\0')
		sub->length++;
	return (sub->length);
}
